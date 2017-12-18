#include"Player.h"
#include"Input.h"

int NormalImage;
void Player::Initialize() {
	center.Set(DISP_WIDTH / 2, DISP_HEIGHT / 2);
	velocity.Set(0,0);
	velocity.Updata();
	weight = 60;
	ang = PI / 2;
	NormalImage = LoadGraph("images/player/normal.png");
	image = NormalImage;
}

Dot decoi;
void Player::Updata(Input input,int Jflag) {
	//プレイヤー上向き時の処理（後で回す）
	if (input.GetKey(KEY_INPUT_W)) velocity.SetY(velocity.GetY() - 2);
	if (input.GetKey(KEY_INPUT_S) && velocity.GetY() < 0) velocity.SetY(velocity.GetY() + 2);
	if (input.GetKey(KEY_INPUT_A)) ang + PI / 12;
	if (input.GetKey(KEY_INPUT_D)) ang - PI/12;
	while (ang >= PI * 2)
		ang -= 2 * PI;
	while (ang < 0)
		ang += 2 * PI;

	velocity.SetY(velocity.GetY() * 0.999);

	velocity.Updata();
	center = center + velocity.Rotate(ang);

	if (input.GetKey(KEY_INPUT_C)) {
		center.Set(DISP_WIDTH / 2, DISP_HEIGHT / 2);
		velocity.Set(0, 0);
	}
}

Dot a;
Dot b;
Dot c;
Dot d;
void Player::Draw() {
	decoi.Set(- P_WIDTH / 2, - P_HEIGHT / 2);
	a = decoi.Rotate(ang) + center;
	decoi.Set(+ P_WIDTH / 2, - P_HEIGHT / 2);
	b = decoi.Rotate(ang) + center;
	decoi.Set(+ P_WIDTH / 2, + P_HEIGHT / 2);
	c = decoi.Rotate(ang) + center;
	decoi.Set(- P_WIDTH / 2, + P_HEIGHT / 2);
	d = decoi.Rotate(ang) + center;
	DrawModiGraph(
		a.GetX(), a.GetY(),
		b.GetX(), b.GetY(), 
		c.GetX(), c.GetY(), 
		d.GetX(), d.GetY(), 
		image,true
		);


}

void Player::End() {
	;
}