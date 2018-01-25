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
}

void Splash::Set(int count, Dot p_center, int p_ang) {
	bodyClock = count;
	center = p_center;
	ang = p_ang;
	isExist = true;
}

int Splash::Updata(int count) {
	enlarge = 1.0 + sin(PI / SPL_LIFETIME / 2 * (count - bodyClock));//‚±‚±‰ö‚µ‚¢

	if ((count - bodyClock) >= SPL_LIFETIME) {
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
}

Splash splashes[SPL_NUM];
void SplashMngInitialize() {
	for (int i = 0; i < SPL_NUM; i++) {
		splashes[i].Initialize();
	}
	image = LoadGraph("images/splash/normal.png");
}
void SplashMngUpdata(int count, Dot p_center,int p_ang) {
	if (count % SPL_INTERVAL) {
		for (int i = 0; i < SPL_NUM; i++) {
			if (!splashes[i].GetisExist()) {
				splashes[i].Set(count, p_center, p_ang);
				break;
			}
		}
	}
}
void SplashMngDraw() {
	for (int i = 0; i < SPL_NUM; i++) {
		splashes[i].Draw();
	}
}