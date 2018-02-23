#include"Output.h"
#include"DxLib.h"
#include"Value.h"
#include"Chore.h"
#include"math.h"
#include "SpidarMouse.h" //SpidarMouseのヘッドを読み込む
#pragma comment (lib, "SpidarMouse.lib") //SpidarMouseのライブラリを読み込む

void Motors::Initialize() {
	if (OpenSpidarMouse() != 1){
		printfDx("No Connect");
	}
	else {
		printfDx("Connecting!");
	}
	UP = 0.0;
	RD = 0.0;
	LD = 0.0;
	SPE = 0.0;
	SetMinForceDuty(0.0);
}

void Motors::Set(float a, float b, float c) {
	UP = a;
	RD = b;
	LD = c;

	//各モーターの値が定義域を外れないよう設定
	if (UP > 1.0) UP = 1.0; if (UP < 0) UP = 0.0;
	if (RD > 1.0) RD = 1.0; if (RD < 0) RD = 0.0;
	if (LD > 1.0) LD = 1.0; if (LD < 0) LD = 0.0;
	if (SPE > 1.0) SPE = 1.0; if (SPE < 0) SPE = 0.0;
}
void Motors::SetSPE(float a) {
	SPE = a;
	if (SPE > 1.0) SPE = 1.0; if (SPE < 0) SPE = 0.0;
}

void Motors::Calc(Dot f,int playerState) {//fは力の位置ベクトル
	double decoi;
	decoi = 1.0 / F_ABS_MAX;//感度

	//各パターンについてベクトル合成の反対の処理、感度をかけることで良応答にしたい
	if ((0 <= f.GetAng() && f.GetAng() <= PI / 2.0) || (11.0 / 6.0 * PI <= f.GetAng() && f.GetAng() <= 2.0 * PI)) {
		UP = decoi * (f.GetAbs() * sin(f.GetAng()) + f.GetAbs() * cos(f.GetAng()) / rootThree);
		RD = decoi * 2.0 / rootThree * f.GetAbs() * cos(f.GetAng());
		LD = 0.0;
	}
	else if (PI / 2.0 <= f.GetAng() && f.GetAng() <= 7.0 / 6.0 * PI) {
		UP = decoi * (f.GetAbs() * sin(f.GetAng()) + f.GetAbs() * -cos(f.GetAng()) / rootThree);
		RD = 0.0;
		LD = -decoi * 2.0 / rootThree * f.GetAbs() * cos(f.GetAng());
	}
	else if (7.0 / 6.0 * PI <= f.GetAng() && f.GetAng() <= 2.0 * PI) {
		UP = 0.0;
		RD = decoi * (2.0 / rootThree * f.GetAbs() * cos(f.GetAng()) + -f.GetAbs()*(cos(f.GetAng()) / rootThree + sin(f.GetAng())));
		LD = decoi * -f.GetAbs()*(cos(f.GetAng()) / rootThree + sin(f.GetAng()));
	}
	if (playerState == 1) SPE = 0.7; else SPE = 0;	//ジャンプ時

	if (UP > 1.0) UP = 1.0; if (UP < 0) UP = 0.0;
	if (RD > 1.0) RD = 1.0; if (RD < 0) RD = 0.0;
	if (LD > 1.0) LD = 1.0; if (LD < 0) LD = 0.0;
	if (SPE > 1.0) SPE = 1.0; if (SPE < 0) SPE = 0.0;
}

const int r = 200;
const double R = 200.0;
void Motors::Updata(bool flag) {
	SetDutyOnCh(UP, RD, LD, SPE, 1000.0 / GetFPS());	//フレーム間で出力が終わるように間隔を設定（PWMの回避）

	if (flag) {
		SetDutyOnCh(UP, RD, LD, SPE, 1000.0 / GetFPS());
		DrawFormatString(0, 280, GREEN, "SetDutyOnCh(UP, RD, LD, SPE, 1000.0 / GetFPS());");
	}
	else {
		SetDutyOnCh(RD, LD, SPE, UP, 1000.0 / GetFPS());
		DrawFormatString(0, 280, GREEN, "SetDutyOnCh(RD, LD, SPE, UP, 1000.0 / GetFPS());");
	}

	//デバック用表示
	DrawFormatString(0, 300, GREEN, "UP : %f", UP);
	DrawFormatString(0, 320, GREEN, "RD : %f", RD);
	DrawFormatString(0, 340, GREEN, "LD : %f", LD);
	DrawFormatString(0, 360, GREEN, "SPE: %f", SPE);
	DrawFormatString(0, 380, GREEN, "DUR: %f", 1000.0 / GetFPS());
	//SetDutyOnCh(UP, RD, LD, SPE, 22);
}
void Motors::Draw() {

	//正三角形上に見やすく描画
	DrawCircle(DISP_WIDTH / 2.0					   , DISP_HEIGHT / 2.0 - r		, UP * R, RED, true);
	DrawCircle(DISP_WIDTH / 2.0 + r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, RD * R, RED, true);
	DrawCircle(DISP_WIDTH / 2.0 - r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, LD * R, RED, true);

	DrawLine(DISP_WIDTH / 2.0, DISP_HEIGHT / 2.0 - r, DISP_WIDTH / 2.0 + r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, GREEN);
	DrawLine(DISP_WIDTH / 2.0 + r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, DISP_WIDTH / 2.0 - r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, GREEN);
	DrawLine(DISP_WIDTH / 2.0, DISP_HEIGHT / 2.0 - r, DISP_WIDTH / 2.0 - r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, GREEN);
}

void Motors::End() {
	CloseSpidarMouse();
}