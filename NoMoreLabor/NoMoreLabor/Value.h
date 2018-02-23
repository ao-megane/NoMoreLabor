#ifndef VALUE_H
#define VALUE_H
#include"DxLib.h"

//�萔���܂Ƃ߂Ă����w�b�_�[

const int RED = GetColor(255, 0, 0);		//�Ԃ̐F�R�[�h
const int GREEN = GetColor(0, 255, 0);		//�΂̐F�R�[�h
const int BLUE = GetColor(0, 0, 255);		//�̐F�R�[�h
const int WHITE = GetColor(255, 255, 255);	//���̐F�R�[�h

const int DISP_WIDTH = 1280;	//�f�B�X�v���C�̉�f�i���j
const int DISP_HEIGHT = 800;	//�f�B�X�v���C�̉�f�i�c�j

const double PI = 3.14159265358979;		//�~����
const double rootTwo = 1.4142135624;	//���[�g2
const double rootThree = 1.7320508;		//���[�g3

const double F_ABS_MAX = DISP_WIDTH;	//�͂̍ő�l�i���[�^�[�̊��x�j

const int P_HEIGHT = 544 * 0.05;			//�v���C���[�̕`��̑傫��
const int P_WIDTH = 928 * 0.05;				//
const double ACCELE = 1.0/2.0;				//1�t���[��������̉����x�̑傫��
const double BRAKE = -0.5;					//1�t���[��������̃u���[�L�̋���
const double LIMIT = 20.0/2;				//�������x
const double ADDED_ANGLE = PI / 24.0/2.0;	//1�t���[��������̉�]�p�x
const double DECAY_STRAIGHT = 0.999;		//�c�����̒�R��
const double DECAY_SIDE = 0.8;				//�������̒����
const double JUMPING_TIME = 30.0;			//�W�����v�ɗv����t���[����

const int M_X = DISP_WIDTH - 100;			//�R�[�X�X�^�[�g���̃}�E�X�̏����ʒu�i���j
const int M_Y = DISP_HEIGHT - 100;			//�R�[�X�X�^�[�g���̃}�E�X�̏����ʒu�i�c�j
const int M_RANGE = 80;						//�`��p�A�~�̔��a

const int WAVE_INTERVAL = 20 * 60;	//�g�̐��܂��Ԋu�i�t���[���j
const int WAVE_SPEED = 2;			//1�t���[��������̔g�̐i�ޑ��x
const int WAVE_BAND = 50;			//�g�̑���

const int SPL_NUM = 100;				//�����ɕ`�悷��g�̌��i���C�t�^�C���ɂ��ˑ����Ă���j
const int SPL_INTERVAL = 0.05 * 60;		//���t���[�����Ƃɔ򖗂��������邩
const double SPL_LIFETIME = 3.0 * 60.0;	//���t���[���Ŕ򖗂̕`�悪�I��邩

#endif // !VALUE_H
