#include <gb/gb.h>
#include "assetsGenerated/wink.h"


void main() {
    SPRITES_8x16;
    set_sprite_data(0, 8, winkTile);
    set_sprite_tile(0, 0);
    move_sprite(0, 75, 75);
    SHOW_SPRITES;
}