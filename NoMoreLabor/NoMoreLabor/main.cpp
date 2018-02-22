#include"DxLib.h"
#include"Chore.h"
#include"Obj.h"
#include"Input.h"
#include"Output.h"
#include"Value.h"
#include"Player.h"
#include"BackGround.h"
#include"Wave.h"
#include"Splash.h"

typedef struct {
	int x, y;
	char name[128];
} MenuElement_t;

/*
TODO
�摜����or���G����
�v���C���[�A���쐫���P
�͂̒���
�g�N���X�̎���
*/

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	/*-------------DxLib�ݒ�----------------------------------------*/
	SetGraphMode(DISP_WIDTH, DISP_HEIGHT, 32);	//��f���A�g�p����F�̐��̐ݒ�
	{
		/*-------------�E�B���h�E���[�h�ݒ�-------------------*/
		SetWindowSizeExtendRate(0.7);	//��Őݒ肵���T�C�Y��0.7�{�ŕ\��
		ChangeWindowMode(true);			//�E�B���h�E���[�h�ɕύX�i�f�t�H���g�̓t���X�N���[�����[�h�j
	}
	SetDrawScreen(DX_SCREEN_BACK);	//����ʏ����̐ݒ�
	DxLib_Init();	// DX���C�u��������������
	/*-------------DxLib�ݒ藹--------------------------------------*/

	/*-------------�e��ϐ��ݒ�-------------------------------------------*/
	Input input;	//���͏���
	Dot center;		//�`��̒��S���W
	center.Set(DISP_WIDTH / 2, DISP_HEIGHT / 2);	//center���s�N�Z���P�ʂŉ�ʂ̒��S�փZ�b�g
	Dot decoi;		//�e�v�Z�̓r���̒l�������
	Player player;	//�v���C���[����
	Motors motor;	//�o�́i���[�^�[�j����
	//�f�o�b�N�p
		intDot mdot;	//�}�E�X����
		mdot.Set(M_X, M_Y);	//�}�E�X������̈ʒu�փZ�b�g
	
	Back back;		//�w�i����
	Wave wave;		//�g����
	
	int Jflag = 0;		//�v���C���[�̃W�����v�t���O
	int count = 0;	//�X�^�[�g����̌o�߃t���[���̃J�E���^
	int flag = 0;	//
	float yunkawa = 0;	//�n�[�h�e�X�g�p�p�����[�^�i0�`1.0�j
	int sceFlag = 0;	//���݂̃\�t�g�̏�ԁiOP,PLAYING,ENDING�j�̃t���O
	int stageFlag = 0;	//OP�Ŏg���A���ݑI�𒆂̃X�e�[�W�i���[�h�j
	
	MenuElement_t MenuElement[3] = {	//�ŏ��̉�ʂ̕\������
		{ 100, 300, "����o�C�N�V�~�����[�^" },
		{ 200,500,"�n�[�h�e�X�g" },
		{ 200,700,"�I��" },
	};

	/*-------------�e��N���X�̏���������-------------------*/
	motor.Initialize();
	player.Initialize();
	back.Initialize();
	wave.Initialize();
	SplashMngInitialize();

	/*-------------�t�H���g�̒ǉ�-------------------*/
	int tanuki;
	if (AddFontResourceEx("font/TanukiMagic.ttf", FR_PRIVATE, NULL) == 0) {
		//printfDx("AddFontResource");
	}
	tanuki = CreateFontToHandle("���ʂ������}�W�b�N", 100, 9, DX_FONTTYPE_ANTIALIASING_8X8);
	if (tanuki == -1) {
		//printfDx("CreateFontToHandle");
	}

	/*-------------�e��ϐ��ݒ藹-------------------------------------------*/

	/*-------------���[�v����------------------------------------------------------------------------------*/
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//�\���n��DxLib�ɃG���[���Ȃ���Α��s
		input.Updata();//���͂̍X�V
		motor.Updata();//���[�^�[�̍X�V

		switch (sceFlag) {//�V�~�����[�^�̗�����Ǘ�����X�C�b�`
		case 0://�^�C�g��
		{
			//�v�Z
			if (input.GetKey(KEY_INPUT_S) == 1 || input.GetKey(KEY_INPUT_DOWN) == 1) {	//�オ�����ꂽ��I�������
				stageFlag = (stageFlag + 1) % 3;
			}
			if (input.GetKey(KEY_INPUT_W) == 1 || input.GetKey(KEY_INPUT_UP) == 1) {	//���������ꂽ��I��������
				stageFlag = (stageFlag + 2) % 3;
			}
			for (int i = 0; i < 3; i++) {
				if (i == stageFlag) {
					MenuElement[i].x = 100;
				}
				else {
					MenuElement[i].x = 200;
				}
			}

			if (input.GetClick() == 1 || input.GetKey(KEY_INPUT_RETURN)) {	//�N���b�N���G���^�[�őI���ɉ��������̏�����
				back.Set(0);//�w�i�̐ݒ�i���[�h�ɂ��قȂ�j
				count = 0;	//�J�E���^��������
				sceFlag = stageFlag + 1;	//OP�̑I��\���t���O���V�X�e���̗���t���O�֔��f
				if (sceFlag == 1) SetMousePoint(M_X, M_Y);	//�}�E�X�ʒu�̏�����
			}

			for (int i = 0; i < 3; i++) {	//�I���̕`��
				DrawStringToHandle(MenuElement[i].x, MenuElement[i].y, MenuElement[i].name, GetColor(225, 225, 225), tanuki);
			}
			break; 
		}
		case 1://����o�C�N
		{
			/*-------------�e�N���X�̍X�V-------------------*/
			wave.Set(count);	//�J�E���^�ɉ����Ĕg���Z�b�g
			wave.Updata(count);	//�J�E���^�ɉ����Ĕg���X�V
			player.Updata(input, wave.IsJump(player.GetCenter()), count);	//���́A�g�������ƂɃv���C���[�̍X�V
			SplashMngUpdata(count, player.GetCenter(), player.GetAng(), player.GetState());	//�򖗂̍X�V�i�v���C���[�̉e�̂悤�Ȗ����j
			//decoi = (input.GetMouse().Todouble() - center);	
			//decoi.Updata();
			//motor.Calc(decoi, player.GetState());	//
			//????

			/*-------------�`��-------------------*/
			back.Draw();
			if (!input.GetMouse().Todouble().IsHitC(M_X, M_Y, M_RANGE)) {
				DrawFormatString(0, 50, RED, "OUT!");
			}
			if (!back.Updata(count, player.GetCenter())) {
				DrawFormatString(0, 100, BLUE, "OUT!");
			}
			input.GetMouse().Todouble().Draw(RED);
			wave.Draw();
			SplashMngDraw();
			player.Draw();
			//motor.Draw();
			//DrawLineByDot(center, input.GetMouse().Todouble(), GREEN);
			//DrawLineByDot(mdot.Todouble(), (mdot.Todouble() + -(player.GetVelocity()).Rotate(player.GetAng())*5), GREEN);
			DrawLineByDot(mdot.Todouble(), (mdot.Todouble() + -player.GetForce()), GREEN);
			DrawCircle(center.GetX(), center.GetY(), 3, RED, true);
			DrawCircle(M_X, M_Y, M_RANGE, BLUE, false);

			break; 
		}
		case 2://�n�[�h�e�X�g
		{
			if (input.GetKey(KEY_INPUT_W) == 1) flag = 0;
			if (input.GetKey(KEY_INPUT_A) == 1) flag = 1;
			if (input.GetKey(KEY_INPUT_D) == 1) flag = 2;
			if (input.GetKey(KEY_INPUT_S) == 1) {
				SetMousePoint(DISP_WIDTH / 2.0, DISP_HEIGHT / 2.0);
				motor.Set(0, 0, 0);
				yunkawa = 0;
				flag = 3;
			}
			if (input.GetKey(KEY_INPUT_UP)) yunkawa += 0.01;
			if (input.GetKey(KEY_INPUT_DOWN)) yunkawa -= 0.01;
			if (yunkawa < 0) yunkawa = 0;

			switch (flag)
			{
			case 0:
				motor.Set(yunkawa, 0, 0);
				break;
			case 1:
				motor.Set(0, 0, yunkawa);
				break;
			case 2:
				motor.Set(0, yunkawa, 0);
				break;
			case 3:
				decoi = (input.GetMouse().Todouble() - center);
				decoi.Updata();
				motor.Calc(decoi, 0);
				DrawLineByDot(center, input.GetMouse().Todouble(), GREEN);
				if (input.GetClick() > 0) motor.SetSPE(0.7);
				break;
			default:
				break;
			}
			motor.Draw();
			break;
		}
		case 3://�N���W�b�g
		{
			break;
		}
		case 4://�I��
			break;
		default:
			break;
		}

		FpsTimeFanction();	//���݂�FPS�̕\��
		if (input.GetKey(KEY_INPUT_DELETE) == 1) {//�f���[�g�������ꂽ���O�̉�ʂցAOP��ʂȂ�\�t�g���I������
			if (sceFlag == 0) {
				break;
			}
			else {
				sceFlag = 0;
			}
		}
		count++;	//�J�E���^�̍X�V
	}
	/*-------------���[�v���������܂�----------------------------------------------------------------------*/

	/*-------------�I������-------------*/
	motor.End();
	InitSoftImage();
	DxLib_End();	// DX���C�u�����I������
	/*-------------�I�����������܂�-----*/
	return 0;
}