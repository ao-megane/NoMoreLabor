#include"DxLib.h"
#include"Value.h"
#include"Obj.h"
#include"Wave.h"
#include"Chore.h"
#include"Splash.h"

int image;

void Splash::Initialize() {
	bodyClock = 0;
	center.Set(0,0);
	ang = 0;
	isExist = false;
	enlarge = 0;
	alpha = 0.0;
}

void Splash::Set(int count, Dot p_center, double p_ang) {
	bodyClock = count;
	center = p_center;
	ang = p_ang;
	isExist = true;
	enlarge = 1.0;
	alpha = 0.0;
}

int Splash::Updata(int count) {
	enlarge = 1.0 + sin(PI / 2.0 / SPL_LIFETIME * (count - bodyClock));//ここ怪しい
	alpha = (count - bodyClock) / SPL_LIFETIME;//0~1なはず

	if ((count - bodyClock) >= SPL_LIFETIME) {
		bodyClock = 0;
		center.Set(0, 0);
		ang = 0;
		enlarge = 0;
		isExist = false;
	}
	return 0;
}

bool Splash::GetisExist() {
	return isExist;
}

Dot a2;
Dot b2;
Dot c2;
Dot d2;
Dot otori;
void Splash::Draw() {
	if (!isExist) return;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255.0*(1.0-alpha));		//ブレンドモードをα(128/255)に設定
	
	//DrawFormatString(100, 100, GREEN, "alpha:%f", alpha);
	otori.Set(-P_WIDTH / 2, -P_HEIGHT / 2);
	a2 = otori.Rotate(ang) * enlarge + center;
	otori.Set(+P_WIDTH / 2, -P_HEIGHT / 2);
	b2 = otori.Rotate(ang) * enlarge + center;
	otori.Set(+P_WIDTH / 2, +P_HEIGHT / 2);
	c2 = otori.Rotate(ang) * enlarge + center;
	otori.Set(-P_WIDTH / 2, +P_HEIGHT / 2);
	d2 = otori.Rotate(ang) * enlarge + center;
	DrawModiGraph(
		a2.GetX(), a2.GetY(),
		b2.GetX(), b2.GetY(),
		c2.GetX(), c2.GetY(),
		d2.GetX(), d2.GetY(),
		image, true
		);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	/*DrawLineByDot(a2, b2, RED);
	DrawLineByDot(b2, c2, RED);
	DrawLineByDot(c2, d2, RED);
	DrawLineByDot(d2, a2, RED);*/
	//DrawModiGraph(0, 0, 300, 0, 300, 300, 0, 300, image, false);
	//printfDx("DRAW");
}

Splash splashes[SPL_NUM];
void SplashMngInitialize() {
	for (int i = 0; i < SPL_NUM; i++) {
		splashes[i].Initialize();
	}
	image = LoadGraph("images/splash/normal.png");
}

void SplashMngUpdata(int count, Dot p_center,double p_ang,int p_state) {
	if (p_state != 1) {//jump中は飛沫上げない
		if (count % SPL_INTERVAL == 0) {
			for (int i = 0; i < SPL_NUM; i++) {
				if (!splashes[i].GetisExist()) {
					//printfDx("BORN!%d", i);
					splashes[i].Set(count, p_center, p_ang);
					break;
				}
			}
		}
	}
	for (int i = 0; i < SPL_NUM; i++) {
		if (splashes[i].GetisExist())splashes[i].Updata(count);
	}
}
void SplashMngDraw() {
	for (int i = 0; i < SPL_NUM; i++) {
		splashes[i].Draw();
	}
	//DrawModiGraph(0, 0, 300, 0, 300, 300, 0, 300, image, false);
}