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
	decoi = 1.0 / F_ABS_MAX;

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
}

const int r = 200;
const double R = 200.0;
void Motors::Draw() {
	DrawCircle(DISP_WIDTH / 2.0					   , DISP_HEIGHT / 2.0 - r		, UP * R, RED, true);
	DrawCircle(DISP_WIDTH / 2.0 + r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, RD * R, RED, true);
	DrawCircle(DISP_WIDTH / 2.0 - r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, LD * R, RED, true);

	DrawFormatString(0, 300, GREEN, "UP : %f", UP);
	DrawFormatString(0, 320, GREEN, "RD : %f", RD);
	DrawFormatString(0, 340, GREEN, "LD : %f", LD);

	DrawLine(DISP_WIDTH / 2.0, DISP_HEIGHT / 2.0 - r, DISP_WIDTH / 2.0 + r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, GREEN);
	DrawLine(DISP_WIDTH / 2.0 + r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, DISP_WIDTH / 2.0 - r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, GREEN);
	DrawLine(DISP_WIDTH / 2.0, DISP_HEIGHT / 2.0 - r, DISP_WIDTH / 2.0 - r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, GREEN);
}