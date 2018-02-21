#include"DxLib.h"
#include"Chore.h"
#include"Obj.h"
#include"Input.h"
#include"Output.h"
#include"Value.h"
#include"Player.h"
#include"BackGround.h"
#include"Wave.h"
#include"Splash.h"

typedef struct {
	int x, y;
	char name[128];
} MenuElement_t;

/*
TODO
画像漁りorお絵かき
プレイヤー、操作性改善
力の調整
波クラスの実装
*/

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	SetGraphMode(DISP_WIDTH, DISP_HEIGHT, 32);
	{
		SetWindowSizeExtendRate(0.7);
		ChangeWindowMode(true);
	}
	SetDrawScreen(DX_SCREEN_BACK);
	DxLib_Init();	// DXライブラリ初期化処理

	Input input;
	Dot center;
	Dot decoi;
	Player player;
	Motors motor;
	intDot mdot;
	Back back;
	Wave wave;
	mdot.Set(M_X, M_Y);
	int Jflag;
	int count = 0;
	int flag = 0;
	float yunkawa = 0;
	MenuElement_t MenuElement[3] = {
		{ 100, 300, "水上バイクシミュレータ" },
		{ 200,500,"ハードテスト" },
		{ 200,700,"終了" },
	};
	center.Set(DISP_WIDTH / 2, DISP_HEIGHT / 2);
	

	int stageFlag = 0;	//現在の選択番号（モード）
	int sceFlag = 0;	//シミュレータの流れを管理する変数

	/*-------------フォント設定-------------------*/
	int tanuki;			//フォント設定
	if (AddFontResourceEx("font/TanukiMagic.ttf", FR_PRIVATE, NULL) == 0) {
		//printfDx("AddFontResource");
	}
	tanuki = CreateFontToHandle("たぬき油性マジック", 100, 9, DX_FONTTYPE_ANTIALIASING_8X8);
	if (tanuki == -1) {
		//printfDx("CreateFontToHandle");
	}
	/*----------------ここまで---------------------*/

	motor.Initialize();
	player.Initialize();
	back.Initialize();
	wave.Initialize();
	SplashMngInitialize();

	Jflag = 0;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		input.Updata();
		motor.Updata();

		switch (sceFlag) {//シミュレータの流れを管理するスイッチ
		case 0://タイトル
			//計算
			if (input.GetKey(KEY_INPUT_S) == 1) {
				stageFlag = (stageFlag + 1) % 3;
			}
			if (input.GetKey(KEY_INPUT_W) == 1) {
				stageFlag = (stageFlag + 2) % 3;
			}
			for (int i = 0; i < 3; i++) {
				if (i == stageFlag) {
					MenuElement[i].x = 100;
				}
				else {
					MenuElement[i].x = 200;
				}
			}

			if (input.GetClick() == 1 || input.GetKey(KEY_INPUT_RETURN)) {
				back.Set(0);
				count = 0;
				sceFlag = stageFlag + 1;
				if(sceFlag == 1) SetMousePoint(M_X, M_Y);
			}

			for (int i = 0; i < 3; i++) {
				DrawStringToHandle(MenuElement[i].x, MenuElement[i].y, MenuElement[i].name, GetColor(225, 225, 225), tanuki);
			}
			break;
		case 1://水上バイク
			wave.Set(count);
			wave.Updata(count);
			player.Updata(input, wave.IsJump(player.GetCenter()),count);
			SplashMngUpdata(count, player.GetCenter(), player.GetAng(),player.GetState());
			decoi = (input.GetMouse().Todouble() - center);
			decoi.Updata();
			motor.Calc(decoi,player.GetState());
			back.Draw();
			if (!input.GetMouse().Todouble().IsHitC(M_X, M_Y, M_RANGE)) {
				DrawFormatString(0, 50, RED, "OUT!");
			}
			if (!back.Updata(count, player.GetCenter())) {
				DrawFormatString(0, 100, BLUE, "OUT!");
			}


			input.GetMouse().Todouble().Draw(RED);
			wave.Draw();
			SplashMngDraw();
			player.Draw();
			//motor.Draw();
			//DrawLineByDot(center, input.GetMouse().Todouble(), GREEN);
			//DrawLineByDot(mdot.Todouble(), (mdot.Todouble() + -(player.GetVelocity()).Rotate(player.GetAng())*5), GREEN);
			DrawLineByDot(mdot.Todouble(), (mdot.Todouble() + -player.GetForce()), GREEN);
			DrawCircle(center.GetX(), center.GetY(), 3, RED, true);
			DrawCircle(M_X, M_Y, M_RANGE, BLUE, false);

			break;
		case 2://ハードテスト
			
			//input.Updata();
			if (input.GetKey(KEY_INPUT_W) == 1) flag = 0;
			if (input.GetKey(KEY_INPUT_A) == 1) flag = 1;
			if (input.GetKey(KEY_INPUT_D) == 1) flag = 2;
			if (input.GetKey(KEY_INPUT_S) == 1) {
				SetMousePoint(DISP_WIDTH / 2.0, DISP_HEIGHT / 2.0);
				motor.Set(0, 0, 0);
				yunkawa = 0;
				flag = 3;
			}
			if (input.GetKey(KEY_INPUT_UP)) yunkawa += 0.01;
			if (input.GetKey(KEY_INPUT_DOWN)) yunkawa -= 0.01;
			if (yunkawa < 0) yunkawa = 0;

			switch (flag)
			{
			case 0:
				motor.Set(yunkawa, 0, 0);
				break;
			case 1:
				motor.Set(0, 0, yunkawa);
				break;
			case 2:
				motor.Set(0, yunkawa, 0);
				break;
			case 3:
				decoi = (input.GetMouse().Todouble() - center);
				decoi.Updata();
				motor.Calc(decoi,0);
				DrawLineByDot(center, input.GetMouse().Todouble(), GREEN);
				if (input.GetClick() > 0) motor.SetSPE(0.7);
				break;
			default:
				break;
			}
			motor.Draw();
			break;
		case 3://クレジット
			break;
		case 4://終了
			break;
		default:
			break;
		}

		FpsTimeFanction();
		if (input.GetKey(KEY_INPUT_DELETE) == 1) {
			if (sceFlag == 0) {
				break;
			}
			else {
				sceFlag = 0;
			}
		}
		count++;
	}
	motor.End();
	InitSoftImage();
	DxLib_End();	// DXライブラリ終了処理
	return 0;
}