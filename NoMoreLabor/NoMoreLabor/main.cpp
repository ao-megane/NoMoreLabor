#include "DxLib.h"
#include"Chore.h"
#include"Obj.h"
#include"Input.h"
#include"Output.h"
#include"Value.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	SetGraphMode(DISP_WIDTH, DISP_HEIGHT, 32);
	ChangeWindowMode(true);
	SetDrawScreen(DX_SCREEN_BACK);
	DxLib_Init();	// DXライブラリ初期化処理

	Dot m;
	Dot center;
	Dot decoi;
	Motors motor;

	center.Set(DISP_WIDTH / 2, DISP_HEIGHT / 2);
	motor.Set(0.5, 0.5, 1.0);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		MouseUpdata(&m);
		m.Updata();
		decoi = (m - center);
		decoi.Updata();

		motor.Calc(decoi);

		//DrawMouse(m);
		DrawMouse(decoi);
		motor.Draw();
		DrawLineByDot(m, center, BLUE);
		DrawCircle(center.x, center.y, 3, RED, true);
		if (CheckHitKey(KEY_INPUT_DELETE)) break;
	}

	
	DxLib_End();	// DXライブラリ終了処理
	return 0;
}