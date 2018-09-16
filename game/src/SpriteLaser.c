#pragma bank 2
#include "main.h"
UINT8 bank_SPRITE_LASER = 2;

#include "Keys.h"
#include "SpriteManager.h"
#include "MapCommon.h"

#include "ZGBMain.h"

static const UINT8 anim[] = {6, 1, 2, 1, 3, 1, 4};

void Start_SPRITE_LASER() {
    SetSpriteAnim(THIS, anim, 25);

    SPRITE_SET_CGB_PALETTE(THIS, 4);
}

void Update_SPRITE_LASER() {
}

void Destroy_SPRITE_LASER() {
}