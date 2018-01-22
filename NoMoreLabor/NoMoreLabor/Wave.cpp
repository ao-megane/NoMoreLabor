#include"DxLib.h"
#include"Value.h"
#include"Obj.h"
#include"Wave.h"


int normal_image;

void Wave::Initialize() {
	normal_image = LoadGraph("images/wave/normal.png");
	image = normal_image;
}

void Wave::Set(int count) {
	if (count % WAVE_INTERVAL != 0)
		return;
	SRand(GetNowCount());
	if (GetRand(1)) {
		dir_x = true;
	}
	else {
		dir_x = false;
	}
	Point1.Set(0, 0);
	if (dir_x)
		Point2.Set(-GetRand(WAVE_SPEED * WAVE_INTERVAL), DISP_HEIGHT);
	else
		Point2.Set(DISP_WIDTH, -GetRand(WAVE_SPEED * WAVE_INTERVAL));
	if (Point2.GetX() == 0) ang = 0;
	else ang = -atan2(Point2.GetY(), Point2.GetX());
	while (ang >= PI * 2)
		ang -= 2 * PI;
	while (ang < 0)
		ang += 2 * PI;
}

int Wave::Updata(int count) {
	if (dir_x) {
		Point1.SetX(Point1.GetX() + WAVE_SPEED);
		Point2.SetX(Point2.GetX() + WAVE_SPEED);
	}
	else {
		Point1.SetY(Point1.GetY() + WAVE_SPEED);
		Point2.SetY(Point2.GetY() + WAVE_SPEED);
	}
}

Dot a;
Dot b;
Dot c;
Dot d;
Dot decoi;
void Wave::Draw() {
	decoi.Set(-WAVE_BAND / 2,0);
	a = decoi.Rotate(ang) + Point1;
	decoi.Set(+WAVE_BAND / 2, 0);
	b = decoi.Rotate(ang) + Point1;
	decoi.Set(+WAVE_BAND/2,0);
	c = decoi.Rotate(ang) + Point2;
	decoi.Set(-WAVE_BAND/2,0);
	d = decoi.Rotate(ang) + Point2;
	DrawModiGraph(
		a.GetX(), a.GetY(),
		b.GetX(), b.GetY(),
		c.GetX(), c.GetY(),
		d.GetX(), d.GetY(),
		image, true
		);
}