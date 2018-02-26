#include"BackGround.h"
#include"Chore.h"

/*-------------各画像格納用変数-------------------*/
int bgHandle1;
int mapHandle1;
int softmapHandle1;
//int mapHandle2;

void Back::Initialize() {
	/*-------------各画像の格納-------------------*/
	bgHandle1 = LoadGraph("images/map/BackGround.png");
	mapHandle1 = LoadGraph("images/map/map1.png");
	softmapHandle1 = LoadSoftImage("images/map/softmap1.png");

}

void Back::Set(int stage) {
	switch (stage)
	{
	case 0:
		bgHandle = bgHandle1;
		mapHandle = 0;
		break;
	case 1://ステージ１（）に応じた画像を格納
		bgHandle = bgHandle1;
		mapHandle = mapHandle1;
		softmapHandle = softmapHandle1;
		break;
	case 2:
		break;
	default:
		break;
	}
}

int Back::Updata(int count,Dot dot) {
	if (IsBlack(softmapHandle, dot)) {//もしソフトマップハンドルに渡した画像のdot(座標)位置の点が黒ければ
		return 1;	//trueを返す
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