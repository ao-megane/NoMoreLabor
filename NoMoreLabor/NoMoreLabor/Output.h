#ifndef OUTPUT_H
#define OUTPUT_H
#include"Obj.h"

class Motors
{
public:
	Motors(){}
	~Motors() {}
	//void Set(float a, float b, float c, float d);
	void Initialize();
	void Set(float u, float r, float l);
	void Calc(Dot F);
	void Draw();

private:
	float UP;
	float RD;
	float LD;
	float SPE;
};

#endif // !OUTPUT_H
