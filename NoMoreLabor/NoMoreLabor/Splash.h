#ifndef SPLASH_H
#define SPLASH_H
#include"Obj.h"
#include"Value.h"

//飛沫（プレイヤーの影的扱い）関係を統括するクラス

class Splash
{
public:
	Splash() {}
	~Splash() {}
	void Initialize();		//初期化関数
	void Set(int count,Dot center,double ang);	//飛沫のセット関数
	int Updata(int count);	//更新関数
	void Draw();			//描画関数
	bool GetisExist();		//存在するか否かを返す関数

private:
	//プレイヤーと同様な変数
	Dot center;
	double ang;
	int bodyClock;
	bool isExist;
	double enlarge;
	double alpha;	//透明度
};

void SplashMngInitialize();	//Splashをまとめて初期化する関数
void SplashMngUpdata(int count,Dot p_center,double p_ang,int p_state);	//Splashをまとめて更新する関数
void SplashMngDraw();		//Splashをまとめて描画する関数
void SplashMngEnd();		//Splashをまとめて終了する関数

#endif // !SPLASH_H
