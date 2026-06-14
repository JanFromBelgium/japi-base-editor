# Pico firmware (editor-only machine)

This folder builds **Japi Base Editor as standalone firmware** for the Raspberry
Pi Pico 2 (RP2350): the Japi Base platform plus the editor, **without** the
BASIC interpreter. Flash the resulting `.uf2` and you get an editor-only machine
over VGA + PS/2 — its Run menu offers the Japi Commander, but no Basic.

For the full **Japi Base Computer** (editor + BASIC) the firmware is built from
the JapiBaseBasic repository instead. This `pico/` build is the way to get the
editor onto hardware straight from this repo.

## Build

You need the [Pico SDK](https://github.com/raspberrypi/pico-sdk), CMake, Ninja
and the ARM toolchain, plus the Japi Base platform checked out next to this repo
(the build pulls the engine source from there):

```
parent/
  JapiBase/          # the platform: japi_base.c, japi_base.h, ...
  JapiBaseEditor/    # this repo
```

```sh
cd pico
cmake -G Ninja -B build -DPICO_SDK_PATH=/path/to/pico-sdk .
ninja -C build
```

The output is `build/japi_base_editor.uf2`. Hold BOOTSEL while plugging in the
Pico 2 and copy the `.uf2` onto the drive that appears.

Prefer to try the editor without hardware first? See [`../sim/README.md`](../sim/README.md)
for the desktop build.
