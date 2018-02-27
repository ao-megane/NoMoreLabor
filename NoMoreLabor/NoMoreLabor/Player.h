#ifndef PLAYER_H
#define PLAYER_H
#include"Obj.h"
#include"Input.h"
#include"Value.h"

//プレイヤー（ボート）の処理を統括するクラス

class Player
{
public:
	Player(){}
	~Player(){}
	void Initialize();		//初期化関数
	void Set(int flag);
	void Updata(Input input,bool Jflag, int count);	//入力や波などに応じた更新関数
	void SetJump(int count);	//ジャンプ状態にする関数
	void UpdataJump(int count);	//ジャンプ状態時の更新関数
	void Draw();			//描画関数
	void End();				//終了関数
	Dot GetCenter();
	Dot GetVelocity();
	Dot GetAccelerator();
	Dot GetForce();
	double GetAng();
	int GetWeight();
	int GetState();

private:
	//Dot precenter;
	Dot center;			//中心座標
	Dot velocity;		//プレイヤーの速度（ベクトル）
	Dot accelerator;	//プレイヤーの加速度（ベクトル）
	Dot force;			//プレイヤーの受ける力のベクトル
	int weight;			//プレイヤーの重さ（受ける力に影響を与える）
	int state;			//プレイヤーの状態を保持する変数　0:normal 1:jumping
	int bodyClock;		//アニメーション用カウント保持変数
	double enlarge;		//アニメーション用画像拡大率
	double ang;			//描画用角度
	int image;			//描画画像ハンドル
};


#endif // !PLAYER_H
