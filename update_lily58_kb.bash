#!/bin/bash

# copy the neccesary config files
cp -f ./keymap.c ./config.h ./rules.mk /home/iswladi/qmk_firmware/keyboards/lily58/keymaps/isaak/
cp -f ./oled.c ./macros.c /home/iswladi/qmk_firmware/keyboards/lily58/keymaps/isaak/
rm -r /home/iswladi/qmk_firmware/keyboards/lily58/keymaps/isaak/.build/
mkdir /home/iswladi/qmk_firmware/keyboards/lily58/keymaps/isaak/.build/

# to compile the kb
source ~/venvs/qmk/bin/activate
qmk compile -kb lily58 -km isaak
deactivate
