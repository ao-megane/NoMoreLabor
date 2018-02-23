#ifndef WAVE_H
#define WAVE_H
#include"Obj.h"
#include"Value.h"

//波に関する処理を統括するクラス

class Wave
{
public:
	Wave() {}
	~Wave() {}
	void Initialize();		//初期化関数
	void Set(int count);	//セッター関数
	int Updata(int count);	//更新関数
	void Draw();			//描画関数
	bool IsJump(Dot center);//centerが波の中にいればtrue

private:
	Dot Point1;	//
	Dot Point2;
	bool dir_x;//波の進む方向がx軸方向ならtrue
	double ang;
	int image;
};

#endif // !WAVE_H
