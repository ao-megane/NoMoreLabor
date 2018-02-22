#ifndef OBJ_H
#define OBJ_H
#include<math.h>
#include"Value.h"

//座標や位置ベクトルとして便利なドットクラスの定義

class Dot
{
public:
	Dot() {}
	~Dot() {}
	void Set(double x, double y);
	void SetX(double a);
	void SetY(double a);
	void SetAbs(float a);
	void SetAng(double a);
	double GetX();
	double GetY();
	double* GetXad();
	double* GetYad();
	float GetAbs();		
	double GetAng();	
	bool IsHitC(Dot a, int range);	//中心a,半径rangeの円内にいればtrueを返す関数
	bool IsHitC(int a, int b, int range);	//
	void Updata();	//直交座標系をもとに極座標系を補足する関数
	void Draw(int color);	//座標にcolor色の円を描画
	double innerPro(Dot a);	//別のDotとの内積
	Dot Rotate(double rad);	//原点を中心にradだけ回転（半時計）

	Dot operator - (Dot a) {	//ドットの平行移動
		Dot RE;
		RE.Set(x - a.x, y - a.y);
		RE.Updata();
		return RE;
	}
	Dot operator - () {			//原点対象なドットへ変換
		Dot RE;
		RE.Set(-x, -y);
		RE.Updata();
		return RE;
	}
	Dot operator + (Dot a) {	//ドットの平行移動
		Dot RE;
		RE.Set(x + a.x, y + a.y);
		RE.Updata();
		return RE;
	}
	void operator = (Dot a) {	//ドットの代入
		x = a.x;
		y = a.y;
		abs = a.abs;
		ang = a.ang;
	}
	Dot operator * (int a) {	//スカラ倍の定義
		Dot RE;
		RE.Set(x *= a, y *= a);
		RE.Updata();
		return RE;
	}
	Dot operator * (double a) {	//スカラ倍の定義
		Dot RE;
		RE.Set(x *= a, y *= a);
		RE.Updata();
		return RE;
	}
	bool operator != (Dot a) {	//別のDotと一致していればfalse
		if (a.x == x && a.y == y) return false;
		return true;
	}
	
private:
	double x;	//直交座標系のx座標
	double y;	//直交座標系のy座標
	float abs;	//極座標系の絶対値
	double ang;	//極座標系の角度　0～2PI

};

//Dotクラスをintへ拡張したもの、マウス用
class intDot
{
public:
	intDot(){}
	~intDot(){}
	void Set(int x, int y);
	int GetX();
	int GetY();
	int* GetXad();
	int* GetYad();
	Dot Todouble();

private:
	int x;
	int y;
	float abs;
	double ang;	//0~2PI
};

#endif // !OBJ_H
