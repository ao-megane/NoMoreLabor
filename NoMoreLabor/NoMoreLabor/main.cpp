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
*/

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	/*-------------DxLib設定----------------------------------------*/
	SetGraphMode(DISP_WIDTH, DISP_HEIGHT, 32);	//画素数、使用する色の数の設定
	{
		/*-------------ウィンドウモード設定-------------------*/
		SetWindowSizeExtendRate(0.9);	//上で設定したサイズの0.7倍で表示
		ChangeWindowMode(true);			//ウィンドウモードに変更（デフォルトはフルスクリーンモード）
	}
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面処理の設定
	DxLib_Init();	// DXライブラリ初期化処理
	/*-------------DxLib設定了--------------------------------------*/

	/*-------------各種変数設定-------------------------------------------*/
	Input input;	//入力処理
	Dot center;		//描画の中心座標
	center.Set(DISP_WIDTH / 2, DISP_HEIGHT / 2);	//centerをピクセル単位で画面の中心へセット
	Dot decoi;		//各計算の途中の値を持つやつ
	Player player;	//プレイヤー処理
	Motors motor;	//出力（モーター）処理
	//デバック用
		intDot mdot;	//マウス処理
		mdot.Set(M_X, M_Y);	//マウスを既定の位置へセット
		bool setFlag = true;//ポートデバッグ用
	
	Back back;		//背景処理
	Wave wave;		//波処理

	int Jflag = 0;		//プレイヤーのジャンプフラグ
	int count = 0;	//スタートからの経過フレームのカウンタ
	int flag = 0;	//
	bool isCourseOut = false;	//コースアウトであればtrueを返すフラグ
	float power = 0;	//ハードテスト用パラメータ（0〜1.0）
	int sceFlag = 0;	//現在のソフトの状態（OP,PLAYING,ENDING）のフラグ
	int stageFlag = 0;	//OPで使う、現在選択中のステージ（モード）

	MenuElement_t MenuElement[5] = {	//最初の画面の表示文字
		{ SENTENCE_WIDTH - 50, 450, "map1" },
		{ SENTENCE_WIDTH, 500, "map2" },
		{ SENTENCE_WIDTH, 550,"ハードテスト" },
		{ SENTENCE_WIDTH, 600,"CREDIT" },
		{ SENTENCE_WIDTH, 650,"EXIT" },
	};

	/*-------------各種クラスの初期化処理-------------------*/
	motor.Initialize();
	player.Initialize();
	back.Initialize();
	back.Set(0);
	wave.Initialize();
	SplashMngInitialize();

	/*-------------フォントの追加-------------------*/
	int tanuki;
	if (AddFontResourceEx("font/TanukiMagic.ttf", FR_PRIVATE, NULL) == 0) {
		//printfDx("AddFontResource");
	}
	tanuki = CreateFontToHandle("たぬき油性マジック", 50, 9, DX_FONTTYPE_ANTIALIASING_8X8);
	if (tanuki == -1) {
		//printfDx("CreateFontToHandle");
	}
	int bigTanuki;
	bigTanuki = CreateFontToHandle("たぬき油性マジック", 100, 9, DX_FONTTYPE_ANTIALIASING_8X8);
	int smallTanuki;
	smallTanuki = CreateFontToHandle("たぬき油性マジック", 25, 9, DX_FONTTYPE_ANTIALIASING_8X8);
	/*-------------各種変数設定了-------------------------------------------*/

	/*-------------ループ処理------------------------------------------------------------------------------*/
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//表示系やDxLibにエラーがなければ続行
		input.Updata();//入力の更新
		motor.Updata(setFlag);//モーターの更新
		//back.Draw();
		if (input.GetKey(KEY_INPUT_P) == 1) setFlag = !setFlag;

		switch (sceFlag) {//シミュレータの流れを管理するスイッチ
		case 0://タイトル
		{
			//計算
			if (input.GetKey(KEY_INPUT_S) == 1 || input.GetKey(KEY_INPUT_DOWN) == 1) {	//下が押されたら選択を下へ
				if (stageFlag == 4) stageFlag = 0;
				else stageFlag = stageFlag + 1;
			}
			if (input.GetKey(KEY_INPUT_W) == 1 || input.GetKey(KEY_INPUT_UP) == 1) {	//上が押されたら選択を上へ
				if (stageFlag == 0) stageFlag = 4;
				else stageFlag = stageFlag - 1;
			}
			for (int i = 0; i < 5; i++) {
				if (i == stageFlag) {
					MenuElement[i].x = SENTENCE_WIDTH - 50;
				}
				else {
					MenuElement[i].x = SENTENCE_WIDTH;
				}
			}

			if (input.GetClick() == 1 || input.GetKey(KEY_INPUT_RETURN)) {	//クリックかエンターで選択に応じた次の処理へ
				
				count = 0;	//カウンタを初期化
				sceFlag = stageFlag + 1;		//OPの選択表示フラグをシステムの流れフラグへ反映

				motor.Initialize();
				player.Set(sceFlag);
				wave.Initialize();
				SplashMngInitialize();
				back.Set(sceFlag);		//背景の設定（モードにより異なる）
				//SetMousePoint(M_X, M_Y);	//マウス位置の初期化

				if (sceFlag == 5) {
					/*-------------終了処理-------------*/
					motor.End();
					InitSoftImage();
					DxLib_End();	// DXライブラリ終了処理

					return 0;
				}
			}
			back.Draw();
			DrawStringToHandle(100,150, "水上バイクシミュレータ", BLACK, bigTanuki);
			DrawStringToHandle(450, 300, "1班　定時退社", BLACK, tanuki);
			for (int i = 0; i < 5; i++) {	//選択の描画
				if(MenuElement[i].x == SENTENCE_WIDTH - 50)
					DrawStringToHandle(MenuElement[i].x, MenuElement[i].y, MenuElement[i].name, ORANGE, tanuki);
				else
					DrawStringToHandle(MenuElement[i].x, MenuElement[i].y, MenuElement[i].name, BLACK, tanuki);
			}
			break;
		}
		case 1://map1
		{
			/*-------------各クラスの更新-------------------*/
			wave.Set(count);	//カウンタに応じて波をセット
			wave.Updata(count);	//カウンタに応じて波を更新
			player.Updata(input, wave.IsJump(player.GetCenter()), count);	//入力、波等をもとにプレイヤーの更新
			SplashMngUpdata(count, player.GetCenter(), player.GetAng(), player.GetState());	//飛沫の更新（プレイヤーの影のような役割）
			isCourseOut = !back.Updata(count, player.GetCenter());

			/*-------------描画-------------------*/
			back.Draw();
			if (!input.GetMouse().Todouble().IsHitC(M_X, M_Y, M_RANGE)) {
				//DrawFormatString(0, 50, RED, "OUT!");
			}

			//input.GetMouse().Todouble().Draw(RED);
			wave.Draw();
			SplashMngDraw();
			player.Draw();
			DrawCircle(M_X, M_Y, M_RANGE, WHITE, true);
			//motor.Draw();
			//DrawLineByDot(center, input.GetMouse().Todouble(), GREEN);
			//DrawLineByDot(mdot.Todouble(), (mdot.Todouble() + -(player.GetVelocity()).Rotate(player.GetAng())*5), GREEN);
			DrawLineByDot(mdot.Todouble(), (mdot.Todouble() + (-player.GetForce() * (1 / F_ABS_MAX) * M_RANGE)), ORANGE);
			//DrawCircle(center.GetX(), center.GetY(), 3, RED, true);
			
			if (isCourseOut) {
				DrawStringToHandle(100, 100, "コースアウトしています！早く戻りましょう！", RED, tanuki);
			}

			break; 
			}
		case 2://map2(現状ではmap1と同じ処理)
		{
			/*-------------各クラスの更新-------------------*/
			wave.Set(count);	//カウンタに応じて波をセット
			wave.Updata(count);	//カウンタに応じて波を更新
			player.Updata(input, wave.IsJump(player.GetCenter()), count);	//入力、波等をもとにプレイヤーの更新
			SplashMngUpdata(count, player.GetCenter(), player.GetAng(), player.GetState());	//飛沫の更新（プレイヤーの影のような役割）
			isCourseOut = !back.Updata(count, player.GetCenter());

			/*-------------描画-------------------*/
			back.Draw();
			if (!input.GetMouse().Todouble().IsHitC(M_X, M_Y, M_RANGE)) {
				//DrawFormatString(0, 50, RED, "OUT!");
			}

			//input.GetMouse().Todouble().Draw(RED);
			wave.Draw();
			SplashMngDraw();
			player.Draw();
			DrawCircle(M_X, M_Y, M_RANGE, WHITE, true);
			//motor.Draw();
			//DrawLineByDot(center, input.GetMouse().Todouble(), GREEN);
			//DrawLineByDot(mdot.Todouble(), (mdot.Todouble() + -(player.GetVelocity()).Rotate(player.GetAng())*5), GREEN);
			DrawLineByDot(mdot.Todouble(), (mdot.Todouble() + (-player.GetForce() * (1 / F_ABS_MAX) * M_RANGE)), ORANGE);
			//DrawCircle(center.GetX(), center.GetY(), 3, RED, true);

			if (isCourseOut) {
				DrawStringToHandle(100, 100, "コースアウトしています！早く戻りましょう！", RED, tanuki);
			}

			break;
		}
		case 3://ハードテスト
		{
			if (input.GetKey(KEY_INPUT_W) == 1) flag = 0;
			if (input.GetKey(KEY_INPUT_A) == 1) flag = 1;
			if (input.GetKey(KEY_INPUT_D) == 1) flag = 2;
			if (input.GetKey(KEY_INPUT_S) == 1) {
				SetMousePoint(DISP_WIDTH / 2.0, DISP_HEIGHT / 2.0);
				motor.Set(0, 0, 0);
				power = 0;
				flag = 3;
			}
			if (input.GetKey(KEY_INPUT_UP)) power += 0.01;
			if (input.GetKey(KEY_INPUT_DOWN)) power -= 0.01;
			if (power < 0) power = 0;

			switch (flag)
			{
			case 0:
				motor.Set(power, 0, 0);
				break;
			case 1:
				motor.Set(0, 0, power);
				break;
			case 2:
				motor.Set(0, power, 0);
				break;
			case 3:
				decoi = (input.GetMouse().Todouble() - center);
				decoi.Updata();
				motor.Calc(decoi, 0);
				DrawLineByDot(center, input.GetMouse().Todouble(), GREEN);
				if (input.GetClick() > 0) motor.SetSPE(0.7);
				break;
			default:
				break;
			}
			motor.Draw();
			break;
		}
		case 4://クレジット
		{
			back.Draw();
			DrawCredit(tanuki);
			break;
		}
		case 5://終了
			break;
		default:
			break;
		}

		FpsTimeFanction();	//現在のFPSの表示
		if (input.GetKey(KEY_INPUT_DELETE) == 1) {//デリートが押されたら一つ前の画面へ、OP画面ならソフトを終了する
			back.Set(0);
			power = 0;
			if (sceFlag == 0) {
				break;
			}
			else {
				sceFlag = 0;
			}
		}

		if(sceFlag == 0)	//タイトルの時に文面を変える
			DrawStringToHandle(DISP_WIDTH - 150, 0, "DELで閉じる", BLACK, smallTanuki);
		else
			DrawStringToHandle(DISP_WIDTH - 300, 0, "DELで一つ前の画面に戻る", BLACK, smallTanuki);

		count++;	//カウンタの更新
	}
	/*-------------ループ処理ここまで----------------------------------------------------------------------*/
	
	/*-------------終了処理-------------*/
	motor.End();
	InitSoftImage();
	DxLib_End();	// DXライブラリ終了処理

	return 0;
}