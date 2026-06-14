/* Standalone Japi Base Editor firmware entry-point.
 *
 * Builds the editor as an editor-only machine for the Raspberry Pi Pico 2:
 * Japi Base (the platform/engine) + the editor, without the BASIC interpreter.
 * japi_init() brings up VGA, PS/2, the SD card and the flash floppy; then
 * jbe_pico_run() runs the editor and never returns.
 *
 * For the full Japi Base Computer (editor + BASIC) build JapiBaseBasic instead. */
#include "pico/stdlib.h"
#include "japi_base.h"

void jbe_pico_run(void);

int main(void) {
    japi_init();
    jbe_pico_run();
    while (1) tight_loop_contents();   /* unreachable */
}
