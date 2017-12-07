#include "DxLib.h"
#include"Chore.h"
#include"Obj.h"
#include"Input.h"
#include"Output.h"
#include"Value.h"

typedef struct {
	int x, y;
	char name[128];
} MenuElement_t;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	SetGraphMode(DISP_WIDTH, DISP_HEIGHT, 32);
	SetWindowSizeExtendRate(0.7);
	ChangeWindowMode(true);
	SetDrawScreen(DX_SCREEN_BACK);
	DxLib_Init();	// DXライブラリ初期化処理

	Input input;
	Dot center;
	Dot decoi;
	Dot m;
	Motors motor;
	center.Set(DISP_WIDTH / 2, DISP_HEIGHT / 2);
	
	MenuElement_t MenuElement[3] = {
		{ 100,300,"スタート1(仮)" },
		{ 200,500,"スタート2(仮)" },
		{ 200,700,"終了" },
	};

	int stageFlag = 0;	//現在の選択番号（モード）
	int sceFlag = 0;	//シミュレータの流れを管理する変数

	/*-------------フォント設定-------------------*/
	int tanuki;			//フォント設定
	if (AddFontResourceEx("Font/TanukiMagic.ttf", FR_PRIVATE, NULL) == 0) {
		printfDx("AddFontResource");
	}
	tanuki = CreateFontToHandle("たぬき油性マジック", 100, 9, DX_FONTTYPE_ANTIALIASING_8X8);
	if (tanuki == -1) {
		printfDx("CreateFontToHandle");
	}
	/*----------------ここまで---------------------*/

	//while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
	//	input.Updata();

	//	switch (sceFlag){//シミュレータの流れを管理するスイッチ
	//	case 0://タイトル
	//		//計算
	//		if (input.GetKey(KEY_INPUT_DOWN) == 1) {
	//			stageFlag = (stageFlag + 1) % 3;
	//		}
	//		if (input.GetKey(KEY_INPUT_UP) == 1) {
	//			stageFlag = (stageFlag + 2) % 3;
	//		}
	//		if (input.GetKey(KEY_INPUT_ESCAPE) == 1) {
	//			stageFlag = 2;
	//			MenuElement[0].x = 200;
	//			MenuElement[1].x = 200;
	//			MenuElement[2].x = 100;
	//		}

	//		if (input.GetKey(KEY_INPUT_DOWN) == 1 || input.GetKey(KEY_INPUT_UP) == 1) {
	//			for (int i = 0; i < 3; i++) {
	//				if (i == stageFlag) {
	//					MenuElement[i].x = 100;
	//				}
	//				else {
	//					MenuElement[i].x = 200;
	//				}
	//			}
	//		}
	//		
	//		if (input.GetClick() == 1) sceFlag = stageFlag;

	//		break;
	//	case 1://リアルモード
	//		break;
	//	case 2://アンリアルモード
	//		break;
	//	case 3://クレジット
	//		break;
	//	case 4://終了
	//		break;
	//	default:
	//		break;
	//	}
	//	
	//	//描画
	//	for (int i = 0; i < 3; i++) {
	//		//DrawFormatString(MenuElement[i].x, MenuElement[i].y, GetColor(225, 225, 225), MenuElement[i].name);
	//		DrawStringToHandle(MenuElement[i].x, MenuElement[i].y, MenuElement[i].name, GetColor(225, 225, 225), tanuki);
	//	}
	//	if (CheckHitKey(KEY_INPUT_DELETE)) break;
	//}
	/*------------------------------------------------------------------------------------------------------------------------------------------------*/
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		
		decoi = (input.GetMouse() - center);
		decoi.Updata();

		motor.Calc(decoi);

		DrawMouse(m);
		DrawMouse(decoi.Rotate(PI / 2);
		motor.Draw();
		DrawLineByDot(input.GetMouse(), center, BLUE);
		DrawCircle(center.GetX(), center.GetY(), 3, RED, true);
		
	}

	
	DxLib_End();	// DXライブラリ終了処理
	return 0;
}