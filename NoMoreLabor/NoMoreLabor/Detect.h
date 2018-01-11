#ifndef DETECT_H
#define DETECT_H
#include"Obj.h"

int isBlack(int imageHandle, Dot dot) {//imageHandle‚Ìdot(À•W)‚ª•‚È‚çtrue‚ğ•Ô‚·
	//dot.GetX();dot.GetY();
	int imagehandle,*r, *g, *b;
	
	GetPixelSoftImage(imagehandle, dot.GetX(), dot.GetY(), r, g, b, 0);
	if (*r == 0 && *g == 0 && *b == 0) {
		return 1;//true
	}
	else {
		return 0;//false
	}

}

#endif