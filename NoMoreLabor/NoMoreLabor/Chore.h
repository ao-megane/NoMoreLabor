#ifndef CHORE_H
#define CHORE_H
#include"Obj.h"

//�G�p�I�֐����܂Ƃ߂�ꏊ

void DrawLineByDot(Dot a, Dot b,int color);	//2�h�b�g�Ԃ�color�F�̐��������֐�

bool IsBlack(int imageHandle,Dot dot);	//imageHandle��dot�ʒu�̐F���������true��Ԃ��֐�

void FpsTimeFanction();	//���݂�FPS���v������֐�

double GetFPS();	//���݂�FPS��n���֐�

#endif // !CHORE_H
