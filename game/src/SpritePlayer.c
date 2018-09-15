#pragma bank 2
#include "main.h"
UINT8 bank_SPRITE_PLAYER = 2;

#include "Keys.h"
#include "SpriteManager.h"

const UINT8 anim_idle[] = {1, 0};
const UINT8 anim_walk[] = {2, 1, 2};

void Start_SPRITE_PLAYER() {
}

void Update_SPRITE_PLAYER() {
    if (KEY_PRESSED(J_UP)) {
        THIS->y--;
        SetSpriteAnim(THIS, anim_walk, 15);
    }
    if (KEY_PRESSED(J_DOWN)) {
        THIS->y++;
        SetSpriteAnim(THIS, anim_walk, 15);
    }
    if (KEY_PRESSED(J_LEFT)) {
        THIS->x--;
        SetSpriteAnim(THIS, anim_walk, 15);
    }
    if (KEY_PRESSED(J_RIGHT)) {
        THIS->x++;
        SetSpriteAnim(THIS, anim_walk, 15);
    }
    if (keys == 0) {
        SetSpriteAnim(THIS, anim_idle, 15);
    }
}

void Destroy_SPRITE_PLAYER() {
}