#include"BackGround.h"

int bgHandle1;
int mapHandle1;
int mapHandle2;

void Back::Initialize() {
	bgHandle1 = LoadGraph("images/map/BackGround.png");
	mapHandle1 = LoadGraph("images/map/map1.png");
}

void Back::Set(int stage) {
	switch (stage)
	{
	case 0:
		bgHandle = bgHandle1;
		mapHandle = mapHandle1;
		break;
	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}
	bgHandle = bgHandle1;
	mapHandle = mapHandle1;

}

int Back::Updata(int count) {
	return 0;
}

void Back::Draw() {
	DrawModiGraph(
		0, 0,
		DISP_WIDTH, 0,
		DISP_WIDTH, DISP_HEIGHT,
		0, DISP_HEIGHT, bgHandle, true
		);
	DrawModiGraph(
		0, 0,
		DISP_WIDTH, 0,
		DISP_WIDTH, DISP_HEIGHT,
		0, DISP_HEIGHT, mapHandle, true
		);
}