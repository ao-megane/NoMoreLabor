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
	void SetSPE(float a);
	void Calc(Dot F,int playerState);
	void Draw();
	void End();

private:
	float UP;
	float RD;
	float LD;
	float SPE;
};

#endif // !OUTPUT_H
