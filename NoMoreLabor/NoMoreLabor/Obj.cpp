#include"DxLib.h"
#include"Obj.h"
#include<math.h>

void Dot::Set(int a, int b) {
	x = a;
	y = b;

	abs = sqrt(x*x + y*y);

	if (x < 0) ang = atan(y / x) + PI;
	else if (x == 0 && y >= 0)
		ang = -3 / 2 * PI;
	else if (x == 0 && y <= 0)
		ang = PI / 2;
	else if (x > 0) ang = atan(y / x);
}

void Dot::Updata() {
	abs = sqrt(x*x + y*y);
	double a;
	//y *= -1;
	if (x == 0) 
		if (y == 0) {
			ang = 0;
			return;
		}

	a = atan2(x, y) + 3 * PI / 2;
	if (a > 2 * PI) ang = a - 2 * PI;
		else ang = a;	
}

Dot Dot::Rotate(double rad) {
	Dot ret;
	ret.Set(x*cos(-rad) - y*sin(-rad), x*sin(-rad) + y*cos(-rad));
	ret.Updata();
	return ret;
}

void Dot::SetX(int a) {
	x = a;
}
void Dot::SetY(int a) {
	y = a;
}
void Dot::SetAbs(float a) {
	abs = a;
}
void Dot::SetAng(double a) {
	ang = a;
}
int Dot::GetX() {
	return x;
}
int Dot::GetY() {
	return y;
}
int* Dot::GetXad() {
	return &x;
}
int* Dot::GetYad() {
	return &y;
}
float Dot::GetAbs() {
	return abs;
}
double Dot::GetAng() {
	return ang;
}