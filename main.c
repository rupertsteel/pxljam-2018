#include "assetsGenerated/wink.h"
#include <gb/gb.h>

UWORD spritePalette[] = {0, 0, 0, 0};
void main() {
  SPRITES_8x16;
  set_sprite_data(0, 8, winkTile);
  set_sprite_palette(0, 1, spritePalette);

  set_sprite_tile(0, 0);
  move_sprite(0, 75, 75);
  set_sprite_prop(0, 0);

  SHOW_SPRITES;

  while (1) {
    spritePalette[1] += 1;
    if (spritePalette[1] > 32767)
      spritePalette[1] = 0;
    spritePalette[2] += 10;
    if (spritePalette[2] > 32767)
      spritePalette[2] = 0;
    spritePalette[3] += 100;
    if (spritePalette[3] > 32767)
      spritePalette[3] = 0;
    set_sprite_palette(0, 1, spritePalette);
    delay(50);
  }
}
