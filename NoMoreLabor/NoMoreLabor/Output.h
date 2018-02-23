#ifndef OUTPUT_H
#define OUTPUT_H
#include"Obj.h"

//出力（Motor）を統括するクラス、Spidermouseはここでしか使わない

class Motors
{
public:
	Motors(){}
	~Motors() {}
	//void Set(float a, float b, float c, float d);
	void Initialize();		//初期化関数
	void Set(float u, float r, float l);	//上、右下、左下の設定関数（0～1.0）
	void SetSPE(float a);	//special（Jump）用セッター関数
	void Calc(Dot F,int playerState);	//力ベクトルやplayerの状態（ジャンプ）に応じて各モーターの値を計算、格納する関数
	void Updata(bool flag);			//各モーターへ反映する関数
	void Draw();			//描画関数
	void End();				//終了関数

private:
	float UP;	//上方向のモーター出力
	float RD;	//右下方向のモーター出力
	float LD;	//左下方向のモーター出力
	float SPE;	//ジャンプ用モーター出力
};

#endif // !OUTPUT_H
