#include "MapCommon.h"
#include "BankManager.h"

UINT16 currentMapWidth = 0;
UINT16 currentMapHeight = 0;
UINT8 currentMapBank = 0;
unsigned char* currentMapPLN0 = 0;
unsigned char* currentMapPLN1 = 0;

UINT8 getDataFromMap(UINT16 tileX, UINT16 tileY, UINT8 plane) {
	UINT8 value;
	unsigned char* currentPlane;

	PushBank(currentMapBank);

	if (plane == 0) {
		currentPlane = currentMapPLN0;
	} else {
		currentPlane = currentMapPLN1;
	}

	currentPlane += tileY * currentMapWidth + tileX;

	//value = currentPlane[tileY * currentMapWidth + tileX];
	value = *currentPlane;

	PopBank();

	return value;
}

void StartMap(UINT16 mapWidth, UINT16 mapHeight, UINT8 mapBank,
	unsigned char* mapPLN0, unsigned char* mapPLN1) {
	
	currentMapWidth = mapWidth;
	currentMapHeight = mapHeight;
	currentMapBank = mapBank;
	currentMapPLN0 = mapPLN0;
	currentMapPLN1 = mapPLN1;
}
