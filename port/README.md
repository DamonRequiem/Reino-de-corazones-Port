# Reino de Corazones — port nativo para PC de Kingdom Hearts: Chain of Memories

Port para PC construido sobre la decompilación [`pheenoh/khcom`](https://github.com/Pheenoh/khcom).
El juego (las ~258,000 líneas de C de `src/`) se compila como un programa normal de PC.
No es un emulador: la carpeta `port/` reemplaza el hardware de la Game Boy Advance.

> **El programa no contiene datos del juego.** Al abrirlo pide la copia legítima del jugador
> (USA B8CE o Europa B8CP), la reconoce por su SHA-1 y reconstruye con ella los gráficos,
> la música, los textos y las cinemáticas cada vez que arranca. Por eso se puede compartir.

## Menú de pausa y opciones (Esc)

`port/pc_menu.c` dibuja el menú (mismo estilo que el lanzador, textos prerrenderizados por
`port/launcher/make_menu_assets.py`) y `port/pc_video.c` aplica los filtros en la CPU (como mucho 1200x800
píxeles por cuadro):

| Filtro | Qué hace |
|---|---|
| Original | píxeles nítidos (vecino más cercano) |
| Suave | bilineal, en la tarjeta gráfica |
| Píxel limpio | ampliación nítida a Nx y suavizado sólo entre píxeles de pantalla: nítido a cualquier tamaño |
| Bordes suaves | Scale2x / Scale3x (EPX); 4x = 2x dos veces; 5x se dibuja a 4x |
| Pantalla LCD de GBA | rejilla fina entre píxeles (al menos a 3x) |
| Televisor CRT | líneas oscuras y un ligero resplandor horizontal |

Extras: colores de la pantalla de la GBA (luz lineal, mezcla leve de canales y oscurecido) y estela LCD (cada
cuadro mezclado con el anterior).

**Cuadros por segundo.** El juego siempre corre a ~60 cuadros lógicos por segundo, como la consola. En
monitores de 60, 120, 180 o 240 Hz con sincronía, cada cuadro ocupa un número fijo de refrescos (movimiento
perfectamente regular). 30 muestra uno de cada dos cuadros. 120, en monitores de 120 Hz o más, muestra antes de
cada cuadro una imagen intermedia (los dos cuadros mezclados). Se comprobó simulando monitores de 60, 120, 144
y 240 Hz: el juego va a 60 en todos los casos y se muestran 30, 60, 120 o una imagen por refresco según el modo.

## El programa

```
ReinoDeCorazones/
  ReinoDeCorazones.exe      menú: pide la ROM, la verifica y arranca el juego
  motor/rdc-usa.exe, .map   motor de la versión USA (B8CE), sin datos del juego
  motor/rdc-eur.exe, .map   motor de la versión europea (B8CP): español, inglés, francés, alemán, italiano
  rom/                      la copia del jugador (el menú también reconoce un .gba copiado aquí a mano)
  partidas/ config/ capturas/ registros/
```

**Cómo quedan fuera los datos.** Todo lo que viene de la ROM — los recursos extraídos (`build/<versión>/gen`)
y las tablas constantes y variables iniciales que la decompilación tiene en C — se enlaza en dos secciones
propias, `romdat` y `romdatw` (`port/tools/convert_data.py`, regla `cc_game_rom` de `port/build.py`).
`port/tools/strip_rom.c` busca de dónde sale cada byte de esas secciones en la ROM, escribe la tabla
`motor/rdc-<versión>.map` (copias desde la ROM más los pocos bytes que no son del juego: punteros que pone el
enlazador, relleno) y vacía las secciones del ejecutable. Al arrancar, `port/pc_romdata.c` lee la ROM del jugador,
comprueba su SHA-1, copia los trozos a su sitio y comprueba el SHA-1 del resultado (unos 0.1 s).
Se verificó tomando 50,000 muestras al azar de cada ROM: ninguna aparece en el paquete, salvo secuencias
genéricas de números (tablas 0, 1, 2, 3… de la biblioteca de C).

**El menú** (`port/launcher/`) está dibujado para el port: cielo nocturno, luna, un castillo lejano y cartas
flotando (todo original, generado por `port/launcher/make_assets.py`), con las fuentes libres Cinzel y
Cormorant Garamond (licencia OFL). Se maneja con ratón, teclado o mando, y acepta arrastrar el `.gba`.

**Generar el paquete** (necesita tus ROMs en `roms/B8CE.gba` y/o `roms/B8CP.gba`, sólo para calcular las tablas):

```sh
python3 port/tools/prepare_data.py roms/B8CP.gba   # extrae los recursos de cada versión (una vez)
python3 port/tools/prepare_data.py roms/B8CE.gba
python3 port/tools/package.py                      # compila todo y crea dist/ReinoDeCorazones.zip
```

Para compilar una sola versión: `python3 port/build.py --target win32 --version eu` (o `us`).

## Estado del proyecto

| Fase | Contenido | Estado |
|---|---|---|
| 0 | ROM verificada, assets extraídos | ✅ |
| 1 | Compilación nativa a ciegas (sin ventana) | ✅ Arranca, llega al título, menú y selección de archivo sin crashear |
| 2 | Renderizador de video + ventana SDL2 | ✅ Imagen idéntica píxel a píxel a mGBA; ventana, teclado/mando, 59.73 FPS |
| 3 | Guardado, remapeo de controles, corrección de bugs originales | ✅ `.sav` compatible con emuladores, `khcom.ini`, ~230 accesos peligrosos corregidos |
| 4 | Sonido (motor m4a en C) | ✅ Motor de música traducido a C, idéntico byte por byte a la consola; chip de sonido emulado |
| 5 | Cinemáticas (códec de video en C) | ✅ Las 5 cinemáticas, con imagen y sonido idénticos a la consola |
| 6 | Migración a x64 | ⏭️ Descartada: el port de 32 bits corre igual en Windows 10/11 de 64 bits y va ~12 veces más rápido de lo necesario |
| 7 | Pulido y empaquetado | ✅ Versión 1.0: sincronía con el monitor, pausa en segundo plano, icono, versión y manifiesto de Windows |
| 8 | Reino de Corazones | ✅ Menú que pide la ROM, motores sin datos del juego, soporte de la versión europea (5 idiomas) |
| 9 | Opciones de imagen | ✅ Menú de pausa (Esc): 30/60/120 fps, resolución 1x–5x, 6 filtros, colores de GBA, estela LCD |

## Cómo está construido

| Pieza GBA | Reemplazo en PC | Archivo |
|---|---|---|
| Mapa de memoria (VRAM, paletas, OAM, registros, SRAM) | Arreglos normales; los encabezados de `include/gba/` apuntan a ellos bajo `PLATFORM_PC` | `pc_memory.c` |
| BIOS (`CpuSet`, `LZ77`, `Sqrt`, `BgAffineSet`…) | Funciones en C | `pc_bios.c` |
| Controlador DMA (inmediato, VBlank, HBlank) | Emulado | `pc_dma.c` |
| Despachador de interrupciones (`crt0.s`) | Despacho en C con interrupciones pendientes | `pc_intr.c` |
| Barrido de pantalla (228 líneas, HBlank/VCount/VBlank) | Avanza línea por línea cuando el juego espera | `pc_frame.c` |
| Chip de video (PPU) | Renderizador por scanline: modos 0–5, fondos afines, sprites, ventanas, mezcla, mosaico | `pc_render.c` |
| Pantalla, controles, reloj | Ventana SDL2, teclado y mando, ritmo de 59.73 FPS | `pc_main_sdl.c` |
| Motor de sonido m4a (`m4a_1.s`, ensamblador ARM) | Traducido a C: secuenciador, mezclador, reverb, envolventes | `pc_m4a.c` |
| Chip de sonido (4 canales PSG, FIFO A/B, timers, DMA de sonido) | Emulado ciclo a ciclo por scanline, salida a 32768 Hz como la consola | `pc_apu.c` |
| Altavoz | Salida SDL2 a 48 kHz con remuestreo sinc y control de latencia | `pc_audio_out.c` |
| Transformada del códec de audio de los créditos (`transform.s`) | Traducida a C | `pc_transform.c` |
| Códecs de las cinemáticas (`movie_codec.s`: video por bloques, ADPCM) | Traducidos a C | `pc_movie_codec.c` |
| Datos (gráficos, música, texto) en ensamblador ARM | Convertidos a ensamblador x86, verificados byte por byte | `tools/convert_data.py` |

Todos los cambios a archivos originales están dentro de `#ifdef PLATFORM_PC` o de las macros `PC_ONLY(...)` / `GBA_ONLY(...)`.
El código que compila la versión GBA queda idéntico (verificado: agbcc produce el mismo ensamblador).

## El ejecutable

`khcom.exe` es un programa de Windows de 32 bits, sin dependencias: SDL2 va incluido dentro. Lleva icono propio (dibujado para el port, sin arte del juego), información de versión (1.0.0) y un manifiesto que lo declara compatible con Windows 10 y 11, con escalado correcto en pantallas de alta densidad (DPI por monitor) y rutas largas. Los recursos están en `port/res/`; el icono se genera con `port/tools/make_icon.py`.

## Partidas guardadas

El juego guarda en `khcom.sav`, junto a `khcom.exe`. Si esa carpeta es de solo lectura (por ejemplo `Archivos de programa`), usa `%APPDATA%\KHCoM\`. La partida se escribe en disco medio segundo después de guardar en un punto de guardado, y otra vez al cerrar. La versión anterior queda como `khcom.sav.bak`.

El archivo es una copia exacta de la memoria de guardado del cartucho (32 KB), el mismo formato de mGBA y VisualBoyAdvance:

- **Para usar una partida de un emulador:** cópiala junto a `khcom.exe` con el nombre `khcom.sav`.
- **Para llevar tu partida a un emulador:** copia `khcom.sav` con el nombre de la ROM, por ejemplo `Kingdom Hearts - Chain of Memories (USA).sav`.

Se verificó que una partida creada en el port se carga en mGBA y muestra las mismas pantallas.

## Configuración (`khcom.ini`)

Se crea la primera vez que abres el juego, en la misma carpeta que la partida. Ahí puedes cambiar:

- `[video]`: arrancar en pantalla completa, tamaño de la ventana, escalado de píxel exacto y `vsync` (ver abajo).
- `[audio]`: `enabled = 0` quita el sonido; `volume` de 0 a 100.
- `[game]`: `skip_movies = 1` deja saltar las cinemáticas con **Start** (el juego original no lo permite); `0` las deja como en la GBA. `pause_in_background = 1` pausa el juego y el sonido cuando cambias a otra ventana.
- `[keyboard]`: una o varias teclas por botón, separadas por comas. Ejemplo: `start = Return, K`.
- `[gamepad]`: los botones del mando. Ejemplo: `a = b` para intercambiar A y B.

Si una tecla no se reconoce, se anota en `khcom_log.txt` y se ignora. Para volver a los valores por defecto, borra el archivo.

### Sincronía con el monitor (`vsync`)

La GBA dibuja 59.73 cuadros por segundo y casi todos los monitores van a 60 Hz. Si el juego fuera a su velocidad exacta, cada ~4 segundos un cuadro se repetiría y se notaría un pequeño tirón. Con `vsync = 1` (por defecto), en monitores de 60 Hz el juego dibuja exactamente un cuadro por refresco: el movimiento es perfectamente fluido y todo va un 0.46 % más rápido que en la consola, algo imperceptible (el sonido se ajusta solo). En monitores de otra frecuencia (120, 144 Hz…) el juego va a su velocidad original. Con `vsync = 0` siempre va a 59.73 cuadros por segundo.

Si el controlador de video ignora la sincronía (o la ventana está minimizada), el port lo detecta y regula la velocidad con el reloj, así que el juego nunca corre de más.

## Controles

Controles por defecto (se cambian en `khcom.ini`):

| GBA | Teclado | Mando (Xbox / genérico) |
|---|---|---|
| Cruceta | Flechas | Cruceta o stick izquierdo |
| A | X | A |
| B | Z | B |
| L / R | A / S | LB / RB o gatillos |
| Start | Enter | Start |
| Select | Retroceso o Shift derecho | Back / View |

Atajos: **F11** o **Alt+Enter** pantalla completa · **F10** escalado de píxel exacto · mantener **Tab** avance rápido · **F5/F8** guardar/cargar estado · **F9** silenciar/activar sonido · **F12** captura de pantalla · **Esc** salir.

## Compilar en Windows 10/11 (MSYS2)

1. Instala **MSYS2** desde <https://www.msys2.org> con las opciones por defecto.
2. En el menú Inicio, abre **"MSYS2 MINGW32"**. Tiene que ser esa, la de 32 bits.
3. Instala las herramientas. Copia esto, pégalo con clic derecho → *Paste* y pulsa Enter:
   ```sh
   pacman -S --needed git make ninja mingw-w64-i686-gcc mingw-w64-i686-python mingw-w64-i686-python-yaml mingw-w64-i686-libpng mingw-w64-i686-SDL2 mingw-w64-i686-pkgconf
   ```
   Cuando pregunte, responde `Y`.
4. Descarga el proyecto, con este port incluido:
   ```sh
   cd ~ && git clone <URL-de-tu-copia-con-el-port> khcom && cd khcom
   ```
5. Prepara los datos desde tu ROM. Cambia la ruta por donde tengas tu ROM; `C:\Users\Tu\Desktop` se escribe `/c/Users/Tu/Desktop`:
   ```sh
   python3 port/tools/prepare_data.py "/c/Users/Tu/Desktop/Kingdom Hearts - Chain of Memories (USA).gba"
   ```
6. Compila:
   ```sh
   python3 port/build.py --target win32
   ```
   El juego queda en `build/pc/win32/khcom.exe`. Es un solo archivo y no necesita DLLs aparte.

> Estos pasos con MSYS2 todavía no se han probado en una máquina Windows real.
> Los `.exe` entregados se compilaron de forma cruzada desde Linux con MinGW y se probaron con Wine.

## Compilar en Linux

```sh
sudo apt install gcc-multilib mingw-w64 ninja-build python3-yaml libpng-dev
python3 port/tools/prepare_data.py ruta/a/tu/rom.gba
python3 port/tools/fetch_sdl2.py            # SDL2 para Windows (solo para el .exe)
python3 port/build.py --target win32        # khcom.exe (ventana)
python3 port/build.py --target linux32      # khcom_headless (pruebas sin ventana)
```

## Pruebas automáticas

Tanto `khcom` como `khcom_headless` aceptan opciones de prueba. La versión headless corre el juego sin ventana y guarda capturas en BMP:

```sh
khcom_headless --frames 1700 --dump-every 60 --out capturas --press 1000:T --press 1300:A --press 1500:A
```

- `--frames N`: cuántos cuadros correr (60 = 1 segundo de juego).
- `--dump-every N`: guarda una captura cada N cuadros.
- `--press CUADRO:TECLAS`: mantiene teclas 4 cuadros. Las teclas son `A`, `B`, `T` (Start), `S` (Select), `U`/`D`/`L`/`R` (cruceta), `l`/`r` (gatillos).

Al terminar debe decir `reached N frames without crashing`.

`khcom.exe --seconds N` juega N segundos en tiempo real y anota en `khcom_log.txt` los cuadros por segundo conseguidos (para revisar la sincronía).

Opciones de sonido de la versión headless:

- `--wav ARCHIVO`: graba la salida del chip de sonido (32768 Hz estéreo).
- `--dump-pcm ARCHIVO`: guarda el búfer que mezcla el motor m4a cada cuadro, para compararlo con un emulador.
- `--mute N`: 1 apaga los canales PSG, 2 el DirectSound (para aislar diferencias).

Las capturas salen del mismo renderizador que usa la ventana. Se compararon contra mGBA en logos, fundidos, menús, cinemáticas de texto y escenas de juego: coinciden píxel a píxel.

## Compatibilidad con los bugs del juego original

El repositorio documenta más de 100 bugs del juego original (`@bug` en `src/`). En la GBA muchos pasan desapercibidos, pero en una PC cerrarían el juego:

- **Lecturas o escrituras a través de un puntero nulo** (46 sitios documentados, más las 178 lecturas de datos de carta, que fallan con la carta de recarga). En la GBA caen en la BIOS: las lecturas devuelven el último código leído por la BIOS y las escrituras se ignoran. `PC_NULL_FIX` (`include/macros.h`) apunta esos accesos a una página que reproduce ese comportamiento. Cuando el juego sigue un puntero leído así, se aplica la corrección más segura. Si Square Enix corrigió el bug en la versión europea, se usa esa corrección.
- **División entre cero**: la rutina de la GBA devuelve 0, mientras que un procesador x86 lanza un error. `port/pc_divzero.c` captura ese error y devuelve 0, igual que la GBA.
- **Funciones sin valor de retorno** que el juego usa igual. Se devuelve el mismo valor que deja el compilador original (se comprobó compilando con agbcc).
- **Escrituras fuera de rango:** en la GBA se pierden en zonas sin memoria o pisan una variable que se reinicia enseguida. En PC caerían en memoria real, así que se descartan o se les da espacio de sobra.
- **Desborde del búfer de audio de las cinemáticas:** al copiar el sonido, la rutina de la BIOS escribe de 32 en 32 bytes y se pasa hasta 28 bytes del final del búfer, dañando la cabecera del siguiente bloque de memoria. En la GBA los punteros dañados apuntan a memoria inexistente y no pasa nada; en PC cerraba el juego al terminar la cinemática. `src/malloc.c` ignora esas escrituras igual que la GBA.
- **Reinicio suave (A+B+Start+Select):** restaura todas las variables del juego a su estado al encender, igual que la GBA al borrar su RAM. Se comprobó que después del reinicio el juego es idéntico, cuadro por cuadro, a un arranque nuevo.

Para encontrar más bugs de este tipo hay una versión de prueba con AddressSanitizer (`python3 port/build.py --asan`), que detecta cualquier lectura o escritura fuera de los límites de una variable.

Todos los cambios a `src/` e `include/` están dentro de `#ifdef PLATFORM_PC`. Se verificó con el compilador original (agbcc) que el código GBA generado es idéntico.

## Capas contra cierres

1. **Correcciones en el código fuente** de cada bug conocido (`PC_NULL_FIX`, división entre cero, valores de retorno, escrituras fuera de rango).
2. **Red de seguridad para accesos tipo GBA** (`port/pc_fault.c`). Si el juego lee o escribe a través de un puntero nulo, o de un puntero basura leído de la BIOS, el procesador avisa del error. El manejador decodifica la instrucción, mueve el registro con el puntero malo a la página "BIOS" y la repite: el juego obtiene lo mismo que en la GBA. Cada caso se anota una vez en `khcom_log.txt` (`recovered GBA-style access ... at khcom.exe+0x…`) para corregirlo en el código.
3. **Recuperación automática** (`port/pc_state.c`). Cada 2 segundos se guarda una foto completa del juego en memoria: variables, montículos, video y hardware, pero **no** la partida guardada. Si aun así hay un cierre o un congelamiento en el código del juego, se vuelve a esa foto y se sigue jugando. Si vuelve a fallar enseguida, usa una foto de ~10 segundos antes. Se comprobó que, después de recuperarse, el juego es idéntico cuadro por cuadro a una partida que no falló.
4. **Aviso y registro** si nada de lo anterior alcanza.

## Estados guardados (F5 / F8)

**F5** guarda el estado completo en `khcom.state` y **F8** lo carga, también después de cerrar y abrir el juego. Solo se cargan estados hechos con la misma versión del ejecutable. No reemplazan los puntos de guardado del juego: la partida (`khcom.sav`) nunca se modifica al cargar un estado.

## Diagnóstico en Windows

Si el juego se cierra o deja de responder durante 10 segundos, sale de pantalla completa, muestra un aviso y escribe en `khcom_log.txt` la dirección del fallo (`khcom.exe+0x…`). Esa dirección se traduce a archivo y línea con la versión sin recortar del ejecutable (`i686-w64-mingw32-addr2line`).

## Pendientes conocidos

- **Bugs no documentados:** puede haber más accesos a punteros nulos que nadie ha anotado. Las pruebas automáticas con botones al azar (10 corridas de hasta 60,000 cuadros, unos 17 minutos de juego cada una) ya no encuentran ninguno.
- **Audio de los créditos finales:** usa un códec propio; su transformada ya está en C y verificada contra el original, pero no se ha escuchado de punta a punta porque requiere terminar el juego.

## Cinemáticas

El juego trae 5 cinemáticas (apertura, dos eventos y los dos finales): 3,605 cuadros a 240x160 y 15 cuadros por segundo, con sonido ADPCM. Sus decodificadores eran rutinas ARM escritas a mano que el juego copia a la memoria rápida y modifica según el ancho del video. Se tradujeron a C y se compararon contra el código ARM original ejecutado en un emulador: todos los cuadros y todos los bloques de audio de las 5 cinemáticas salen idénticos byte por byte.

En el juego, la apertura se comparó contra mGBA cuadro por cuadro: misma imagen, mismo ritmo, sin desfase del principio al final, y el sonido coincide en volumen y tiempo.


El motor de música del juego (MusicPlayer2000 de Nintendo, escrito en ensamblador ARM) se tradujo a C. Se comparó contra mGBA leyendo el búfer que mezcla el motor cada cuadro: los 1,989 bloques distintos que mezcló el port en 50 segundos de arranque y título aparecen idénticos byte por byte en la consola emulada.

El chip de sonido (canales de onda cuadrada, onda programable, ruido, y los dos canales DirectSound con sus FIFO alimentadas por DMA) se emula a la misma frecuencia de la consola. La salida se convierte a la frecuencia de la tarjeta de sonido con un filtro sinc; la velocidad se corrige como mucho 0.5 % (inaudible) para que nunca se corte ni se acumule retraso. En avance rápido (Tab) el sonido se silencia.
