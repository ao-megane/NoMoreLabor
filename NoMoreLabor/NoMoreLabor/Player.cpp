#include"Player.h"
#include"Input.h"

int NormalImage;
void Player::Initialize() {
	center.Set(DISP_WIDTH / 2, DISP_HEIGHT / 2);
	velocity.Set(0,0);
	velocity.Updata();
	accelerator.Set(0, 0);
	accelerator.Updata();
	weight = 60;
	ang = 0;
	NormalImage = LoadGraph("images/player/normal.png");
	image = NormalImage;
}

Dot decoi;
void Player::Updata(Input input,int Jflag) {
	//プレイヤー上向き時の処理（後で回す）
	if (input.GetKey(KEY_INPUT_W)) accelerator.SetX(1);
	else if (input.GetKey(KEY_INPUT_S) && velocity.GetY() < 0) accelerator.SetX(-1);
	else accelerator.Set(0, 0);
	if (input.GetKey(KEY_INPUT_A)) ang += PI / 12.0;
	if (input.GetKey(KEY_INPUT_D)) ang -= PI / 12.0;

	while (ang >= PI * 2)
		ang -= 2 * PI;
	while (ang < 0)
		ang += 2 * PI;

	if(velocity.GetAbs() < 50)
		velocity = velocity + accelerator.Rotate(ang) * 3.0; //絶対速度

	velocity.Set(velocity.Rotate(-ang).GetX(), velocity.Rotate(-ang).GetY() * 0.5);//相対速度

	velocity = velocity.Rotate(ang);//絶対速度

	//velocity.Set(velocity.GetX() * 0.9, velocity.GetY() * 0.9);
	//velocity.Set(velocity.GetX(),velocity.GetY());
	velocity.Updata();
	center = center + velocity;

	if (input.GetKey(KEY_INPUT_C)) {
		center.Set(DISP_WIDTH / 2, DISP_HEIGHT / 2);
		velocity.Set(0, 0);
	}
	if (center.GetX() > DISP_WIDTH) center.SetX(0);
	if (center.GetX() < 0) center.SetX(DISP_WIDTH);
	if (center.GetY() > DISP_HEIGHT) center.SetY(0);
	if (center.GetY() < 0) center.SetY(DISP_HEIGHT);
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

Dot Player::GetVelocity() {
	return velocity;
}