#include"DxLib.h"
#include"Obj.h"
#include"Value.h"

void DrawLineByDot(Dot a, Dot b,int color) {
	DrawLine(a.GetX(), a.GetY(), b.GetX(), b.GetY(), color, false);
}

bool IsSafeInMap(Dot player, int imagehandle) {

	if (out) {
		return false;
	}
	else {
		return true;
	}
}
