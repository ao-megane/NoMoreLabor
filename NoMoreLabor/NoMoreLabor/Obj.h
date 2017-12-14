#ifndef OBJ_H
#define OBJ_H
#include<math.h>
#include"Value.h"

class Dot
{
public:
	Dot() {}
	~Dot() {}
	void Set(double x, double y);
	void SetX(double a);
	void SetY(double a);
	void SetAbs(float a);
	void SetAng(double a);
	double GetX();
	double GetY();
	double* GetXad();
	double* GetYad();
	float GetAbs();
	double GetAng();
	bool IsHitC(Dot a, int range);
	bool IsHitC(int a, int b, int range);
	void Updata();
	void Draw(int color);
	Dot Rotate(double rad);

	Dot operator - (Dot a) {//ドットの平行移動
		Dot RE;
		RE.Set(x - a.x, y - a.y);
		return RE;
	}
	Dot operator - () {
		Dot RE;
		RE.Set(-x, -y);
		return RE;
	}
	Dot operator + (Dot a) {//ドットの平行移動
		Dot RE;
		RE.Set(x + a.x, y + a.y);
		return RE;
	}
	void operator = (Dot a) {
		x = a.x;
		y = a.y;
		abs = a.abs;
		ang = a.ang;
	}
	Dot operator * (int a) {
		Dot RE;
		RE.Set(x *= a, y *= a);
		return RE;
	}
	
private:
	double x;
	double y;
	float abs;
	double ang;	//0~2PI

};

class intDot
{
public:
	intDot(){}
	~intDot(){}
	void Set(int x, int y);
	int GetX();
	int GetY();
	int* GetXad();
	int* GetYad();
	Dot Todouble();

private:
	int x;
	int y;
	float abs;
	double ang;	//0~2PI
};

#endif // !OBJ_H
