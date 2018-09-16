
#include <gb/gb.h>

typedef struct LaserInfo {
    // 0 is faceing left, clockwise up to 3
    // 4 is facing up left, clockwise up to 7
	INT8 targetDirection;
    INT8 currentDirection;
    INT8 targetLaserState;
    INT8 currentLaserState;
} LaserInfo;
