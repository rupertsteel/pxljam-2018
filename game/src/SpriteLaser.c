#pragma bank 2
#include "main.h"
UINT8 bank_SPRITE_LASER = 2;

#include "SpriteLaser.h"

#include "Keys.h"
#include "SpriteManager.h"
#include "MapCommon.h"

#include "ZGBMain.h"

static const UINT8 flStaticAnim[] = {1, 0};
static const UINT8 flAnim[] = {6, 1, 2, 1, 3, 1, 4};
static const UINT8 fuStaticAnim[] = {1, 5};
static const UINT8 fuAnim[] = {6, 6, 7, 6, 8, 6, 9};
static const UINT8 frStaticAnim[] = {1, 10};
static const UINT8 frAnim[] = {6, 11, 12, 11, 13, 11, 14};
static const UINT8 fdStaticAnim[] = {1, 15};
static const UINT8 fdAnim[] = {6, 16, 17, 16, 18, 16, 19};

static const UINT8 fulStaticAnim[] = {1, 20};
static const UINT8 fulAnim[] = {6, 21, 22, 21, 23, 21, 24};
static const UINT8 furStaticAnim[] = {1, 25};
static const UINT8 furAnim[] = {6, 26, 27, 26, 28, 26, 29};
static const UINT8 fdrStaticAnim[] = {1, 30};
static const UINT8 fdrAnim[] = {6, 31, 32, 31, 33, 31, 34};
static const UINT8 fdlStaticAnim[] = {1, 35};
static const UINT8 fdlAnim[] = {6, 36, 37, 36, 38, 36, 39};

void Start_SPRITE_LASER() {
    struct LaserInfo* info = (struct LaserInfo*)THIS->custom_data;
    info->targetDirection = 0;
    info->currentDirection = -1;
    info->targetLaserState = 0;
    info->currentLaserState = 0;

    THIS->lim_x = 1000;
    THIS->lim_y = 1000;

    SPRITE_SET_CGB_PALETTE(THIS, 4);
}

void Update_SPRITE_LASER() {
    UINT8 animationUpdateNeeded = 0;

    struct LaserInfo* info = (struct LaserInfo*)THIS->custom_data;
    if (info->targetDirection != info->currentDirection) {
        // if the lasers direction changes, change the animation as well
        info->currentDirection = info->targetDirection;
        animationUpdateNeeded = 1;
    }

    if (info->targetLaserState != info->currentLaserState) {
        info->currentLaserState = info->targetLaserState;
        animationUpdateNeeded = 1;
    }

    if (animationUpdateNeeded && !info->currentLaserState) {
        const UINT8* animationData;
        switch (info->targetDirection) {
        case 0: animationData = flStaticAnim; break;
        case 1: animationData = fuStaticAnim; break;
        case 2: animationData = frStaticAnim; break;
        case 3: animationData = fdStaticAnim; break;
        case 4: animationData = fulStaticAnim; break;
        case 5: animationData = furStaticAnim; break;
        case 6: animationData = fdrStaticAnim; break;
        case 7: animationData = fdlStaticAnim; break;
        }
        SetSpriteAnim(THIS, animationData, info->animationSpeed);
    } else if (animationUpdateNeeded) {
        const UINT8* animationData;
        switch (info->targetDirection) {
        case 0: animationData = flAnim; break;
        case 1: animationData = fuAnim; break;
        case 2: animationData = frAnim; break;
        case 3: animationData = fdAnim; break;
        case 4: animationData = fulAnim; break;
        case 5: animationData = furAnim; break;
        case 6: animationData = fdrAnim; break;
        case 7: animationData = fdlAnim; break;
        }
        SetSpriteAnim(THIS, animationData, info->animationSpeed);
    }
}

void Destroy_SPRITE_LASER() {
}