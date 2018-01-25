#ifndef SPLASH_H
#define SPLASH_H
#include"Obj.h"
#include"Value.h"

class Splash
{
public:
	Splash() {}
	~Splash() {}
	void Initialize();
	void Set(int count,Dot center,int ang);
	int Updata(int count);
	void Draw();
	bool GetisExist();

private:
	Dot center;
	double ang;
	int bodyClock;
	bool isExist;
	double enlarge;
};

void SplashMngInitialize();
void SplashMngUpdata(int count,Dot p_center,int p_ang);
void SplashMngDraw();
void SplashMngEnd();

#endif // !SPLASH_H
