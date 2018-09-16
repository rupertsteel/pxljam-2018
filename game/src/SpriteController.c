#pragma bank 2
#include "main.h"
UINT8 bank_SPRITE_CONTROLLER = 2;

#include "Keys.h"
#include "SpriteManager.h"
#include "MapCommon.h"

#include "ZGBMain.h"

void Start_SPRITE_CONTROLLER() {
    //UINT16 tileX;
    //UINT16 tileY;
    //struct DoorInfo* data;

    //SetSpriteAnim(THIS, anim, 50);

    //tileX = THIS->x >> 3;
    //tileY = (THIS->y >> 3) + 1;

    //data = (struct DoorInfo*)THIS->custom_data;
    //data->target = getDataFromMap(tileX, tileY, 1);

    THIS->coll_x = 0;
    THIS->coll_y = 0;
    THIS->coll_w = 16;
    THIS->coll_h = 7;
}

void Update_SPRITE_CONTROLLER() {
    /*UINT8 i;
    struct Sprite* spr;

    SPRITEMANAGER_ITERATE(i, spr) {
        if (spr->type == SPRITE_PLAYER) {
            if (CheckCollision(THIS, spr)) {
                struct DoorInfo* data;
                data = (struct DoorInfo*)THIS->custom_data;
                SetState(data->target);
            }
        }
    }*/
}

void Destroy_SPRITE_CONTROLLER() {
}