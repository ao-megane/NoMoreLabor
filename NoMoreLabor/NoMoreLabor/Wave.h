#ifndef WAVE_H
#define WAVE_H
#include"Obj.h"
#include"Value.h"

//�g�Ɋւ��鏈���𓝊�����N���X

class Wave
{
public:
	Wave() {}
	~Wave() {}
	void Initialize();		//�������֐�
	void Set(int count);	//�Z�b�^�[�֐�
	int Updata(int count);	//�X�V�֐�
	void Draw();			//�`��֐�
	bool IsJump(Dot center);//center���g�̒��ɂ����true

private:
	Dot Point1;	//
	Dot Point2;
	bool dir_x;//�g�̐i�ޕ�����x�������Ȃ�true
	double ang;
	int image;
};

#endif // !WAVE_H
