#ifndef OUTPUT_H
#define OUTPUT_H
#include"Obj.h"

//�o�́iMotor�j�𓝊�����N���X�ASpidermouse�͂����ł����g��Ȃ�

class Motors
{
public:
	Motors(){}
	~Motors() {}
	//void Set(float a, float b, float c, float d);
	void Initialize();		//�������֐�
	void Set(float u, float r, float l);	//��A�E���A�����̐ݒ�֐��i0�`1.0�j
	void SetSPE(float a);	//special�iJump�j�p�Z�b�^�[�֐�
	void Calc(Dot F,int playerState);	//�̓x�N�g����player�̏�ԁi�W�����v�j�ɉ����Ċe���[�^�[�̒l���v�Z�A�i�[����֐�
	void Updata(bool flag);			//�e���[�^�[�֔��f����֐�
	void Draw();			//�`��֐�
	void End();				//�I���֐�

private:
	float UP;	//������̃��[�^�[�o��
	float RD;	//�E�������̃��[�^�[�o��
	float LD;	//���������̃��[�^�[�o��
	float SPE;	//�W�����v�p���[�^�[�o��
};

#endif // !OUTPUT_H
