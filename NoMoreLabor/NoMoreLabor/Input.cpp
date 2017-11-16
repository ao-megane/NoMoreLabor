#include"DxLib.h"
#include"Value.h"
#include"Obj.h"

void MouseUpdata(Dot* m) {
	GetMousePoint(&(m->x), &(m->y));
}

void DrawMouse(Dot m) {
	DrawCircle(m.x, m.y, 5, BLUE, true);
	DrawFormatString(0, 0, RED, "(%5d,%5d)", m.x, m.y);
	DrawFormatString(0, 20, RED, "ang = %f", m.ang * 180.0 / PI);
}