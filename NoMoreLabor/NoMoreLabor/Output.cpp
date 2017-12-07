#include"Output.h"
#include"DxLib.h"
#include"Value.h"
#include"math.h"

void Motors::Set(float a, float b, float c) {
	UP = a;
	RD = b;
	LD = c;
}

void Motors::Calc(Dot f) {//fは位置ベクトル
	double decoi;
	f = f.Rotate(8.5*PI / 180.0);
	decoi = 1.0 / F_ABS_MAX;
	//decoi = f.abs / DISP_WIDTH / 2;

	if ((0 <= f.GetAng() && f.GetAng() <= PI / 2.0) || (11.0 / 6.0 * PI <= f.GetAng() && f.GetAng() <= 2.0 * PI)) {
		UP = decoi * (-f.GetY() + f.GetX() / rootThree);
		RD = decoi * 2 / rootTwo*f.GetX();
		LD = 0.0;
	}
	else if (PI / 2.0 <= f.GetAng() && f.GetAng() <= 7.0 / 6.0 * PI) {
		UP = decoi * (-f.GetY() - f.GetX() / rootThree);
		RD = 0.0;
		LD = decoi * 2 / rootTwo*(-f.GetX());
	}
	else if (7.0 / 6.0 * PI <= f.GetAng() && f.GetAng() <= 11.0 / 6.0 * PI) {
		UP = 0.0;
		RD = decoi * (-f.Rotate(2.0/3.0*PI).GetY() + f.Rotate(2.0/3.0*PI).GetX() / rootThree);
		LD = decoi * 2 / rootTwo*f.Rotate(2.0 / 3.0*PI).GetX();
	}
}

const int r = 200;
void Motors::Draw() {
	DrawCircle(DISP_WIDTH / 2.0, DISP_HEIGHT / 2.0 - r, UP * 100.0, RED, true);
	DrawCircle(DISP_WIDTH / 2.0 + r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, RD * 100.0, RED, true);
	DrawCircle(DISP_WIDTH / 2.0 - r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, LD * 100.0, RED, true);

	DrawFormatString(0, 300, GREEN, "UP : %f", UP);
	DrawFormatString(0, 320, GREEN, "RD : %f", RD);
	DrawFormatString(0, 340, GREEN, "LD : %f", LD);

	DrawLine(DISP_WIDTH / 2.0, DISP_HEIGHT / 2.0 - r, DISP_WIDTH / 2.0 + r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, GREEN);
	DrawLine(DISP_WIDTH / 2.0 + r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, DISP_WIDTH / 2.0 - r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, GREEN);
	DrawLine(DISP_WIDTH / 2.0, DISP_HEIGHT / 2.0 - r, DISP_WIDTH / 2.0 - r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, GREEN);
}