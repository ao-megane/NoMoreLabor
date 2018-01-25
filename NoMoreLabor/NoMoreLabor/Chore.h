#ifndef CHORE_H
#define CHORE_H
#include"Obj.h"

void DrawLineByDot(Dot a, Dot b,int color);

bool IsBlack(int imageHandle,Dot dot);

void FpsTimeFanction();

double GetFPS();

#endif // !CHORE_H
