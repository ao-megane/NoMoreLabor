#ifndef INPUT_H
#define INPUT_H
#include"Obj.h"
#include"Value.h"

//入力全てを統括するクラス
class Input
{
public:
	Input() {}
	~Input() {}
	void MouseUpdata();	//マウスの更新関数
	void KeyUpdata();	//キーボードの更新関数
	void Updata();		//上のふたつをまとめて行う関数
	int GetKey(int code);	//あるキーボードの入力状態を渡す関数
	int GetClick();		//クリックの入力状態を渡す関数
	intDot GetMouse();	//マウスの座標を渡す関数
	void DrawMouse();	//マウスの座標の描画
	void DrawKey();		//キーボード（十字キー）の入力状態の描画
private:
	intDot m;		//マウスの処理用座標
	int click;		//クリックの状態保持用変数
	int key[256];	//各キーの状態保存用変数
};

#endif // !INPUT_H
