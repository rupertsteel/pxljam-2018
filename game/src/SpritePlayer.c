#pragma bank 2
#include "main.h"
UINT8 bank_SPRITE_PLAYER = 2;

#include "Keys.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
#include "Print.h"
#include "SpritePlayer.h"
#include "MapCommon.h"

const UINT8 anim_idle[] = {1, 0};
const UINT8 anim_walk[] = {2, 1, 2};

void Start_SPRITE_PLAYER() {
    struct PlayerInfo* info = (struct PlayerInfo*)THIS->custom_data;
    info->controller = 0;
    info->hasControl = 1;
    info->near = 0;
    THIS->coll_x = 2;
    THIS->coll_y = 0;
    THIS->coll_w = 12;
    THIS->coll_h = 16;
}

void Update_SPRITE_PLAYER() {
    INT8 x = 0;
    INT8 y = 0;
    UINT16 tileX;
    UINT16 tileY;
    UINT8 i;
    struct Sprite* spr;
    struct Sprite tmp;
    struct PlayerInfo* info = (struct PlayerInfo*)THIS->custom_data;
    if (!info->hasControl) {
        if (KEY_PRESSED(J_B)) {
            info->hasControl = 1;
        }   
        return;
    }

    if (KEY_PRESSED(J_UP)) {
        y = -1;
    }
    if (KEY_PRESSED(J_DOWN)) {
        y = 1;
    }
    if (KEY_PRESSED(J_LEFT)) {
        x = -1;
    }
    if (KEY_PRESSED(J_RIGHT)) {
        x = 1;
    }
    if (KEY_PRESSED(J_A) && info->near) {
        info->hasControl = 0;
        PRINT_POS(0, 1);
        Printf("                                       ");
        PRINT_POS(0, 0);
        Printf("Press B to return");
    }
    if (keys == 0) {
        SetSpriteAnim(THIS, anim_idle, 15);
    } else {
        SetSpriteAnim(THIS, anim_walk, 15);
        tmp.x = THIS->x+x;
        tmp.y = THIS->y+y;
        tmp.coll_x = THIS->coll_x;
        tmp.coll_y = THIS->coll_y;
        tmp.coll_w = THIS->coll_w;
        tmp.coll_h = THIS->coll_h;
        SPRITEMANAGER_ITERATE(i, spr) {
            if (spr->type == SPRITE_CONTROLLER) {
                if (CheckCollision(&tmp, spr)) {
                    // PRINT_POS(0, 1); MEMES are great
                    Printf("Press A to use ");
                    info->near = 1;
                    tileX = spr->x >> 3;
                    tileY = (spr->y >> 3) + 1;
                    info->controller = getDataFromMap(tileX, tileY, 1);;
                    return;
                }
            }
        }
        info->near = 0;
        Printf("                                                          ");
        TranslateSprite(THIS, x, y);
    }
}

void Destroy_SPRITE_PLAYER() {
}