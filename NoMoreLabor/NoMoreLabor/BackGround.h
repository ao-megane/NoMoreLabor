#ifndef BACKGROUND_H
#define BACKGROUND_H
#include"Obj.h"

//�w�i�S�Ă𓝊�����N���X
class Back
{
public:
	Back() {}
	~Back() {}
	//void Set(float a, float b, float c, float d);
	void Initialize();	//�������֐�
	void Set(int stage);	//�X�e�[�W�ɉ������w�i���Z�b�g
	int Updata(int count,Dot dot);	
		//���Ԍo�߂ɂ��ω��̔��f�A����_�̃R�[�X�̈��ۂ�Ԃ��֐�
	void Draw();	//�`��֐�

private:
	int bgHandle;		//�w�i�摜�n���h��
	int mapHandle;		//�R�[�X�摜�n���h��
	int softmapHandle;	//�\�t�g�}�b�v�n���h��
	
};

#endif // !BACKGROUND_H
