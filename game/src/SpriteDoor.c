#pragma bank 2
#include "main.h"
UINT8 bank_SPRITE_DOOR = 2;

#include "Keys.h"
#include "SpriteManager.h"
#include "MapCommon.h"

#include "ZGBMain.h"

static const UINT8 anim[] = {4, 0, 1, 2, 3};

typedef struct DoorInfo {
	INT8 target;
} DoorInfo;

void Start_SPRITE_DOOR() {
    UINT16 tileX;
    UINT16 tileY;
    struct DoorInfo* data;

    SetSpriteAnim(THIS, anim, 50);

    tileX = THIS->x >> 3;
    tileY = (THIS->y >> 3) + 1;

    data = (struct DoorInfo*)THIS->custom_data;
    data->target = getDataFromMap(tileX, tileY, 1);

    THIS->coll_x = 0;
    THIS->coll_y = 0;
    THIS->coll_w = 16;
    THIS->coll_h = 1;
}

void Update_SPRITE_DOOR() {
    UINT8 i;
    struct Sprite* spr;

    SPRITEMANAGER_ITERATE(i, spr) {
        if (spr->type == SPRITE_PLAYER) {
            if (CheckCollision(THIS, spr)) {
                struct DoorInfo* data;
                data = (struct DoorInfo*)THIS->custom_data;
                SetState(data->target);
            }
        }
    }
}

void Destroy_SPRITE_DOOR() {
}