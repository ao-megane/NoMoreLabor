#include"DxLib.h"
#include"Obj.h"
#include<math.h>

void Dot::Set(double a, double b) {
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

bool Dot::IsHitC(Dot a,int range) {
	if (((x - a.x)*(x - a.x) + (y - a.y)*(y - a.y)) <= (range * range)) {//“à‘¤
		return true;
	}
	else {
		return false;
	}
}

bool Dot::IsHitC(int a_x,int a_y, int range) {
	if (((x - a_x)*(x - a_x) + (y - a_y)*(y - a_y)) <= (range * range)) {//“à‘¤
		return true;
	}
	else {
		return false;
	}
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

void Dot::Draw(int color) {
	DrawCircle(x, y, 10, color, 1);
}

Dot Dot::Rotate(double rad) {
	Dot ret;
	ret.Set(x*cos(-rad) - y*sin(-rad), x*sin(-rad) + y*cos(-rad));
	ret.Updata();
	return ret;
}

double Dot::innerPro(Dot a) {
	return x*a.x + y*a.y;
}

void Dot::SetX(double a) {
	x = a;
}
void Dot::SetY(double a) {
	y = a;
}
void Dot::SetAbs(float a) {
	abs = a;
}
void Dot::SetAng(double a) {
	ang = a;
}
double Dot::GetX() {
	return x;
}
double Dot::GetY() {
	return y;
}
double* Dot::GetXad() {
	return &x;
}
double* Dot::GetYad() {
	return &y;
}
float Dot::GetAbs() {
	return abs;
}
double Dot::GetAng() {
	return ang;
}

void intDot::Set(int a, int b) {
	x = a;
	y = b;
}

int intDot::GetX() {
	return x;
}

int intDot::GetY() {
	return y;
}

int* intDot::GetXad() {
	return &x;
}

int* intDot::GetYad() {
	return &y;
}

Dot intDot::Todouble() {
	Dot a;
	a.Set(x, y);
	return a;
}