#pragma bank 2
#include "main.h"
UINT8 bank_STATE_GAME = 2;

#include "../res/src/tiles.h"
#include "../res/src/map.h"
#include "../res/src/player.h"
#include "../res/src/door.h"
#include "../res/src/font.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Palette.h"
#include "Frame.h"
#include "Print.h"

static const UINT16 bg_palette[] = {PALETTE_FROM_HEADER(tiles)};

static const UINT16 sprites_palette[] = {
	PALETTE_INDEX(player, 0),
	PALETTE_INDEX(player, 1),
	PALETTE_INDEX(door,  2),
	PALETTE_INDEX(player, 3),
	PALETTE_INDEX(player, 4),
	PALETTE_INDEX(player, 5),
	PALETTE_INDEX(player, 6),
	PALETTE_INDEX(player, 7),
};

static const UINT8 collision_tiles[] = {1, 2, 3, 0};

UINT8 i = 0;

UINT16 currentMapWidth = 0;
UINT16 currentMapHeight = 0;
UINT8 currentMapBank = 0;
unsigned char* currentMapPLN0 = 0;
unsigned char* currentMapPLN1 = 0;

void Start_STATE_GAME() {
	UINT8 i;

	currentMapWidth = mapWidth;
	currentMapHeight = mapHeight;
	currentMapBank = 3;
	currentMapPLN0 = mapPLN0;
	currentMapPLN1 = mapPLN1;

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
	UINT8 i;
	struct Sprite* spr;

	PRINT_POS(0, 1);
	Printf("%d out of %d      ", (UINT16)(i++),1);

	// DEBUG ZONE
	/*SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type == SPRITE_DOOR) {
			struct DoorInfo* data;
			data = (struct DoorInfo*)THIS->custom_data;
			PRINT_POS(1, 1);
			Printf("Door target %d", data->target);
			//Printf("Door (x y) ")
		}
	}*/
}
