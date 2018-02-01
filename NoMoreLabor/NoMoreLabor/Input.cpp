#include"DxLib.h"
#include"Value.h"
#include"Obj.h"
#include"Input.h"

void Input::MouseUpdata() {
	GetMousePoint(m.GetXad(), m.GetYad());
	if (GetMouseInput() & MOUSE_INPUT_LEFT) click++;else click = 0;
}

// �L�[�̓��͏�ԍX�V
void Input::KeyUpdata() {
	char tmpKey[256];             // ���݂̃L�[�̓��͏�Ԃ��i�[����
	GetHitKeyStateAll(tmpKey);  // �S�ẴL�[�̓��͏�Ԃ𓾂�
	for (int i = 0; i<256; i++) {
		if (tmpKey[i] != 0) { // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			key[i]++;   // ���Z
		}
		else {              // ������Ă��Ȃ����
			key[i] = 0; // 0�ɂ���
		}
	}
}

void Input::Updata() {
	MouseUpdata();
	KeyUpdata();
}

// KeyCode�̃L�[�̓��͏�Ԃ��擾����
int Input::GetKey(int KeyCode) {
	return key[KeyCode]; // KeyCode�̓��͏�Ԃ�Ԃ�
}
intDot Input::GetMouse() {
	return m;
}
int Input::GetClick() {
	return click;
}
void Input::DrawMouse() {
	DrawCircle(m.GetX(), m.GetY(), 5, BLUE, true);
	DrawFormatString(0, 0, RED, "(%5d,%5d)", m.GetX(), m.GetY());
	DrawFormatString(0, 20, RED, "ang = %f", m.Todouble().GetAng() * 180.0 / PI);
	DrawFormatString(0, 40, RED, "click : ", click);
}
void Input::DrawKey() {
	DrawFormatString(0, 100, RED, "UP    : %d", GetKey(KEY_INPUT_UP));
	DrawFormatString(0, 120, RED, "DOWN  : %d", GetKey(KEY_INPUT_DOWN));
	DrawFormatString(0, 140, RED, "RIGHT : %d", GetKey(KEY_INPUT_RIGHT));
	DrawFormatString(0, 160, RED, "LEFT  : %d", GetKey(KEY_INPUT_LEFT));
}