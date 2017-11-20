#ifndef OBJ_H
#define OBJ_H
#include<math.h>
#include"Value.h"

class Dot
{
public:
	Dot();
	~Dot();
	void Set(int x, int y);
	void SetX(int a);
	void SetY(int a);
	void SetAbs(float a);
	void SetAng(double a);
	int GetX();
	int GetY();
	float GetAbs();
	double GetAng();
	void Updata();
	Dot Rotate(double rad);

	Dot operator - (Dot a) {//ドットの平行移動
		Dot RE;
		RE.Set(x - a.x, y - a.y);
		return RE;
	}
	void operator = (Dot a) {
		x = a.x;
		y = a.y;
		abs = a.abs;
		ang = a.ang;
	}
	
private:
	int x;
	int y;
	float abs;
	double ang;	//0~2PI

};

Dot::Dot()
{
}

Dot::~Dot()
{
}

#endif // !OBJ_H
