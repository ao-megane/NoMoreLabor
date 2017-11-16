#ifndef OBJ_H
#define OBJ_H
#include<math.h>
#include"Value.h"

class Dot
{
public:
	/*Dot();
	~Dot();*/
	int x;
	int y;
	float abs;
	double ang;	//0~2PI

	void Set(int x, int y);
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

};

//Dot::Dot()
//{
//}
//
//Dot::~Dot()
//{
//}

#endif // !OBJ_H
