#pragma bank 2
#include "main.h"
UINT8 bank_STATE_GAME_LASER = 2;

#include "../res/src/tiles.h"
#include "../res/src/laser1.h"
#include "../res/src/player.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Palette.h"

static const UINT16 bg_palette[] = {PALETTE_FROM_HEADER(tiles)};
static const UINT16 sprites_palette[] = {PALETTE_FROM_HEADER(player)};

static const UINT8 collision_tiles[] = {1, 2, 3, 0};

void Start_STATE_GAME_LASER() {
	UINT8 i;

	SetPalette(BG_PALETTE, 0, 8, bg_palette, bank_STATE_GAME_LASER);
	SetPalette(SPRITES_PALETTE, 0, 8, sprites_palette, bank_STATE_GAME_LASER);

	SPRITES_8x16;
	for(i = 0; i != N_SPRITE_TYPES; ++ i) {
		SpriteManagerLoad(i);
	}
	SHOW_SPRITES;

	scroll_target = SpriteManagerAdd(SPRITE_PLAYER, 50, 50);

	InitScrollTilesColor(0, 8, tiles, 3);
	InitScroll(mapLaser1Width, mapLaser1Height, mapLaser1, collision_tiles, 0, 3);
	SHOW_BKG;
}

void Update_STATE_GAME_LASER() {
}