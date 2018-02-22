#ifndef BACKGROUND_H
#define BACKGROUND_H
#include"Obj.h"

//背景全てを統括するクラス
class Back
{
public:
	Back() {}
	~Back() {}
	//void Set(float a, float b, float c, float d);
	void Initialize();	//初期化関数
	void Set(int stage);	//ステージに応じた背景をセット
	int Updata(int count,Dot dot);	
		//時間経過による変化の反映、ある点のコースの安否を返す関数
	void Draw();	//描画関数

private:
	int bgHandle;		//背景画像ハンドル
	int mapHandle;		//コース画像ハンドル
	int softmapHandle;	//ソフトマップハンドル
	
};

#endif // !BACKGROUND_H
