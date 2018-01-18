#include"BackGround.h"
#include"Chore.h"

int bgHandle1;
int mapHandle1;
int softmapHandle1;
int mapHandle2;

void Back::Initialize() {
	bgHandle1 = LoadGraph("images/map/BackGround.png");
	mapHandle1 = LoadGraph("images/map/map1.png");
	softmapHandle1 = LoadSoftImage("images/map/map1.png");

}

void Back::Set(int stage) {
	switch (stage)
	{
	case 0:
		bgHandle = bgHandle1;
		mapHandle = mapHandle1;
		softmapHandle = softmapHandle1;
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
	softmapHandle = softmapHandle1;
}

int Back::Updata(int count,Dot dot) {
	if (IsBlack(softmapHandle, dot)) {
		return 1;
	}
	else {
		return 0;
	}
	//return 1;
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