#include"DxLib.h"
#include"Obj.h"
#include"Value.h"

void DrawLineByDot(Dot a, Dot b,int color) {
	DrawLine(a.GetX(), a.GetY(), b.GetX(), b.GetY(), color, false);
}

bool IsBlack(int imageHandle, Dot dot) {
	int r = 0, g = 0, b = 0;

	GetPixelSoftImage(imageHandle, dot.GetX(), dot.GetY(), &r, &g, &b, 0);	//imageHandleのdot(座標)のRGBを格納
	if (r == 0 && g == 0 && b == 0) {	//全て0なら
		return true;
	}
	else {
		return false;
	}
	//return true;
}

void DrawCredit(int font) {
	//DrawBox(0, 0, DISP_WIDTH, DISP_HEIGHT, BLUE, true);
	DrawStringToHandle(250, 100, "CREDIT", BLACK, font);
	DrawStringToHandle(250, 150, "", BLACK, font);
	DrawStringToHandle(250, 200, "ソフト担当", BLACK, font);
	DrawStringToHandle(250, 250, "　4L22 田村 崚", BLACK, font);
	DrawStringToHandle(250, 300, "　4R22 小林 荘太", BLACK, font);
	DrawStringToHandle(250, 350, "　使用ソフト:visualstudio2015,github", BLACK, font);
	DrawStringToHandle(250, 400, "　使用ライブラリ:DxLib", BLACK, font);
	DrawStringToHandle(250, 450, "", BLACK, font);
	DrawStringToHandle(250, 500, "ハード担当", BLACK, font);
	DrawStringToHandle(250, 550, "　4R26 仁平 蒼太郎", BLACK, font);
	DrawStringToHandle(250, 600, "　4L36 渡邉 拓磨", BLACK, font);
	DrawStringToHandle(250, 650, "　使用ソフト:Fusion360", BLACK, font);
	//DrawStringToHandle(450, 700, "CREDIT", BLACK, font);
}

int FpsTime[2] = { 0, }, FpsTime_i = 0;
double Fps = 0.0;
void FpsTimeFanction() {
	if (FpsTime_i == 0)
		FpsTime[0] = GetNowCount();               //1周目の時間取得
	if (FpsTime_i == 49) {
		FpsTime[1] = GetNowCount();               //50周目の時間取得
		Fps = 1000.0f / ((FpsTime[1] - FpsTime[0]) / 50.0f);//測定した値からfpsを計算
		FpsTime_i = 0;//カウントを初期化
	}
	else
		FpsTime_i++;//現在何周目かカウント
	if (Fps != 0)
		//DrawFormatString(DISP_WIDTH - 100, DISP_HEIGHT - 20, RED, "FPS %.1f", Fps); //fpsを表示
	return;
}

double GetFPS() {
	return Fps;
}

