/*
 * pc_config.c
 * khcom.ini: controls and display settings for the SDL frontend.
 *
 * The file is created with the defaults on first run. Each GBA button can be
 * bound to several keys or gamepad buttons, separated by commas, using SDL's
 * names (e.g. "Return", "Left Shift", "Keypad 8"; gamepad: "a", "b", "x",
 * "y", "back", "start", "leftshoulder", "rightshoulder", "lefttrigger",
 * "righttrigger", "dpup", "dpdown", "dpleft", "dpright").
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include "pc_config.h"
#include "pc_platform.h"

PcConfig gPcConfig;

static const char* const sButtonNames[PC_NUM_BUTTONS] = {
    "a", "b", "select", "start", "right", "left", "up", "down", "r", "l",
};

const char* const kFilterNames[6] = {"original", "suave", "limpio", "bordes", "lcd", "crt"};
const char* const kAspectNames[4] = {"original", "4:3", "16:9", "completa"};
static char sPath[1024];

static const char sDefaultIni[] =
    "; Reino de Corazones - configuracion (Kingdom Hearts: Chain of Memories, port nativo)\n"
    "; Borra este archivo para volver a los valores por defecto.\n"
    "\n"
    "[video]\n"
    "; 1 = arrancar en pantalla completa (tambien F11 / Alt+Enter)\n"
    "fullscreen = 0\n"
    "; resolucion: 1 = 240x160, 2 = 480x320, 3 = 720x480, 4 = 960x640, 5 = 1200x800\n"
    "scale = 3\n"
    "; filtro: original, suave, limpio, bordes, lcd, crt\n"
    "filter = original\n"
    "; cuadros por segundo: 30, 60 o 120 (120 necesita un monitor de 120 Hz)\n"
    "fps = 60\n"
    "; 1 = colores de la pantalla de la GBA\n"
    "gba_colors = 0\n"
    "; 1 = estela de la pantalla LCD (mezcla cada cuadro con el anterior)\n"
    "lcd_ghosting = 0\n"
    "; 1 = escalado de pixel exacto, con bordes negros (tambien F10)\n"
    "integer_scale = 0\n"
    "; 1 = sincronizar con el monitor: movimiento sin tirones en pantallas de\n"
    ";     60 Hz (el juego va un 0.5% mas rapido que en la GBA, imperceptible)\n"
    "vsync = 1\n"
    "; motor grafico: auto (Direct3D 11 y, si falla, el mejor disponible),\n"
    ";                direct3d11, direct3d (Direct3D 9), opengl o software\n"
    "renderer = auto\n"
    "\n"
    "[audio]\n"
    "; 0 = sin sonido\n"
    "enabled = 1\n"
    "; volumen de 0 a 100 (tambien F9 silencia / activa el sonido)\n"
    "volume = 100\n"
    "\n"
    "[game]\n"
    "; 1 = Start salta las cinematicas (el juego original no lo permite)\n"
    "skip_movies = 1\n"
    "; 1 = pausar el juego cuando cambias a otra ventana\n"
    "pause_in_background = 1\n"
    "; modo rapido: 2, 3 o 4 veces la velocidad normal (la musica se acelera igual)\n"
    "fast_speed = 2\n"
    "\n"
#ifdef __ANDROID__
    "[screen]\n"
    "; forma de la imagen: original (3:2, como la GBA), 4:3, 16:9 o completa\n"
    "; los bordes muestran el castillo de corazones\n"
    "aspect = original\n"
    "\n"
    "[touch]\n"
    "; botones en pantalla: opacidad de 0 a 100\n"
    "opacity = 70\n"
    "; tamano: 0 = pequeno, 1 = normal, 2 = grande\n"
    "size = 1\n"
    "; 1 = vibracion breve al pulsar un boton\n"
    "vibration = 1\n"
    "\n"
#endif
    "[keyboard]\n"
    "; Boton de GBA = teclas separadas por comas (nombres de SDL)\n"
    "up = Up\n"
    "down = Down\n"
    "left = Left\n"
    "right = Right\n"
    "a = X\n"
    "b = Z\n"
    "l = A\n"
    "r = S\n"
    "start = Return\n"
    "select = Backspace, Right Shift\n"
    "\n"
    "[gamepad]\n"
    "; Botones del mando (nombres de SDL). La cruceta y el stick izquierdo\n"
    "; siempre mueven a Sora.\n"
    "a = a\n"
    "b = b\n"
    "l = leftshoulder, lefttrigger\n"
    "r = rightshoulder, righttrigger\n"
    "start = start\n"
    "select = back\n"
    "up = dpup\n"
    "down = dpdown\n"
    "left = dpleft\n"
    "right = dpright\n";

static char* Trim(char* s) {
    char* e;
    while (isspace((unsigned char)*s))
        s++;
    e = s + strlen(s);
    while (e > s && isspace((unsigned char)e[-1]))
        *--e = '\0';
    return s;
}

static int ButtonIndex(const char* name) {
    int i;
    for (i = 0; i < PC_NUM_BUTTONS; i++)
        if (SDL_strcasecmp(name, sButtonNames[i]) == 0)
            return i;
    return -1;
}

static void AddKey(int button, const char* name) {
    SDL_Scancode sc = SDL_GetScancodeFromName(name);
    PcBinding* b = &gPcConfig.keys[button];
    if (sc == SDL_SCANCODE_UNKNOWN) {
        PcLog("[pc] config: unknown key '%s'\n", name);
        return;
    }
    if (b->count < PC_MAX_BINDINGS)
        b->codes[b->count++] = (int)sc;
}

static void AddPadButton(int button, const char* name) {
    PcBinding* b = &gPcConfig.pad[button];
    SDL_GameControllerButton gb = SDL_GameControllerGetButtonFromString(name);
    int code;

    if (gb != SDL_CONTROLLER_BUTTON_INVALID) {
        code = (int)gb;
    } else {
        SDL_GameControllerAxis ax = SDL_GameControllerGetAxisFromString(name);
        if (ax != SDL_CONTROLLER_AXIS_TRIGGERLEFT && ax != SDL_CONTROLLER_AXIS_TRIGGERRIGHT) {
            PcLog("[pc] config: unknown gamepad button '%s'\n", name);
            return;
        }
        code = PC_PAD_AXIS_FLAG | (int)ax;
    }
    if (b->count < PC_MAX_BINDINGS)
        b->codes[b->count++] = code;
}

static void ParseLine(const char* section, char* key, char* value) {
    if (!SDL_strcasecmp(section, "video")) {
        int v = atoi(value);
        if (!SDL_strcasecmp(key, "fullscreen"))
            gPcConfig.fullscreen = v != 0;
        else if (!SDL_strcasecmp(key, "scale"))
            gPcConfig.scale = v < 1 ? 1 : v > 5 ? 5 : v;
        else if (!SDL_strcasecmp(key, "integer_scale"))
            gPcConfig.integerScale = v != 0;
        else if (!SDL_strcasecmp(key, "vsync"))
            gPcConfig.vsync = v != 0;
        else if (!SDL_strcasecmp(key, "renderer"))
            snprintf(gPcConfig.renderer, sizeof(gPcConfig.renderer), "%s", value);
        else if (!SDL_strcasecmp(key, "fps"))
            gPcConfig.fps = v <= 30 ? 30 : v >= 120 ? 120 : 60;
        else if (!SDL_strcasecmp(key, "gba_colors"))
            gPcConfig.gbaColors = v != 0;
        else if (!SDL_strcasecmp(key, "lcd_ghosting"))
            gPcConfig.ghosting = v != 0;
        else if (!SDL_strcasecmp(key, "filter")) {
            int i;
            for (i = 0; i < 6; i++)
                if (!SDL_strcasecmp(value, kFilterNames[i]))
                    gPcConfig.filter = i;
        }
    } else if (!SDL_strcasecmp(section, "game")) {
        if (!SDL_strcasecmp(key, "skip_movies"))
            gPcConfig.skipMovies = atoi(value) != 0;
        else if (!SDL_strcasecmp(key, "pause_in_background"))
            gPcConfig.pauseInBackground = atoi(value) != 0;
        else if (!SDL_strcasecmp(key, "fast_speed")) {
            int v = atoi(value);
            gPcConfig.fastSpeed = v < 2 ? 2 : v > 4 ? 4 : v;
        }
    } else if (!SDL_strcasecmp(section, "audio")) {
        int v = atoi(value);
        if (!SDL_strcasecmp(key, "enabled"))
            gPcConfig.audioEnabled = v != 0;
        else if (!SDL_strcasecmp(key, "volume"))
            gPcConfig.volume = v < 0 ? 0 : v > 100 ? 100 : v;
    } else if (!SDL_strcasecmp(section, "screen")) {
        if (!SDL_strcasecmp(key, "aspect")) {
            int i;
            for (i = 0; i < 4; i++)
                if (!SDL_strcasecmp(value, kAspectNames[i]))
                    gPcConfig.aspect = i;
        }
    } else if (!SDL_strcasecmp(section, "touch")) {
        int v = atoi(value);
        if (!SDL_strcasecmp(key, "opacity"))
            gPcConfig.touchOpacity = v < 0 ? 0 : v > 100 ? 100 : v;
        else if (!SDL_strcasecmp(key, "size"))
            gPcConfig.touchSize = v < 0 ? 0 : v > 2 ? 2 : v;
        else if (!SDL_strcasecmp(key, "vibration"))
            gPcConfig.vibration = v != 0;
    } else if (!SDL_strcasecmp(section, "keyboard") || !SDL_strcasecmp(section, "gamepad")) {
        int button = ButtonIndex(key);
        int isPad = !SDL_strcasecmp(section, "gamepad");
        char* tok;
        if (button < 0) {
            PcLog("[pc] config: unknown button '%s'\n", key);
            return;
        }
        /* The file replaces the defaults for this button. */
        if (isPad)
            gPcConfig.pad[button].count = 0;
        else
            gPcConfig.keys[button].count = 0;
        for (tok = strtok(value, ","); tok; tok = strtok(NULL, ",")) {
            tok = Trim(tok);
            if (*tok == '\0')
                continue;
            if (isPad)
                AddPadButton(button, tok);
            else
                AddKey(button, tok);
        }
    }
}

static void ParseText(char* text) {
    char section[32] = "";
    char* line;
    char* next;

    for (line = text; line && *line; line = next) {
        char* eq;
        next = strchr(line, '\n');
        if (next)
            *next++ = '\0';
        {
            char* semi = strchr(line, ';');
            if (semi)
                *semi = '\0';
        }
        line = Trim(line);
        if (*line == '\0')
            continue;
        if (*line == '[') {
            char* end = strchr(line, ']');
            if (end) {
                *end = '\0';
                snprintf(section, sizeof(section), "%s", line + 1);
            }
            continue;
        }
        eq = strchr(line, '=');
        if (!eq)
            continue;
        *eq = '\0';
        ParseLine(section, Trim(line), Trim(eq + 1));
    }
}

void PcConfigLoad(const char* path) {
    SDL_RWops* rw;
    char* text;

    memset(&gPcConfig, 0, sizeof(gPcConfig));
    snprintf(sPath, sizeof(sPath), "%s", path);
    gPcConfig.scale = 3;
    gPcConfig.touchOpacity = 70;
    gPcConfig.touchSize = 1;
    gPcConfig.vibration = 1;
    gPcConfig.fastSpeed = 2;
    text = SDL_strdup(sDefaultIni);
    ParseText(text);
    SDL_free(text);

    rw = SDL_RWFromFile(path, "rb");
    if (rw == NULL) {
        rw = SDL_RWFromFile(path, "wb");
        if (rw) {
            SDL_RWwrite(rw, sDefaultIni, 1, sizeof(sDefaultIni) - 1);
            SDL_RWclose(rw);
            PcLog("[pc] config: created %s\n", path);
        }
        return;
    }
    {
        Sint64 size = SDL_RWsize(rw);
        if (size > 0 && size < (1 << 20)) {
            text = SDL_malloc((size_t)size + 1);
            if (text) {
                size_t n = SDL_RWread(rw, text, 1, (size_t)size);
                text[n] = '\0';
                ParseText(text);
                SDL_free(text);
            }
        }
        SDL_RWclose(rw);
    }
    PcLog("[pc] config: loaded %s\n", path);
}

/* Changes one setting in the file, keeping everything else (comments, key
 * bindings) as the player left it. Adds the line if it is missing. */
void PcConfigSet(const char* section, const char* key, const char* value) {
    SDL_RWops* rw;
    char* text = NULL;
    char* out;
    size_t n = 0, cap;
    char header[64];
    const char* sec;
    const char* line = NULL;

    rw = SDL_RWFromFile(sPath, "rb");
    if (rw) {
        Sint64 size = SDL_RWsize(rw);
        if (size > 0 && size < (1 << 20)) {
            text = SDL_malloc((size_t)size + 1);
            if (text) {
                n = SDL_RWread(rw, text, 1, (size_t)size);
                text[n] = '\0';
            }
        }
        SDL_RWclose(rw);
    }
    if (!text) {
        text = SDL_strdup(sDefaultIni);
        n = strlen(text);
    }
    cap = n + 256;
    out = SDL_malloc(cap);
    if (!out) {
        SDL_free(text);
        return;
    }
    snprintf(header, sizeof(header), "[%s]", section);
    sec = strstr(text, header);
    if (sec) {
        /* Find "key =" at the start of a line inside this section. */
        const char* p = strchr(sec, '\n');
        while (p && *p) {
            const char* l = p + 1;
            const char* q = l;
            while (*q == ' ' || *q == '\t')
                q++;
            if (*q == '[')
                break;
            if (!SDL_strncasecmp(q, key, strlen(key))) {
                const char* r = q + strlen(key);
                while (*r == ' ' || *r == '\t')
                    r++;
                if (*r == '=') {
                    line = l;
                    break;
                }
            }
            p = strchr(l, '\n');
        }
        if (line) {
            const char* end = strchr(line, '\n');
            size_t before = (size_t)(line - text);
            if (!end)
                end = text + n;
            memcpy(out, text, before);
            n = before + (size_t)snprintf(out + before, cap - before, "%s = %s", key, value);
            memcpy(out + n, end, strlen(end) + 1);
        } else {
            /* Insert right after the section header line. */
            const char* hdrEnd = strchr(sec, '\n');
            size_t before = hdrEnd ? (size_t)(hdrEnd + 1 - text) : strlen(text);
            memcpy(out, text, before);
            n = before + (size_t)snprintf(out + before, cap - before, "%s = %s\n", key, value);
            memcpy(out + n, text + before, strlen(text + before) + 1);
        }
    } else {
        n = (size_t)snprintf(out, cap, "%s\n%s\n%s = %s\n", text, header, key, value);
    }
    rw = SDL_RWFromFile(sPath, "wb");
    if (rw) {
        SDL_RWwrite(rw, out, 1, strlen(out));
        SDL_RWclose(rw);
    }
    SDL_free(out);
    SDL_free(text);
}
