# Reino de Corazones

<p align="center">
  <a href="https://github.com/DamonRequiem/Reino-de-corazones-Port./releases/latest"><img alt="Descargar APK" src="https://img.shields.io/badge/Descargar-APK%20para%20Android-6b4fd8?style=for-the-badge&logo=android&logoColor=white"></a>
  <br>
  <sub>Versión 1.2.14 · Android 5.0 o superior · <a href="descargas/ReinoDeCorazones-1.2.14.apk">descarga directa</a></sub>
</p>

Proyecto de aficionados para jugar en **Android** un clásico de cartas y acción de Game Boy Advance: *Kingdom Hearts: Chain of Memories*. Se ejecuta como una app nativa, con controles táctiles y opciones de pantalla pensados para teléfonos.

Está basado en el trabajo de preservación de la comunidad de decompilación ([khcom](https://github.com/Pheenoh/khcom)): el código del juego se compila directamente para el teléfono, sin emulador.

> [!NOTE]
> Este repositorio y la app **no incluyen ningún contenido del juego**: ni gráficos, ni música, ni textos. Para jugar necesitas tu propio cartucho y una copia de respaldo hecha por ti. La app solo funciona con una copia original sin modificar y la mantiene en privado dentro del teléfono.

## Descarga

El APK está en [Releases](https://github.com/DamonRequiem/Reino-de-corazones-Port./releases/latest) y también en la carpeta [`descargas/`](descargas/): [ReinoDeCorazones-1.2.14.apk](descargas/ReinoDeCorazones-1.2.14.apk). Las instrucciones vienen en [LEEME_ANDROID.txt](descargas/LEEME_ANDROID.txt). Funciona en Android 5.0 o superior, en teléfonos de 32 y de 64 bits.

SHA-256 del APK: `8bc3f6eb0e82b3abd8221adc224c25b010919709b651b10e79ccce8ea75b8437`

Como no viene de la Play Store, Android puede mostrar un aviso al instalar. Toca "Más detalles" y luego "Instalar de todas formas".

## Características

- Controles táctiles con arte original:
  - Joystick flotante.
  - Botones de ataque y salto.
  - Placas curvas para cambiar de carta.
  - Vibración opcional.
- Forma de pantalla a elegir: original, 4:3, 16:9 o completa, con bordes decorados en lugar de franjas negras.
- Filtros de imagen.
- Modo rápido x2, x3 o x4, con el sonido acelerado.
- Estados guardados.
- Si sales de la app, la partida queda en pausa y continúa donde la dejaste.
- Compatible con mandos Bluetooth y USB.

## Compilar

Las instrucciones están en [`port/android/README.md`](port/android/README.md).

La compilación usa clang, SDL2 y las herramientas de Android, sin Gradle. Las bibliotecas que salen de la compilación no llevan datos del juego: los lee la app desde la copia del usuario.

El código del port está en `port/`; una parte es compartida con una versión de escritorio que todavía está en preparación. Las notas del proyecto de decompilación original están en [`README_DECOMP.md`](README_DECOMP.md).

## Licencia

- El código de este repositorio está bajo **CC0 1.0** (ver [`LICENSE.md`](LICENSE.md)), igual que el proyecto en el que se basa.
- Los componentes de terceros conservan sus licencias; ver [`TERCEROS.md`](TERCEROS.md).

Proyecto sin ánimo de lucro y sin relación con los dueños de la obra original, a quienes pertenecen el juego, sus nombres y sus personajes. Todo el arte de la app es original.

## Créditos

- Decompilación: [khcom](https://github.com/Pheenoh/khcom) y sus colaboradores.
- Port para Android: Edinson.
