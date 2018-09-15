#pragma bank 2
#include "main.h"
UINT8 bank_SPRITE_DOOR = 2;

#include "Keys.h"
#include "SpriteManager.h"

const UINT8 anim[] = {4, 0, 1, 2, 3};

void Start_SPRITE_DOOR() {
    SetSpriteAnim(THIS, anim, 50);
}

void Update_SPRITE_DOOR() {
    
}

void Destroy_SPRITE_DOOR() {
}