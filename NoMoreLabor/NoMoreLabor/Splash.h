#ifndef SPLASH_H
#define SPLASH_H
#include"Obj.h"
#include"Value.h"

//�򖗁i�v���C���[�̉e�I�����j�֌W�𓝊�����N���X

class Splash
{
public:
	Splash() {}
	~Splash() {}
	void Initialize();		//�������֐�
	void Set(int count,Dot center,double ang);	//�򖗂̃Z�b�g�֐�
	int Updata(int count);	//�X�V�֐�
	void Draw();			//�`��֐�
	bool GetisExist();		//���݂��邩�ۂ���Ԃ��֐�

private:
	//�v���C���[�Ɠ��l�ȕϐ�
	Dot center;
	double ang;
	int bodyClock;
	bool isExist;
	double enlarge;
	double alpha;	//�����x
};

void SplashMngInitialize();	//Splash���܂Ƃ߂ď���������֐�
void SplashMngUpdata(int count,Dot p_center,double p_ang,int p_state);	//Splash���܂Ƃ߂čX�V����֐�
void SplashMngDraw();		//Splash���܂Ƃ߂ĕ`�悷��֐�
void SplashMngEnd();		//Splash���܂Ƃ߂ďI������֐�

#endif // !SPLASH_H
