#pragma bank 2
#include "main.h"
UINT8 bank_STATE_GAME = 2;

#include "../res/src/tiles.h"
#include "../res/src/map.h"
#include "../res/src/player.h"
#include "../res/src/font.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Palette.h"
#include "Frame.h"
#include "Print.h"

const UINT16 bg_palette[] = {PALETTE_FROM_HEADER(tiles)};
UINT16 sprites_palette[] = {PALETTE_FROM_HEADER(player)};

UINT8 collision_tiles[] = {1, 2, 3, 0};
UINT8 i = 0;
void Start_STATE_GAME() {
	UINT8 i;

	SetPalette(BG_PALETTE, 0, 8, bg_palette, bank_STATE_GAME);
	SetPalette(SPRITES_PALETTE, 0, 8, sprites_palette, bank_STATE_GAME);

	SPRITES_8x16;
	for(i = 0; i != N_SPRITE_TYPES; ++ i) {
		SpriteManagerLoad(i);
	}
	SHOW_SPRITES;
	print_target = PRINT_WIN;
	print_x = 0;
	print_y = 0;
	font_idx = 255 - 45;
	InitScrollTilesColor(255 - 45, 45, font, 3);
	WX_REG = 7;
  	WY_REG = (144 - (2 << 3));
	scroll_h_border = 2 << 3;
	SHOW_WIN;
	scroll_target = SpriteManagerAdd(SPRITE_PLAYER, 50, 50);

	InitScrollTilesColor(0, 8, tiles, 3);
	InitScroll(mapWidth, mapHeight, map, collision_tiles, 0, 3);
	SHOW_BKG;
	
}

void Update_STATE_GAME() {
	PRINT_POS(0, 1);
	Printf("%d out of %d      ", (UINT16)(i++),1);
}