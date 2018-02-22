#ifndef INPUT_H
#define INPUT_H
#include"Obj.h"
#include"Value.h"

//���͑S�Ă𓝊�����N���X
class Input
{
public:
	Input() {}
	~Input() {}
	void MouseUpdata();	//�}�E�X�̍X�V�֐�
	void KeyUpdata();	//�L�[�{�[�h�̍X�V�֐�
	void Updata();		//��̂ӂ����܂Ƃ߂čs���֐�
	int GetKey(int code);	//����L�[�{�[�h�̓��͏�Ԃ�n���֐�
	int GetClick();		//�N���b�N�̓��͏�Ԃ�n���֐�
	intDot GetMouse();	//�}�E�X�̍��W��n���֐�
	void DrawMouse();	//�}�E�X�̍��W�̕`��
	void DrawKey();		//�L�[�{�[�h�i�\���L�[�j�̓��͏�Ԃ̕`��
private:
	intDot m;		//�}�E�X�̏����p���W
	int click;		//�N���b�N�̏�ԕێ��p�ϐ�
	int key[256];	//�e�L�[�̏�ԕۑ��p�ϐ�
};

#endif // !INPUT_H
