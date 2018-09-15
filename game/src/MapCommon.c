#include "MapCommon.h"
#include "BankManager.h"

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