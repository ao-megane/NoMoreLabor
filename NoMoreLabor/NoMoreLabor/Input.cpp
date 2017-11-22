#include"DxLib.h"
#include"Value.h"
#include"Obj.h"
#include"Input.h"

void Input::MouseUpdata() {
	GetMousePoint(m.GetXad(), m.GetYad());
}

void Input::DrawMouse() {
	DrawCircle(m.GetX(), m.GetY(), 5, BLUE, true);
	DrawFormatString(0, 0, RED, "(%5d,%5d)", m.GetX(), m.GetY());
	DrawFormatString(0, 20, RED, "ang = %f", m.GetAng() * 180.0 / PI);
}