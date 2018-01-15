#ifndef BACKGROUND_H
#define BACKGROUND_H
#include"Obj.h"

class Back
{
public:
	Back() {}
	~Back() {}
	//void Set(float a, float b, float c, float d);
	void Initialize();
	void Set(int stage);
	int Updata(int count,Dot dot);
	void Draw();

private:
	int bgHandle;
	int mapHandle;
	
};

#endif // !BACKGROUND_H
