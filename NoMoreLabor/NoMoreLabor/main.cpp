#include"DxLib.h"
#include"Chore.h"
#include"Obj.h"
#include"Input.h"
#include"Output.h"
#include"Value.h"
#include"Player.h"


typedef struct {
	int x, y;
	char name[128];
} MenuElement_t;

/*
TODO
�摜����or���G����
*/

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	

	SetGraphMode(DISP_WIDTH, DISP_HEIGHT, 32);
	{
		SetWindowSizeExtendRate(0.7);
		ChangeWindowMode(true);
	}
	SetDrawScreen(DX_SCREEN_BACK);
	DxLib_Init();	// DX���C�u��������������

	Input input;
	Dot center;
	Dot decoi;
	Player player;
	Motors motor;
	intDot mdot;
	mdot.Set(M_X, M_Y);
	int Jflag;
	center.Set(DISP_WIDTH / 2, DISP_HEIGHT / 2);
	SetMousePoint(M_X, M_Y);

	int stageFlag = 0;	//���݂̑I��ԍ��i���[�h�j
	int sceFlag = 0;	//�V�~�����[�^�̗�����Ǘ�����ϐ�

	/*-------------�t�H���g�ݒ�-------------------*/
	int tanuki;			//�t�H���g�ݒ�
	if (AddFontResourceEx("Font/TanukiMagic.ttf", FR_PRIVATE, NULL) == 0) {
		//printfDx("AddFontResource");
	}
	tanuki = CreateFontToHandle("���ʂ������}�W�b�N", 100, 9, DX_FONTTYPE_ANTIALIASING_8X8);
	if (tanuki == -1) {
		//printfDx("CreateFontToHandle");
	}
	/*----------------�����܂�---------------------*/

	motor.Initialize();
	player.Initialize();
	Jflag = 0;
	//SetMousePoint(DISP_WIDTH / 2.0, DISP_HEIGHT / 2.0);

	/*
	//�n�[�h�e�X�g�p�v���O����
	{
		SetMousePoint(DISP_WIDTH / 2.0, DISP_HEIGHT / 2.0);
		int flag = 0;
		float yunkawa = 0;
		while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
			input.Updata();
			if (input.GetKey(KEY_INPUT_W) == 1) flag = 0;
			if (input.GetKey(KEY_INPUT_A) == 1) flag = 1;
			if (input.GetKey(KEY_INPUT_D) == 1) flag = 2;
			if (input.GetKey(KEY_INPUT_S) == 1) {
				SetMousePoint(DISP_WIDTH / 2.0, DISP_HEIGHT / 2.0);
				flag = 3;
			}
			if (input.GetKey(KEY_INPUT_UP)) yunkawa += 0.01;
			if (input.GetKey(KEY_INPUT_DOWN)) yunkawa -= 0.01;

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

				motor.Calc(decoi);
				//motor.Draw();
				DrawLineByDot(center, input.GetMouse().Todouble(), GREEN);

				break;
			default:
				break;
			}
			motor.Draw();
			if (input.GetKey(KEY_INPUT_DELETE)) break;
		}
	}
	*/

	//���̂ق�
	
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		input.Updata();

		MenuElement_t MenuElement[3] = {
			{ 100, 300, "�X�^�[�g1(��)" },
			{ 200,500,"�X�^�[�g2(��)" },
			{ 200,700,"�I��" },
		};
		switch (sceFlag){//�V�~�����[�^�̗�����Ǘ�����X�C�b�`
		case 0://�^�C�g��
			//�v�Z
			if (input.GetKey(KEY_INPUT_S) == 1) {
				stageFlag = (stageFlag + 1) % 3;
			}
			if (input.GetKey(KEY_INPUT_W) == 1) {
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
				
			if (input.GetClick() == 1) sceFlag = stageFlag+1;

			for (int i = 0; i < 3; i++) {
				//DrawFormatString(MenuElement[i].x, MenuElement[i].y, GetColor(225, 225, 225), MenuElement[i].name);
				DrawStringToHandle(MenuElement[i].x, MenuElement[i].y, MenuElement[i].name, GetColor(225, 225, 225), tanuki);
			}
			break;
		case 1://���A�����[�h
			player.Updata(input,Jflag);
			decoi = (input.GetMouse().Todouble() - center);
			decoi.Updata();

			motor.Calc(decoi);
			if (!input.GetMouse().Todouble().IsHitC(M_X, M_Y, M_RANGE))
			DrawFormatString(0, 0, RED, "OUT!");

			input.GetMouse().Todouble().Draw(RED);
			player.Draw();
			//motor.Draw();
			//DrawLineByDot(center, input.GetMouse().Todouble(), GREEN);
			//DrawLineByDot(mdot.Todouble(), (mdot.Todouble() + -(player.GetVelocity()).Rotate(player.GetAng())*5), GREEN);
			DrawLineByDot(mdot.Todouble(), (mdot.Todouble() + -player.GetForce()), GREEN);
			DrawCircle(center.GetX(), center.GetY(), 3, RED, true);
			DrawCircle(M_X, M_Y, M_RANGE, BLUE, false);
			break;
		case 2://�A�����A�����[�h
			player.Updata(input,Jflag);
			decoi = (input.GetMouse().Todouble() - center);
			decoi.Updata();

			motor.Calc(decoi);
			if (!input.GetMouse().Todouble().IsHitC(M_X, M_Y, M_RANGE))
			DrawFormatString(0, 0, RED, "OUT!");

			input.GetMouse().Todouble().Draw(RED);
			player.Draw();
			//motor.Draw();
			//DrawLineByDot(center, input.GetMouse().Todouble(), GREEN);
			//DrawLineByDot(mdot.Todouble(), (mdot.Todouble() + -(player.GetVelocity()).Rotate(player.GetAng())*5), GREEN);
			DrawLineByDot(mdot.Todouble(), (mdot.Todouble() + -player.GetForce()), GREEN);
			DrawCircle(center.GetX(), center.GetY(), 3, RED, true);
			DrawCircle(M_X, M_Y, M_RANGE, BLUE, false);
			break;
		case 3://�N���W�b�g
			break;
		case 4://�I��
			break;
		default:
			break;
		}

		if (input.GetKey(KEY_INPUT_DELETE)) break;
	}
	
	
	DxLib_End();	// DX���C�u�����I������
	return 0;
}


//while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
//	input.Updata();
//MenuElement_t MenuElement[3] = {
//	{ 100, 300, "�X�^�[�g1(��)" },
//	{ 200,500,"�X�^�[�g2(��)" },
//	{ 200,700,"�I��" },
//};
//	switch (sceFlag){//�V�~�����[�^�̗�����Ǘ�����X�C�b�`
//	case 0://�^�C�g��
//		//�v�Z
//		if (input.GetKey(KEY_INPUT_DOWN) == 1) {
//			stageFlag = (stageFlag + 1) % 3;
//		}
//		if (input.GetKey(KEY_INPUT_UP) == 1) {
//			stageFlag = (stageFlag + 2) % 3;
//		}
//		if (input.GetKey(KEY_INPUT_ESCAPE) == 1) {
//			stageFlag = 2;
//			MenuElement[0].x = 200;
//			MenuElement[1].x = 200;
//			MenuElement[2].x = 100;
//		}

//		if (input.GetKey(KEY_INPUT_DOWN) == 1 || input.GetKey(KEY_INPUT_UP) == 1) {
//			for (int i = 0; i < 3; i++) {
//				if (i == stageFlag) {
//					MenuElement[i].x = 100;
//				}
//				else {
//					MenuElement[i].x = 200;
//				}
//			}
//		}
//		
//		if (input.GetClick() == 1) sceFlag = stageFlag;

//		break;
//	case 1://���A�����[�h
//		break;
//	case 2://�A�����A�����[�h
//		break;
//	case 3://�N���W�b�g
//		break;
//	case 4://�I��
//		break;
//	default:
//		break;
//	}
//	
//	//�`��
//	for (int i = 0; i < 3; i++) {
//		//DrawFormatString(MenuElement[i].x, MenuElement[i].y, GetColor(225, 225, 225), MenuElement[i].name);
//		DrawStringToHandle(MenuElement[i].x, MenuElement[i].y, MenuElement[i].name, GetColor(225, 225, 225), tanuki);
//	}
//	if (CheckHitKey(KEY_INPUT_DELETE)) break;
//}
/*------------------------------------------------------------------------------------------------------------------------------------------------*/