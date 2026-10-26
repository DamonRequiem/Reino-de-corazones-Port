package com.reinodecorazones;

import android.content.ContentProvider;
import android.content.ContentValues;
import android.database.Cursor;
import android.database.MatrixCursor;
import android.net.Uri;
import android.os.ParcelFileDescriptor;
import android.provider.OpenableColumns;

import java.io.File;
import java.io.FileNotFoundException;

/**
 * Lets the player send the game's logs and saves (registros/, partidas/) to
 * another app, read-only, so a problem can be reported without digging in
 * Android/data. Only those two folders are reachable.
 * content://com.reinodecorazones.files/<folder>/<file>
 */
public final class FileShare extends ContentProvider {
    static final String AUTHORITY = "com.reinodecorazones.files";

    static Uri uriFor(String folder, String name) {
        return new Uri.Builder().scheme("content").authority(AUTHORITY).appendPath(folder).appendPath(name).build();
    }

    private File fileFor(Uri uri) throws FileNotFoundException {
        java.util.List<String> seg = uri.getPathSegments();
        if (seg.size() != 2 || !(seg.get(0).equals("registros") || seg.get(0).equals("partidas")))
            throw new FileNotFoundException(uri.toString());
        String name = seg.get(1);
        if (name.contains("/") || name.contains("..") || name.startsWith("."))
            throw new FileNotFoundException(uri.toString());
        File f = new File(new File(new RomStore(getContext()).dataRoot(), seg.get(0)), name);
        if (!f.isFile())
            throw new FileNotFoundException(uri.toString());
        return f;
    }

    @Override
    public boolean onCreate() {
        return true;
    }

    @Override
    public ParcelFileDescriptor openFile(Uri uri, String mode) throws FileNotFoundException {
        if (mode != null && !mode.equals("r"))
            throw new FileNotFoundException("read only");
        return ParcelFileDescriptor.open(fileFor(uri), ParcelFileDescriptor.MODE_READ_ONLY);
    }

    @Override
    public Cursor query(Uri uri, String[] projection, String selection, String[] args, String sort) {
        File f;
        try {
            f = fileFor(uri);
        } catch (FileNotFoundException e) {
            return null;
        }
        MatrixCursor c = new MatrixCursor(new String[] {OpenableColumns.DISPLAY_NAME, OpenableColumns.SIZE});
        c.addRow(new Object[] {f.getName(), f.length()});
        return c;
    }

    @Override
    public String getType(Uri uri) {
        String p = uri.getPath();
        return p != null && p.endsWith(".txt") ? "text/plain" : "application/octet-stream";
    }

    @Override
    public Uri insert(Uri uri, ContentValues values) {
        return null;
    }

    @Override
    public int delete(Uri uri, String selection, String[] args) {
        return 0;
    }

    @Override
    public int update(Uri uri, ContentValues values, String selection, String[] args) {
        return 0;
    }
}
