#include"DxLib.h"
#include"Obj.h"
#include"Value.h"

void DrawLineByDot(Dot a, Dot b,int color) {
	DrawLine(a.GetX(), a.GetY(), b.GetX(), b.GetY(), color, false);
}

bool IsBlack(int imageHandle, Dot dot) {
	int r = 0, g = 0, b = 0;

	GetPixelSoftImage(imageHandle, dot.GetX(), dot.GetY(), &r, &g, &b, 0);	//imageHandle��dot(���W)��RGB���i�[
	if (r == 0 && g == 0 && b == 0) {	//�S��0�Ȃ�
		return true;
	}
	else {
		return false;
	}
	//return true;
}

void DrawCredit(int font) {
	//DrawBox(0, 0, DISP_WIDTH, DISP_HEIGHT, BLUE, true);
	DrawStringToHandle(250, 100, "CREDIT", BLACK, font);
	DrawStringToHandle(250, 150, "", BLACK, font);
	DrawStringToHandle(250, 200, "�\�t�g�S��", BLACK, font);
	DrawStringToHandle(250, 250, "�@4L22 �c�� ��", BLACK, font);
	DrawStringToHandle(250, 300, "�@4R22 ���� ����", BLACK, font);
	DrawStringToHandle(250, 350, "�@�g�p�\�t�g:visualstudio2015,github", BLACK, font);
	DrawStringToHandle(250, 400, "�@�g�p���C�u����:DxLib", BLACK, font);
	DrawStringToHandle(250, 450, "", BLACK, font);
	DrawStringToHandle(250, 500, "�n�[�h�S��", BLACK, font);
	DrawStringToHandle(250, 550, "�@4R26 �m�� �����Y", BLACK, font);
	DrawStringToHandle(250, 600, "�@4L36 �n� ��", BLACK, font);
	DrawStringToHandle(250, 650, "�@�g�p�\�t�g:Fusion360", BLACK, font);
	//DrawStringToHandle(450, 700, "CREDIT", BLACK, font);
}

int FpsTime[2] = { 0, }, FpsTime_i = 0;
double Fps = 0.0;
void FpsTimeFanction() {
	if (FpsTime_i == 0)
		FpsTime[0] = GetNowCount();               //1���ڂ̎��Ԏ擾
	if (FpsTime_i == 49) {
		FpsTime[1] = GetNowCount();               //50���ڂ̎��Ԏ擾
		Fps = 1000.0f / ((FpsTime[1] - FpsTime[0]) / 50.0f);//���肵���l����fps���v�Z
		FpsTime_i = 0;//�J�E���g��������
	}
	else
		FpsTime_i++;//���݉����ڂ��J�E���g
	if (Fps != 0)
		//DrawFormatString(DISP_WIDTH - 100, DISP_HEIGHT - 20, RED, "FPS %.1f", Fps); //fps��\��
	return;
}

double GetFPS() {
	return Fps;
}

