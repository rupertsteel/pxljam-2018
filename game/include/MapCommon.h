
#include <gb/gb.h>

extern UINT16 currentMapWidth;
extern UINT16 currentMapHeight;
extern UINT8 currentMapBank;
extern unsigned char* currentMapPLN0;
extern unsigned char* currentMapPLN1;

UINT8 getDataFromMap(UINT16 tileX, UINT16 tileY, UINT8 plane);
