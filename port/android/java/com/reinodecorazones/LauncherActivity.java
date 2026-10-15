package com.reinodecorazones;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.LinearGradient;
import android.graphics.Paint;
import android.graphics.RectF;
import android.graphics.Shader;
import android.graphics.Typeface;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;

import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

/**
 * The first screen: asks for the player's own copy of the game (checked by
 * its SHA-1, kept on the phone), then lets them choose which version to play.
 * Same look as the PC launcher: night sky, castle, floating cards, gold.
 */
public class LauncherActivity extends Activity {
    private static final int PICK_ROM = 1;
    static final String VERSION = "v1.3.0 · Android";

    private RomStore store;
    private MenuView view;
    private final Handler ui = new Handler(Looper.getMainLooper());

    @Override
    protected void onCreate(Bundle b) {
        super.onCreate(b);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN);
        /* Draw under the camera hole too: without this, phones with a punch
         * hole leave a black strip along that side in landscape. */
        if (Build.VERSION.SDK_INT >= 28) {
            WindowManager.LayoutParams lp = getWindow().getAttributes();
            lp.layoutInDisplayCutoutMode = Build.VERSION.SDK_INT >= 30
                ? 3 /* LAYOUT_IN_DISPLAY_CUTOUT_MODE_ALWAYS */
                : WindowManager.LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;
            getWindow().setAttributes(lp);
        }
        getWindow().setBackgroundDrawable(new android.graphics.drawable.ColorDrawable(0xFF0A0C28));
        store = new RomStore(this);
        view = new MenuView(this);
        setContentView(view);
        hideBars();
    }

    @Override
    protected void onResume() {
        super.onResume();
        hideBars();
        view.rebuild();
    }

    @Override
    public void onWindowFocusChanged(boolean hasFocus) {
        super.onWindowFocusChanged(hasFocus);
        if (hasFocus)
            hideBars();
    }

    @SuppressWarnings("deprecation")
    private void hideBars() {
        if (Build.VERSION.SDK_INT >= 19)
            getWindow().getDecorView().setSystemUiVisibility(
                View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY | View.SYSTEM_UI_FLAG_FULLSCREEN |
                View.SYSTEM_UI_FLAG_HIDE_NAVIGATION | View.SYSTEM_UI_FLAG_LAYOUT_STABLE |
                View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION | View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN);
    }

    void pickRom() {
        Intent i = new Intent(Intent.ACTION_OPEN_DOCUMENT);
        i.addCategory(Intent.CATEGORY_OPENABLE);
        i.setType("*/*");
        try {
            startActivityForResult(i, PICK_ROM);
        } catch (Exception e) {
            Intent g = new Intent(Intent.ACTION_GET_CONTENT);
            g.addCategory(Intent.CATEGORY_OPENABLE);
            g.setType("*/*");
            startActivityForResult(g, PICK_ROM);
        }
    }

    @Override
    protected void onActivityResult(int req, int res, Intent data) {
        super.onActivityResult(req, res, data);
        if (req != PICK_ROM || res != RESULT_OK || data == null || data.getData() == null)
            return;
        final Uri uri = data.getData();
        view.setMessage("Comprobando tu copia…", false);
        new Thread(new Runnable() { public void run() {
            final RomStore.Result r = store.importRom(uri);
            ui.post(new Runnable() { public void run() {
                switch (r) {
                    case OK_EUR: view.setMessage("Copia verificada: Europa (B8CP). ¡Bienvenido al reino!", false); break;
                    case OK_USA: view.setMessage("Copia verificada: USA (B8CE). ¡Bienvenido al reino!", false); break;
                    case ALREADY: view.setMessage("Esa versión ya estaba lista para jugar.", false); break;
                    case BAD_JP: view.setMessage("Es la versión japonesa: por ahora solo se admiten USA y Europa.", true); break;
                    case NOT_GBA: view.setMessage("Ese archivo no parece un juego de GBA.", true); break;
                    case ZIP: view.setMessage("Ese formato comprimido (7z/RAR) no se admite: usa un .zip o el archivo .gba.", true); break;
                    case ZIP_EMPTY: view.setMessage("Ese .zip no contiene un juego de GBA.", true); break;
                    case READ_ERR: view.setMessage("No se pudo leer ese archivo.", true); break;
                    case COPY_ERR: view.setMessage("No se pudo guardar la copia en el teléfono.", true); break;
                    default: view.setMessage("Ese archivo no es una copia compatible del juego.", true); break;
                }
                view.rebuild();
            }});
        }}).start();
    }

    Runnable pickAction() {
        return new Runnable() { public void run() { pickRom(); } };
    }

    Runnable finishAction() {
        return new Runnable() { public void run() { finish(); } };
    }

    Runnable playAction(final String region) {
        return new Runnable() { public void run() { play(region); } };
    }

    void play(String region) {
        view.setMessage("Abriendo el reino…", false);
        Intent i = new Intent(this, GameActivity.class);
        i.putExtra(GameActivity.EXTRA_REGION, region);
        startActivity(i);
    }

    /* ------------------------------------------------------------------ */

    private static final class Button {
        final String label, sub;
        final Runnable action;
        final RectF box = new RectF();

        Button(String label, String sub, Runnable action) {
            this.label = label;
            this.sub = sub;
            this.action = action;
        }
    }

    private final class MenuView extends View {
        static final float W = 960, H = 600; /* design coordinates, as on PC */
        final Bitmap bg, twinkle;
        final Bitmap[] cards = new Bitmap[3];
        final Typeface title, head, body;
        final Paint p = new Paint(Paint.ANTI_ALIAS_FLAG | Paint.FILTER_BITMAP_FLAG);
        final List<Button> buttons = new ArrayList<>();
        String[] intro = new String[0];
        String heading;
        String message;
        boolean messageBad;
        int pressed = -1, selected = 0;
        float scale = 1, ox, oy;
        final long start = System.currentTimeMillis();

        MenuView(Context c) {
            super(c);
            bg = load("art/fondo.png");
            twinkle = load("art/twinkle.png");
            for (int i = 0; i < 3; i++)
                cards[i] = load("art/card" + i + ".png");
            title = font("fonts/CinzelDecorative-Bold.ttf", Typeface.SERIF);
            head = font("fonts/Cinzel.ttf", Typeface.SERIF);
            body = font("fonts/CormorantGaramond.ttf", Typeface.SERIF);
            setFocusable(true);
            setFocusableInTouchMode(true);
            setKeepScreenOn(false);
        }

        private Bitmap load(String asset) {
            try (InputStream in = getContext().getAssets().open(asset)) {
                return BitmapFactory.decodeStream(in);
            } catch (Exception e) {
                return null;
            }
        }

        private Typeface font(String asset, Typeface fallback) {
            try {
                return Typeface.createFromAsset(getContext().getAssets(), asset);
            } catch (Exception e) {
                return fallback;
            }
        }

        void setMessage(String m, boolean bad) {
            message = m;
            messageBad = bad;
            invalidate();
        }

        void rebuild() {
            buttons.clear();
            boolean eur = store.has("eur"), usa = store.has("usa");
            if (!eur && !usa) {
                heading = null;
                intro = new String[] {"Para comenzar tu viaje, el reino necesita tu copia legítima del juego.",
                                      "Toca el botón y elige tu archivo .gba o .zip."};
                buttons.add(new Button("Buscar mi juego", "USA (B8CE) o Europa (B8CP)", pickAction()));
            } else {
                heading = "Elige tu destino";
                intro = new String[0];
                if (eur)
                    buttons.add(new Button("Jugar  ·  Europa", "Español, inglés, francés, alemán e italiano",
                                           playAction("eur")));
                if (usa)
                    buttons.add(new Button("Jugar  ·  USA", "En inglés", playAction("usa")));
                if (!eur || !usa)
                    buttons.add(new Button("Añadir otra versión",
                                           eur ? "La versión USA (B8CE)" : "La versión europea (B8CP), con español",
                                           pickAction()));
            }
            buttons.add(new Button("Salir", null, finishAction()));
            if (selected >= buttons.size())
                selected = 0;
            invalidate();
        }

        /* --- drawing --- */

        private void text(Canvas c, String s, float cx, float y, Typeface tf, float size, int color, boolean shadow) {
            p.setShader(null);
            p.setTypeface(tf);
            p.setTextSize(size);
            p.setTextAlign(Paint.Align.CENTER);
            if (shadow) {
                p.setColor(0xC0050514);
                c.drawText(s, cx + 1.5f, y + 2f, p);
            }
            p.setColor(color);
            c.drawText(s, cx, y, p);
        }

        @Override
        protected void onDraw(Canvas c) {
            float t = (System.currentTimeMillis() - start) / 1000f;
            int vw = getWidth(), vh = getHeight();
            c.drawColor(Color.rgb(6, 8, 26));
            /* Background covers the screen; the menu fits inside it. */
            if (bg != null) {
                float k = Math.max(vw / (float) bg.getWidth(), vh / (float) bg.getHeight());
                float bw = bg.getWidth() * k, bh = bg.getHeight() * k;
                c.drawBitmap(bg, null, new RectF((vw - bw) / 2, (vh - bh) / 2, (vw + bw) / 2, (vh + bh) / 2), p);
            }
            scale = Math.min(vw / W, vh / H);
            ox = (vw - W * scale) / 2;
            oy = (vh - H * scale) / 2;
            c.save();
            c.translate(ox, oy);
            c.scale(scale, scale);

            /* Twinkling stars and floating cards. */
            if (twinkle != null) {
                float[][] st = {{120, 80}, {300, 40}, {520, 110}, {700, 60}, {860, 150}, {60, 230}, {420, 30}};
                for (int i = 0; i < st.length; i++) {
                    float a = 0.5f + 0.5f * (float) Math.sin(t * 1.7 + i * 1.3);
                    p.setAlpha((int) (a * 220));
                    c.drawBitmap(twinkle, st[i][0] - 16, st[i][1] - 16, p);
                }
                p.setAlpha(255);
            }
            float[][] cp = {{70, 360, -12}, {878, 420, 10}, {800, 120, -6}};
            for (int i = 0; i < 3; i++) {
                if (cards[i] == null)
                    continue;
                c.save();
                float bob = 8 * (float) Math.sin(t * 0.9 + i * 2.1);
                c.translate(cp[i][0], cp[i][1] + bob);
                c.rotate(cp[i][2] + 3 * (float) Math.sin(t * 0.6 + i));
                p.setAlpha(210);
                c.drawBitmap(cards[i], -cards[i].getWidth() / 2f, -cards[i].getHeight() / 2f, p);
                p.setAlpha(255);
                c.restore();
            }

            /* Title in gold. */
            p.setTypeface(title);
            p.setTextSize(64);
            p.setTextAlign(Paint.Align.CENTER);
            p.setColor(0x90000000);
            c.drawText("Reino de Corazones", W / 2 + 2, 112 + 3, p);
            p.setShader(new LinearGradient(0, 62, 0, 116, Color.rgb(255, 236, 186), Color.rgb(236, 200, 120),
                                           Shader.TileMode.CLAMP));
            c.drawText("Reino de Corazones", W / 2, 112, p);
            p.setShader(null);
            text(c, "Kingdom Hearts: Chain of Memories  ·  port nativo para Android", W / 2, 148, body, 23,
                 0xFFCFC8F0, true);
            ornament(c, W / 2, 168);

            float y = 214;
            for (String line : intro) {
                text(c, line, W / 2, y, body, 25, 0xFFF4EEFF, true);
                y += 34;
            }
            if (heading != null) {
                text(c, heading, W / 2, y, head, 25, 0xFFECC878, true);
                y += 22;
            } else {
                y += 6;
            }

            /* Buttons. */
            float bw = 470, bh = buttons.size() > 3 ? 56 : 62, gap = 12;
            for (int i = 0; i < buttons.size(); i++) {
                Button b = buttons.get(i);
                b.box.set(W / 2 - bw / 2, y, W / 2 + bw / 2, y + bh);
                boolean sel = i == pressed || (pressed < 0 && i == selected && hasFocus() && keyNav);
                p.setStyle(Paint.Style.FILL);
                p.setColor(sel ? 0xEB3A2C60 : 0xC80E1234);
                c.drawRoundRect(b.box, 14, 14, p);
                p.setStyle(Paint.Style.STROKE);
                p.setStrokeWidth(sel ? 3 : 2);
                p.setColor(sel ? 0xFFECC878 : 0x9696A0DC);
                c.drawRoundRect(b.box, 14, 14, p);
                p.setStyle(Paint.Style.FILL);
                if (b.sub == null) {
                    text(c, b.label, W / 2, y + bh / 2 + 9, head, 24, sel ? 0xFFFFEEC4 : 0xFFE6E4FF, false);
                } else {
                    text(c, b.label, W / 2, y + bh / 2 - 2, head, 23, sel ? 0xFFFFEEC4 : 0xFFE6E4FF, false);
                    text(c, b.sub, W / 2, y + bh / 2 + 20, body, 18, 0xFFB8B4DC, false);
                }
                y += bh + gap;
            }

            if (message != null)
                text(c, message, W / 2, Math.max(y + 22, 520), body, 23, messageBad ? 0xFFFFA8A0 : 0xFFF4E2B0, true);
            text(c, "Tu juego no sale de tu teléfono: solo se comprueba su huella SHA-1.", W / 2, 566, body, 18,
                 0xFF9C98C8, true);
            p.setTextAlign(Paint.Align.RIGHT);
            p.setTypeface(body);
            p.setTextSize(16);
            p.setColor(0xFF7C78A8);
            c.drawText(VERSION, W - 14, H - 12, p);
            c.restore();
            postInvalidateDelayed(33);
        }

        private void ornament(Canvas c, float cx, float cy) {
            p.setShader(new LinearGradient(cx - 230, 0, cx + 230, 0, new int[] {0x00ECC878, 0xE6ECC878, 0x00ECC878},
                                           null, Shader.TileMode.CLAMP));
            c.drawRect(cx - 230, cy - 0.75f, cx + 230, cy + 0.75f, p);
            p.setShader(null);
            p.setColor(0xFFFFECBA);
            android.graphics.Path d = new android.graphics.Path();
            d.moveTo(cx, cy - 8);
            d.lineTo(cx + 8, cy);
            d.lineTo(cx, cy + 8);
            d.lineTo(cx - 8, cy);
            d.close();
            c.drawPath(d, p);
        }

        /* --- input --- */

        boolean keyNav;

        private int hit(float x, float y) {
            float mx = (x - ox) / scale, my = (y - oy) / scale;
            for (int i = 0; i < buttons.size(); i++)
                if (buttons.get(i).box.contains(mx, my))
                    return i;
            return -1;
        }

        @Override
        public boolean onTouchEvent(MotionEvent e) {
            keyNav = false;
            switch (e.getActionMasked()) {
                case MotionEvent.ACTION_DOWN:
                case MotionEvent.ACTION_MOVE:
                    pressed = hit(e.getX(), e.getY());
                    invalidate();
                    return true;
                case MotionEvent.ACTION_UP: {
                    int h = hit(e.getX(), e.getY());
                    pressed = -1;
                    invalidate();
                    if (h >= 0) {
                        performHapticFeedback(android.view.HapticFeedbackConstants.VIRTUAL_KEY);
                        buttons.get(h).action.run();
                    }
                    return true;
                }
                case MotionEvent.ACTION_CANCEL:
                    pressed = -1;
                    invalidate();
                    return true;
            }
            return super.onTouchEvent(e);
        }

        @Override
        public boolean onKeyDown(int code, KeyEvent e) {
            /* Gamepads and keyboards work too. */
            switch (code) {
                case KeyEvent.KEYCODE_DPAD_UP:
                    keyNav = true;
                    selected = (selected + buttons.size() - 1) % buttons.size();
                    invalidate();
                    return true;
                case KeyEvent.KEYCODE_DPAD_DOWN:
                    keyNav = true;
                    selected = (selected + 1) % buttons.size();
                    invalidate();
                    return true;
                case KeyEvent.KEYCODE_DPAD_CENTER:
                case KeyEvent.KEYCODE_ENTER:
                case KeyEvent.KEYCODE_BUTTON_A:
                case KeyEvent.KEYCODE_BUTTON_START:
                    if (!buttons.isEmpty())
                        buttons.get(selected).action.run();
                    return true;
            }
            return super.onKeyDown(code, e);
        }
    }
}
