#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#define STATES \
_STATE(STATE_GAME)\
STATE_DEF_END

#define SPRITES \
_SPRITE_COLOR(SPRITE_PLAYER, player, 3, FRAME_16x16, 3)\
SPRITE_DEF_END

#include "ZGBMain_Init.h"

#endif