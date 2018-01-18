#include"Player.h"
#include"Input.h"

int NormalImage;
void Player::Initialize() {
	center.Set(DISP_WIDTH / 2, DISP_HEIGHT / 2);
	velocity.Set(0,0);
	velocity.Updata();
	accelerator.Set(0, 0);
	accelerator.Updata();
	force.Set(0, 0);
	force.Updata();
	weight = 60;
	ang = 0;
	NormalImage = LoadGraph("images/player/normal.png");
	image = NormalImage;
}

Dot decoi;
void Player::Updata(Input input,int Jflag) {
	force.Set(0, 0);//force初期化


	//プレイヤー上向き時の処理（後で回す）
	if (input.GetKey(KEY_INPUT_W)) accelerator.SetX(ACCELE);
	//else if (input.GetKey(KEY_INPUT_S)) velocity.Set(velocity.GetX()*0.7, velocity.GetY()*0.7);
	else if (input.GetKey(KEY_INPUT_S) && velocity.Rotate(-ang).GetX() > 1) accelerator.SetX(BRAKE);
	else accelerator.Set(0, 0);
	if (input.GetKey(KEY_INPUT_A)) ang += ADDED_ANGLE;
	if (input.GetKey(KEY_INPUT_D)) ang -= ADDED_ANGLE;

	while (ang >= PI * 2)
		ang -= 2 * PI;
	while (ang < 0)
		ang += 2 * PI;

	accelerator.Updata();
	if(velocity.GetAbs() < 50)//制限速度
		velocity = velocity + accelerator.Rotate(ang); //絶対速度
	//													↑加速の具合
	
	velocity.Set(velocity.Rotate(-ang).GetX() * DECAY_STRAIGHT, velocity.Rotate(-ang).GetY() *DECAY_SIDE);//相対速度
	//											↑縦方向の減衰						　↑横方向の減衰

	velocity = velocity.Rotate(ang);//絶対速度

	velocity.Updata();
	center = center + velocity;

	if (velocity.GetAbs() != 0) {
		force.SetX(-0.5 * weight * velocity.Rotate(-ang + PI / 2).GetX() * velocity.Rotate(-ang + PI / 2).GetX() / velocity.GetAbs() * 0.5);// 力 = (1/2mv^2)/変位
		force.SetY(0.5 * weight * velocity.Rotate(-ang + PI / 2).GetY() * velocity.Rotate(-ang + PI / 2).GetY() / velocity.GetAbs() * 0.5);// 力 = (1/2mv^2)/変位
		if (velocity.Rotate(-ang + PI / 2).GetX() < 0) force.SetX(-force.GetX());
		if (velocity.Rotate(-ang + PI / 2).GetY() < 0) force.SetY(-force.GetY());
	}

	if (input.GetKey(KEY_INPUT_C)) {
		center.Set(DISP_WIDTH / 2, DISP_HEIGHT / 2);
		velocity.Set(0, 0);
	}//位置初期化
	if (center.GetX() > DISP_WIDTH) center.SetX(0);
	if (center.GetX() < 0) center.SetX(DISP_WIDTH);
	if (center.GetY() > DISP_HEIGHT) center.SetY(0);
	if (center.GetY() < 0) center.SetY(DISP_HEIGHT);
	//ループ処理

	force = force + accelerator.Rotate(PI / 2) * weight;
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

Dot Player::GetPosi() {
	return center;
}
Dot Player::GetVelocity() {
	return velocity;
}
Dot Player::GetAccelerator() {
	return accelerator;
}
Dot Player::GetForce() {
	return force;
}
double Player::GetAng() {
	return ang;
}
int Player::GetWeight() {
	return weight;
}


