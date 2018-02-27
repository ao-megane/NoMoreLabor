#include"DxLib.h"
#include"Value.h"
#include"Obj.h"
#include"Wave.h"
#include"Chore.h"

int normal_image;

void Wave::Initialize() {
	normal_image = LoadGraph("images/wave/normal.png");
	image = normal_image;
}

void Wave::Set(int count) {
	if (count % WAVE_INTERVAL != 3)	//WAVE_INTERVAL���Ƃɐ���
		return;

	Point1.Set(0, 0);

	SRand(GetNowCount());	//�c�ɐi�ނ����ɐi�ނ��������_���Ɍ���
	if (GetRand(1)) {
		dir_x = true;
	}
	else {
		dir_x = false;
	}
	
	if (dir_x)	//Point2�̐ݒ�
		Point2.Set(-GetRand(WAVE_SPEED * WAVE_INTERVAL*0.8), DISP_HEIGHT);
	else
		Point2.Set(DISP_WIDTH, -GetRand(WAVE_SPEED * WAVE_INTERVAL*0.8));

	if (Point2.GetX() == 0) ang = 0;	//�g�̊p�x���Z�o
	else ang = -atan2(Point2.GetY(), Point2.GetX());
	while (ang >= PI * 2)
		ang -= 2 * PI;
	while (ang < 0)
		ang += 2 * PI;
}

int Wave::Updata(int count) {	//�g�̍X�V�i�i�߂�j
	if (dir_x) {
		Point1.SetX(Point1.GetX() + WAVE_SPEED);
		Point2.SetX(Point2.GetX() + WAVE_SPEED);
	}
	else {
		Point1.SetY(Point1.GetY() + WAVE_SPEED);
		Point2.SetY(Point2.GetY() + WAVE_SPEED);
	}
	return 0;
}

bool Wave::IsJump(Dot center) {
	//�_�Ǝl�p�̂����蔻��
	//�l�p��center�����s�ړ����A��2�ی��A��4�ی��ɂ������Ă��邩����
	Dot decoi1, decoi2;
	decoi1 = Point1 - center;
	decoi2 = Point2 - center;
	decoi1 = decoi1.Rotate(-ang);
	decoi2 = decoi2.Rotate(-ang);
	decoi1.SetY(decoi1.GetY() - WAVE_BAND / 2.0);
	decoi2.SetY(decoi2.GetY() + WAVE_BAND / 2.0);

	if (decoi1.GetX()*decoi2.GetX() < 0 && decoi2.GetY()*decoi1.GetY() < 0) {	//�l�p�̒��Ɍ��_�����邩
		return true;
	}
	else {
		return false;
	}
}

Dot a1;
Dot b1;
Dot c1;
Dot d1;
Dot kakashi;
void Wave::Draw() {
	kakashi.Set(-WAVE_BAND / 2,0);
	a1 = kakashi.Rotate(-ang) + Point1;
	kakashi.Set(+WAVE_BAND / 2, 0);
	b1 = kakashi.Rotate(-ang) + Point1;
	kakashi.Set(+WAVE_BAND/2,0);
	c1 = kakashi.Rotate(-ang) + Point2;
	kakashi.Set(-WAVE_BAND/2,0);
	d1 = kakashi.Rotate(-ang) + Point2;
	DrawModiGraph(
		a1.GetX(), a1.GetY(),
		b1.GetX(), b1.GetY(),
		c1.GetX(), c1.GetY(),
		d1.GetX(), d1.GetY(),
		image, true
		);
}