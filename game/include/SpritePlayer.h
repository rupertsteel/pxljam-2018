
#include <gb/gb.h>

typedef struct PlayerInfo {
    // 0 is faceing left, clockwise up to 3
    // 4 is facing up left, clockwise up to 7
	UINT8 controller;
    UINT8 hasControl;
    UINT8 near;
} PlayerInfo;
