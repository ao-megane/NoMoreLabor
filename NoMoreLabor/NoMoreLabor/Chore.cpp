#include"DxLib.h"
#include"Obj.h"
#include"Value.h"

void DrawLineByDot(Dot a, Dot b,int color) {
	DrawLine(a.GetX(), a.GetY(), b.GetX(), b.GetY(), color, false);
}

bool isBlack(int imageHandle, Dot dot) {//imageHandle‚Ìdot(À•W)‚ª•‚È‚çtrue‚ğ•Ô‚·
									    //dot.GetX();dot.GetY();
	int imagehandle = 0, *r = 0, *g = 0, *b = 0;

	GetPixelSoftImage(imagehandle, dot.GetX(), dot.GetY(), r, g, b, 0);
	if (*r == 0 && *g == 0 && *b == 0) {
		return true;
	}
	else {
		return false;
	}
}
