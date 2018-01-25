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
	void Set(int count,Dot center,double ang);
	int Updata(int count);
	void Draw();
	bool GetisExist();

private:
	Dot center;
	double ang;
	int bodyClock;
	bool isExist;
	double enlarge;
	double alpha;
};

void SplashMngInitialize();
void SplashMngUpdata(int count,Dot p_center,double p_ang,int p_state);
void SplashMngDraw();
void SplashMngEnd();

#endif // !SPLASH_H
