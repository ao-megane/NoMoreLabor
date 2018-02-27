#ifndef PLAYER_H
#define PLAYER_H
#include"Obj.h"
#include"Input.h"
#include"Value.h"

//�v���C���[�i�{�[�g�j�̏����𓝊�����N���X

class Player
{
public:
	Player(){}
	~Player(){}
	void Initialize();		//�������֐�
	void Set(int flag);
	void Updata(Input input,bool Jflag, int count);	//���͂�g�Ȃǂɉ������X�V�֐�
	void SetJump(int count);	//�W�����v��Ԃɂ���֐�
	void UpdataJump(int count);	//�W�����v��Ԏ��̍X�V�֐�
	void Draw();			//�`��֐�
	void End();				//�I���֐�
	Dot GetCenter();
	Dot GetVelocity();
	Dot GetAccelerator();
	Dot GetForce();
	double GetAng();
	int GetWeight();
	int GetState();

private:
	//Dot precenter;
	Dot center;			//���S���W
	Dot velocity;		//�v���C���[�̑��x�i�x�N�g���j
	Dot accelerator;	//�v���C���[�̉����x�i�x�N�g���j
	Dot force;			//�v���C���[�̎󂯂�͂̃x�N�g��
	int weight;			//�v���C���[�̏d���i�󂯂�͂ɉe����^����j
	int state;			//�v���C���[�̏�Ԃ�ێ�����ϐ��@0:normal 1:jumping
	int bodyClock;		//�A�j���[�V�����p�J�E���g�ێ��ϐ�
	double enlarge;		//�A�j���[�V�����p�摜�g�嗦
	double ang;			//�`��p�p�x
	int image;			//�`��摜�n���h��
};


#endif // !PLAYER_H
