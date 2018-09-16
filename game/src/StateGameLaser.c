#pragma bank 2
#include "main.h"
UINT8 bank_STATE_GAME_LASER = 2;

#include "../res/src/tiles.h"
#include "../res/src/laser1.h"
#include "../res/src/player.h"
#include "../res/src/door.h"
#include "../res/src/font.h"
#include "../res/src/laser.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Palette.h"
#include "Print.h"
#include "Frame.h"

#include "MapCommon.h"
#include "SpriteLaser.h"

static const UINT16 bg_palette[] = {PALETTE_FROM_HEADER(tiles)};

static const UINT16 sprites_palette[] = {
	PALETTE_INDEX(player, 0),
	PALETTE_INDEX(player, 1),
	PALETTE_INDEX(door,  2),
	PALETTE_INDEX(player, 3),
	PALETTE_INDEX(laserSprite, 4),
	PALETTE_INDEX(laserSprite, 5),
	PALETTE_INDEX(laserSprite, 6),
	PALETTE_INDEX(laserSprite, 7),
};

static const UINT8 collision_tiles[] = {1, 2, 3, 0};

void Start_STATE_GAME_LASER() {
	UINT8 i;
	struct Sprite* addedLaserSprite;

	StartMap(mapLaser1Width, mapLaser1Height, 3, mapLaser1PLN0, mapLaser1PLN1);

	SetPalette(BG_PALETTE, 0, 8, bg_palette, bank_STATE_GAME_LASER);
	SetPalette(SPRITES_PALETTE, 0, 8, sprites_palette, bank_STATE_GAME_LASER);

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

	addedLaserSprite = SpriteManagerAdd(SPRITE_LASER, 80, 50);
	{
		struct LaserInfo* info = (struct LaserInfo*)addedLaserSprite->custom_data;
		info->targetLaserState = 1;
		info->targetDirection = 1;
	}

	InitScrollTilesColor(0, 8, tiles, 3);
	InitScroll(mapLaser1Width, mapLaser1Height, mapLaser1, collision_tiles, 0, 3);
	SHOW_BKG;
}

void Update_STATE_GAME_LASER() {
}