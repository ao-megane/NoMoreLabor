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

	if ((0 <= f.ang && f.ang <= PI / 2.0) || (11.0 / 6.0 * PI <= f.ang && f.ang <= 2.0 * PI)) {
		UP = decoi * (-f.y + f.x / rootThree);
		RD = decoi * 2 / rootTwo*f.x;
		LD = 0.0;
	}
	else if (PI / 2.0 <= f.ang && f.ang <= 7.0 / 6.0 * PI) {
		UP = decoi * (-f.y - f.x / rootThree);
		RD = 0.0;
		LD = decoi * 2 / rootTwo*(-f.x);
	}
	else if (7.0 / 6.0 * PI <= f.ang && f.ang <= 11.0 / 6.0 * PI) {
		UP = 0.0;
		RD = decoi * (-f.Rotate(2.0/3.0*PI).y + f.Rotate(2.0/3.0*PI).x / rootThree);
		LD = decoi * 2 / rootTwo*f.Rotate(2.0 / 3.0*PI).x;
	}
}

const int r = 200;
void Motors::Draw() {
	DrawCircle(DISP_WIDTH / 2.0, DISP_HEIGHT / 2.0 - r, UP * 50.0, RED, true);
	DrawCircle(DISP_WIDTH / 2.0 + r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, RD * 50.0, RED, true);
	DrawCircle(DISP_WIDTH / 2.0 - r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, LD * 50.0, RED, true);

	DrawFormatString(0, 300, GREEN, "UP : %f", UP);
	DrawFormatString(0, 320, GREEN, "RD : %f", RD);
	DrawFormatString(0, 340, GREEN, "LD : %f", LD);

	DrawLine(DISP_WIDTH / 2.0, DISP_HEIGHT / 2.0 - r, DISP_WIDTH / 2.0 + r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, GREEN);
	DrawLine(DISP_WIDTH / 2.0 + r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, DISP_WIDTH / 2.0 - r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, GREEN);
	DrawLine(DISP_WIDTH / 2.0, DISP_HEIGHT / 2.0 - r, DISP_WIDTH / 2.0 - r*rootThree / 2.0, DISP_HEIGHT / 2.0 + r / 2.0, GREEN);
}