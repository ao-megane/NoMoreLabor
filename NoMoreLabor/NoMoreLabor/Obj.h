#ifndef OBJ_H
#define OBJ_H
#include<math.h>
#include"Value.h"

//���W��ʒu�x�N�g���Ƃ��ĕ֗��ȃh�b�g�N���X�̒�`

class Dot
{
public:
	Dot() {}
	~Dot() {}
	void Set(double x, double y);
	void SetX(double a);
	void SetY(double a);
	void SetAbs(float a);
	void SetAng(double a);
	double GetX();
	double GetY();
	double* GetXad();
	double* GetYad();
	float GetAbs();		
	double GetAng();	
	bool IsHitC(Dot a, int range);	//���Sa,���arange�̉~���ɂ����true��Ԃ��֐�
	bool IsHitC(int a, int b, int range);	//
	void Updata();	//�������W�n�����Ƃɋɍ��W�n��⑫����֐�
	void Draw(int color);	//���W��color�F�̉~��`��
	double innerPro(Dot a);	//�ʂ�Dot�Ƃ̓���
	Dot Rotate(double rad);	//���_�𒆐S��rad������]�i�����v�j

	Dot operator - (Dot a) {	//�h�b�g�̕��s�ړ�
		Dot RE;
		RE.Set(x - a.x, y - a.y);
		RE.Updata();
		return RE;
	}
	Dot operator - () {			//���_�Ώۂȃh�b�g�֕ϊ�
		Dot RE;
		RE.Set(-x, -y);
		RE.Updata();
		return RE;
	}
	Dot operator + (Dot a) {	//�h�b�g�̕��s�ړ�
		Dot RE;
		RE.Set(x + a.x, y + a.y);
		RE.Updata();
		return RE;
	}
	void operator = (Dot a) {	//�h�b�g�̑��
		x = a.x;
		y = a.y;
		abs = a.abs;
		ang = a.ang;
	}
	Dot operator * (int a) {	//�X�J���{�̒�`
		Dot RE;
		RE.Set(x *= a, y *= a);
		RE.Updata();
		return RE;
	}
	Dot operator * (double a) {	//�X�J���{�̒�`
		Dot RE;
		RE.Set(x *= a, y *= a);
		RE.Updata();
		return RE;
	}
	bool operator != (Dot a) {	//�ʂ�Dot�ƈ�v���Ă����false
		if (a.x == x && a.y == y) return false;
		return true;
	}
	
private:
	double x;	//�������W�n��x���W
	double y;	//�������W�n��y���W
	float abs;	//�ɍ��W�n�̐�Βl
	double ang;	//�ɍ��W�n�̊p�x�@0�`2PI

};

//Dot�N���X��int�֊g���������́A�}�E�X�p
class intDot
{
public:
	intDot(){}
	~intDot(){}
	void Set(int x, int y);
	int GetX();
	int GetY();
	int* GetXad();
	int* GetYad();
	Dot Todouble();

private:
	int x;
	int y;
	float abs;
	double ang;	//0~2PI
};

#endif // !OBJ_H
