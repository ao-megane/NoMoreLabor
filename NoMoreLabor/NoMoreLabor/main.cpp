#include "DxLib.h"
#include"Chore.h"
#include"Obj.h"
#include"Input.h"
#include"Output.h"
#include"Value.h"

typedef struct {
	int x, y;
	char name[128];
} MenuElement_t;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	SetGraphMode(DISP_WIDTH, DISP_HEIGHT, 32);
	SetWindowSizeExtendRate(0.7);
	ChangeWindowMode(true);
	SetDrawScreen(DX_SCREEN_BACK);
	DxLib_Init();	// DX���C�u��������������

	Input input;
	Dot center;
	Dot decoi;
	Dot m;
	Motors motor;
	center.Set(DISP_WIDTH / 2, DISP_HEIGHT / 2);
	
	MenuElement_t MenuElement[3] = {
		{ 100,300,"�X�^�[�g1(��)" },
		{ 200,500,"�X�^�[�g2(��)" },
		{ 200,700,"�I��" },
	};

	int stageFlag = 0;	//���݂̑I��ԍ��i���[�h�j
	int sceFlag = 0;	//�V�~�����[�^�̗�����Ǘ�����ϐ�

	/*-------------�t�H���g�ݒ�-------------------*/
	int tanuki;			//�t�H���g�ݒ�
	if (AddFontResourceEx("Font/TanukiMagic.ttf", FR_PRIVATE, NULL) == 0) {
		printfDx("AddFontResource");
	}
	tanuki = CreateFontToHandle("���ʂ������}�W�b�N", 100, 9, DX_FONTTYPE_ANTIALIASING_8X8);
	if (tanuki == -1) {
		printfDx("CreateFontToHandle");
	}
	/*----------------�����܂�---------------------*/

	//while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
	//	input.Updata();

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
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		
		decoi = (input.GetMouse() - center);
		decoi.Updata();

		motor.Calc(decoi);

		DrawMouse(m);
		DrawMouse(decoi.Rotate(PI / 2);
		motor.Draw();
		DrawLineByDot(input.GetMouse(), center, BLUE);
		DrawCircle(center.GetX(), center.GetY(), 3, RED, true);
		
	}

	
	DxLib_End();	// DX���C�u�����I������
	return 0;
}