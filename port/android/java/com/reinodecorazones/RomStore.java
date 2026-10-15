package com.reinodecorazones;

import android.content.Context;
import android.content.pm.PackageInfo;
import android.net.Uri;
import android.os.Build;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

/**
 * The player's copies of the game and the engine's map files.
 *
 * A copy is accepted only if its SHA-1 matches one of the supported versions.
 * It is kept in the app's private storage (rom/usa.gba, rom/eur.gba) and
 * never leaves the phone. The maps (motor/usa.map, motor/eur.map) say where
 * each piece of the game's data sits in the ROM; they come with the app.
 */
final class RomStore {
    static final String SHA_USA = "10729bd884f8fdca7a310b6d606c52e46657aa48";
    static final String SHA_EUR = "8db73586cdb11b3795907edebf43228dbcd3e6b2";
    static final String SHA_JPN = "59ec0a0a4ccd1e6acb3bbd7bfb21d63988958cfa";

    enum Result { OK_USA, OK_EUR, ALREADY, BAD, BAD_JP, NOT_GBA, ZIP, ZIP_EMPTY, READ_ERR, COPY_ERR }

    private final Context ctx;

    RomStore(Context ctx) {
        this.ctx = ctx;
    }

    File romDir() {
        File d = new File(ctx.getFilesDir(), "rom");
        d.mkdirs();
        return d;
    }

    File rom(String region) {
        return new File(romDir(), region + ".gba");
    }

    boolean has(String region) {
        return rom(region).isFile();
    }

    /** Where saves, settings, screenshots and logs go: a folder the player can
     *  reach from a PC (Android/data/com.reinodecorazones/files), else private. */
    File dataRoot() {
        File d = ctx.getExternalFilesDir(null);
        if (d == null || !(d.isDirectory() || d.mkdirs()))
            d = ctx.getFilesDir();
        return d;
    }

    /** The game's native code in use: 64-bit phones run the 32-bit core
     *  (its own map), the others the 32-bit ARM engine. */
    static String abi() {
        String arch = System.getProperty("os.arch", "");
        return arch.contains("64") ? "arm64-v8a" : "armeabi-v7a";
    }

    /** Copies motor/<abi>/<region>.map out of the APK when missing or after an update. */
    File map(String region) throws IOException {
        File dir = new File(ctx.getFilesDir(), "motor");
        dir.mkdirs();
        String abi = abi();
        File out = new File(dir, abi + "-" + region + ".map");
        long installed = 0;
        try {
            PackageInfo pi = ctx.getPackageManager().getPackageInfo(ctx.getPackageName(), 0);
            installed = pi.lastUpdateTime;
        } catch (Exception ignored) {
        }
        if (!out.isFile() || out.lastModified() < installed) {
            File tmp = new File(dir, region + ".map.tmp");
            try (InputStream in = ctx.getAssets().open("motor/" + abi + "/" + region + ".map");
                 OutputStream o = new FileOutputStream(tmp)) {
                copy(in, o, null);
            }
            if (!tmp.renameTo(out))
                throw new IOException("rename");
        }
        return out;
    }

    private static long copy(InputStream in, OutputStream out, MessageDigest md) throws IOException {
        byte[] buf = new byte[1 << 16];
        long total = 0;
        int n;
        while ((n = in.read(buf)) > 0) {
            if (md != null)
                md.update(buf, 0, n);
            if (out != null)
                out.write(buf, 0, n);
            total += n;
            if (total > 64L << 20)
                throw new IOException("too big");
        }
        return total;
    }

    private static String hex(byte[] b) {
        StringBuilder s = new StringBuilder();
        for (byte x : b)
            s.append(String.format("%02x", x & 0xFF));
        return s.toString();
    }

    /** Checks the chosen file (a .gba, or a .zip holding one) and, if it is
     *  a supported version, keeps it. */
    Result importRom(Uri uri) {
        byte[] magic = new byte[4];
        int got;
        try (InputStream in = ctx.getContentResolver().openInputStream(uri)) {
            if (in == null)
                return Result.READ_ERR;
            got = readFully(in, magic);
        } catch (Exception e) {
            return Result.READ_ERR;
        }
        if (got >= 4 && magic[0] == 'P' && magic[1] == 'K' && magic[2] == 3 && magic[3] == 4)
            return importZip(uri);
        if (got >= 2 && ((magic[0] == '7' && magic[1] == 'z') || (magic[0] == 'R' && magic[1] == 'a')))
            return Result.ZIP; /* 7-Zip / RAR: not supported */
        try (InputStream in = ctx.getContentResolver().openInputStream(uri)) {
            if (in == null)
                return Result.READ_ERR;
            return importStream(in);
        } catch (Exception e) {
            return Result.READ_ERR;
        }
    }

    /** Looks through a .zip for the game: every entry that looks like a GBA
     *  game is checked, the first supported one is kept. */
    private Result importZip(Uri uri) {
        Result best = Result.NOT_GBA;
        try (InputStream raw = ctx.getContentResolver().openInputStream(uri)) {
            if (raw == null)
                return Result.READ_ERR;
            /* Names are not needed; Latin-1 never fails to decode them. */
            ZipInputStream zin = Build.VERSION.SDK_INT >= 24
                ? new ZipInputStream(new BufferedInputStream(raw, 1 << 16), StandardCharsets.ISO_8859_1)
                : new ZipInputStream(new BufferedInputStream(raw, 1 << 16));
            ZipEntry e;
            int entries = 0;
            while ((e = zin.getNextEntry()) != null) {
                if (++entries > 4096)
                    break;
                if (e.isDirectory())
                    continue;
                long size = e.getSize();
                if (size >= 0 && (size < 0xC0 || size > (64L << 20)))
                    continue;
                Result r = importStream(zin);
                if (r == Result.OK_USA || r == Result.OK_EUR || r == Result.ALREADY || r == Result.COPY_ERR)
                    return r;
                /* Remember the most useful answer if nothing better turns up. */
                if (r == Result.BAD_JP || (r == Result.BAD && best != Result.BAD_JP))
                    best = r;
            }
        } catch (Exception e) {
            return best == Result.NOT_GBA ? Result.READ_ERR : best;
        }
        return best == Result.NOT_GBA ? Result.ZIP_EMPTY : best;
    }

    private static int readFully(InputStream in, byte[] b) throws IOException {
        int got = 0;
        while (got < b.length) {
            int n = in.read(b, got, b.length - got);
            if (n <= 0)
                break;
            got += n;
        }
        return got;
    }

    /** Reads one candidate game from the stream (not closing it). */
    private Result importStream(InputStream in) {
        File tmp = new File(romDir(), "import.tmp");
        String sha;
        byte[] head = new byte[0xC0];
        try {
            int got = readFully(in, head);
            if (got < head.length || (head[0xB2] & 0xFF) != 0x96)
                return Result.NOT_GBA;
            MessageDigest md = MessageDigest.getInstance("SHA-1");
            md.update(head, 0, got);
            try (OutputStream out = new FileOutputStream(tmp)) {
                out.write(head, 0, got);
                copy(in, out, md);
            }
            sha = hex(md.digest());
        } catch (Exception e) {
            tmp.delete();
            return Result.READ_ERR;
        }
        String region = SHA_USA.equals(sha) ? "usa" : SHA_EUR.equals(sha) ? "eur" : null;
        if (region == null) {
            tmp.delete();
            return SHA_JPN.equals(sha) ? Result.BAD_JP : Result.BAD;
        }
        if (has(region)) {
            tmp.delete();
            return Result.ALREADY;
        }
        if (!tmp.renameTo(rom(region))) {
            tmp.delete();
            return Result.COPY_ERR;
        }
        return region.equals("usa") ? Result.OK_USA : Result.OK_EUR;
    }
}
