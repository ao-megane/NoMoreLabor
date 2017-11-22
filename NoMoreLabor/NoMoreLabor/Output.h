#ifndef OUTPUT_H
#define OUTPUT_H
#include"Obj.h"

class Motors
{
public:
	Motors(){}
	~Motors() {}
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

//Motors::Motors(){
//	UP = 0.0;
//	RD = 0.0;
//	LD = 0.0;
//	SPE = 0.0;
//}
//
//Motors::~Motors(){
//	UP = 0.0;
//	RD = 0.0;
//	LD = 0.0;
//	SPE = 0.0;
//}

#endif // !OUTPUT_H
