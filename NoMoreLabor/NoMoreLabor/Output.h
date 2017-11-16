#ifndef OUTPUT_H
#define OUTPUT_H
#include"Obj.h"

class Motors
{
public:
	/*Motors();
	~Motors();*/
	float UP;
	float RD;
	float LD;
	float SPE;
	void Set(float a, float b, float c, float d);
	void Set(float a, float b, float c);
	void Calc(Dot F);
	void Draw();

private:

};

//Motors::Motors()
//{
//}
//
//Motors::~Motors()
//{
//}

#endif // !OUTPUT_H
