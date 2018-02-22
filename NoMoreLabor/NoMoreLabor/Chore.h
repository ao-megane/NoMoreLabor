#ifndef CHORE_H
#define CHORE_H
#include"Obj.h"

//雑用的関数をまとめる場所

void DrawLineByDot(Dot a, Dot b,int color);	//2ドット間にcolor色の線を引く関数

bool IsBlack(int imageHandle,Dot dot);	//imageHandleのdot位置の色が黒ければtrueを返す関数

void FpsTimeFanction();	//現在のFPSを計測する関数

double GetFPS();	//現在のFPSを渡す関数

#endif // !CHORE_H
