#pragma bank 2
#include "main.h"
UINT8 bank_STATE_MENU = 2;

#include "../res/src/font.h"
#include "../res/src/tiles.h"
#include "../res/src/menu.h"
#include "../res/src/player.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Palette.h"
#include "Keys.h"

const UINT16 bg_palette_2[] = {PALETTE_FROM_HEADER(font)};
UINT8 collision_tiles_2[] = {1, 0};
void Start_STATE_MENU() {
	SetPalette(BG_PALETTE, 0, 8, bg_palette_2, bank_STATE_MENU);

	InitScrollTilesColor(0, 48, font, 3);
	InitScroll(menuWidth, menuHeight, menu, collision_tiles_2, 0, 3);
	SHOW_BKG;
}

void Update_STATE_MENU() {
	if (KEY_PRESSED(J_START)) {
        SetState(STATE_GAME);
    }
}