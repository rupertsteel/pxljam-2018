#pragma bank 2
#include "main.h"
UINT8 bank_SPRITE_DOOR = 2;

#include "Keys.h"
#include "SpriteManager.h"
#include "MapCommon.h"

const UINT8 anim[] = {4, 0, 1, 2, 3};

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
}

void Update_SPRITE_DOOR() {
    
}

void Destroy_SPRITE_DOOR() {
}