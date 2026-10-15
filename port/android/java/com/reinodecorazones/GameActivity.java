package com.reinodecorazones;

import android.os.Bundle;
import android.view.WindowManager;

import org.libsdl.app.SDLActivity;

/**
 * The game (libgame.so, started by libmain.so). Runs in its own process
 * (":game"), so leaving the game always ends it cleanly and the next start
 * begins from a fresh copy of the game's memory.
 */
public class GameActivity extends SDLActivity {
    static final String EXTRA_REGION = "region";

    @Override
    protected String[] getLibraries() {
        return new String[] {"SDL2", "main"};
    }

    @Override
    protected String[] getArguments() {
        String region = getIntent().getStringExtra(EXTRA_REGION);
        if (region == null)
            region = "usa";
        RomStore store = new RomStore(this);
        String map;
        try {
            map = store.map(region).getAbsolutePath();
        } catch (Exception e) {
            map = "";
        }
        String root = store.dataRoot().getAbsolutePath() + "/";
        return new String[] {"--root", root, "--rom", store.rom(region).getAbsolutePath(), "--map", map,
                             "--region", region};
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        /* The game's memory is not reusable: the next game starts in a new
         * process (this one only ever hosts the game). */
        System.exit(0);
    }
}
