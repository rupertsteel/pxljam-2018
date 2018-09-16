#pragma bank 2
#include "main.h"
UINT8 bank_STATE_GAME_LASER1 = 2;

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
#include "Keys.h"

#include "MapCommon.h"
#include "SpriteLaser.h"
#include "SpritePlayer.h"

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

static struct Sprite* laserFl;
static struct Sprite* laserFu;
static struct Sprite* laserFr;
static struct Sprite* laserFd;

static struct Sprite* leftSlot;
static struct Sprite* upSlot;
static struct Sprite* rightSlot;
static struct Sprite* downSlot;

void Start_STATE_GAME_LASER1() {
	UINT8 i;

	StartMap(mapLaser1Width, mapLaser1Height, 3, mapLaser1PLN0, mapLaser1PLN1);

	SetPalette(BG_PALETTE, 0, 8, bg_palette, bank_STATE_GAME_LASER1);
	SetPalette(SPRITES_PALETTE, 0, 8, sprites_palette, bank_STATE_GAME_LASER1);

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

	{
		struct LaserInfo* info;
		laserFl = SpriteManagerAdd(SPRITE_LASER, 100, 50); // 100 50
		rightSlot = laserFl;
		info = (struct LaserInfo*)laserFl->custom_data;
		info->targetLaserState = 1;
		info->targetDirection = 0;
		info->animationSpeed = 25;
	}
	{
		struct LaserInfo* info;
		laserFu = SpriteManagerAdd(SPRITE_LASER, 92, 58);
		downSlot = laserFu;
		info = (struct LaserInfo*)laserFu->custom_data;
		info->targetLaserState = 1;
		info->targetDirection = 1;
		info->animationSpeed = 31;
	}
	{
		struct LaserInfo* info;
		laserFr = SpriteManagerAdd(SPRITE_LASER, 84, 50); // 84 50
		leftSlot = laserFr;
		info = (struct LaserInfo*)laserFr->custom_data;
		info->targetLaserState = 1;
		info->targetDirection = 2;
		info->animationSpeed = 19;
	}
	{
		struct LaserInfo* info;
		laserFd = SpriteManagerAdd(SPRITE_LASER, 92, 42); // 92 42
		upSlot = laserFd;
		info = (struct LaserInfo*)laserFd->custom_data;
		info->targetLaserState = 1;
		info->targetDirection = 3;
		info->animationSpeed = 33;
	}

	InitScrollTilesColor(0, 8, tiles, 3);
	InitScroll(mapLaser1Width, mapLaser1Height, mapLaser1, collision_tiles, 0, 3);
	SHOW_BKG;
}

void Update_STATE_GAME_LASER1() {
	UINT8 controllerControl = 0;
	UINT8 i;
	struct Sprite* spr;

	SPRITEMANAGER_ITERATE(i, spr) {
		if (spr->type == SPRITE_PLAYER) {
			struct PlayerInfo* data;
			data = (struct PlayerInfo*)spr->custom_data;
			
			controllerControl = !data->hasControl;
		}
	}

	if (controllerControl) {
		if (KEY_TICKED(J_LEFT)) {
			//swap_lasers(&leftSlot, &downSlot);
			//swap_lasers(&downSlot, &rightSlot);
		} else if (KEY_TICKED(J_RIGHT)) {
			//swap_lasers(&leftSlot, &downSlot);
			//swap_lasers(&downSlot, &rightSlot);
		} else if (KEY_TICKED(J_UP)) {
			//swap_lasers(&leftSlot, &upSlot);
			//swap_lasers(&leftSlot, &downSlot);
		} else if (KEY_TICKED(J_DOWN)) {
			//swap_lasers(&leftSlot, &downSlot);
			//swap_lasers(&leftSlot, &upSlot);
		}
	}

	if (leftSlot == laserFr
		&& upSlot == laserFd
		&& rightSlot == laserFl
		&& downSlot == laserFu) {
		// puzzle completed, show the door


	}
}
