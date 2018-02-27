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
	enlarge = 1;
	state = 0;
}

void Player::Set(int flag) {
	velocity.Set(0, 0);
	velocity.Updata();
	accelerator.Set(0, 0);
	accelerator.Updata();
	force.Set(0, 0);
	force.Updata();
	image = NormalImage;
	enlarge = 1;
	state = 0;
	switch (flag) {//map1 or map2
	case 1:
		ang = 0;
		center.Set(DISP_WIDTH / 2, DISP_HEIGHT / 2);
		break;
	case 2:
		ang = PI;
		center.Set(DISP_WIDTH - 100, 75);
		break;
	}
}

void Player::SetJump(int count) {
	state = 1;			//ジャンプ状態へ
	bodyClock = count;	//アニメーションのスタートクロックの保持
}
void Player::UpdataJump(int count) {
	enlarge = 1.0 + sin(PI / JUMPING_TIME * (count - bodyClock));	//拡大率の更新
	center = center + velocity;										//移動

	/*-------------ループ処理-------------------*/
	if (center.GetX() > DISP_WIDTH) center.SetX(0);					
	if (center.GetX() < 0) center.SetX(DISP_WIDTH);
	if (center.GetY() > DISP_HEIGHT) center.SetY(0);
	if (center.GetY() < 0) center.SetY(DISP_HEIGHT);

	if ((count - bodyClock) >= JUMPING_TIME) {	//指定時間過ぎたら元の状態へ
		enlarge = 1.0;
		state = 0;
	}
}

Dot decoi;
void Player::Updata(Input input,bool Jflag,int count) {

	/*----------ジャンプ処理-------------*/
	if (Jflag && GetState() == 0) {
		//printfDx("JUMP!!!");
		SetJump(count);
	}
	if (GetState() == 1) {
		UpdataJump(count);
		return;
	}

	force.Set(0, 0);	//force初期化

	/*---プレイヤーを上に向けたと仮定して、入力に対応した各変数の更新（後で回す）---*/
	if (input.GetKey(KEY_INPUT_W)) accelerator.SetX(ACCELE);
	else if (input.GetKey(KEY_INPUT_S) && velocity.Rotate(-ang).GetX() > 1) accelerator.SetX(BRAKE);
	else accelerator.Set(0, 0);
	if (input.GetKey(KEY_INPUT_A) && velocity.GetAbs() != 0) ang += ADDED_ANGLE;
	if (input.GetKey(KEY_INPUT_D) && velocity.GetAbs() != 0) ang -= ADDED_ANGLE;

	while (ang >= PI * 2)
		ang -= 2 * PI;
	while (ang < 0)
		ang += 2 * PI;

	accelerator.Updata();
	if (velocity.GetAbs() < LIMIT)	//制限速度以上にならないように処理
		velocity = velocity + accelerator.Rotate(ang);	//速度に加速度を加算
	
	velocity.Set(velocity.Rotate(-ang).GetX() * DECAY_STRAIGHT, velocity.Rotate(-ang).GetY() *DECAY_SIDE);	//縦横に応じた抵抗を掛け算

	velocity = velocity.Rotate(ang);	//速度をプレイヤーから見た速度から画面に対応した速度へ変換（抵抗込）

	velocity.Updata();
	center = center + velocity;			//速度を変位に加算

	if (velocity.GetAbs() != 0) {		//力を更新
		force.SetX(-0.5 * weight * velocity.Rotate(-ang + PI / 2).GetX() * velocity.Rotate(-ang + PI / 2).GetX() / velocity.GetAbs() * 0.5);	// 力 = (1/2mv^2)/変位
		force.SetY(0.5 * weight * velocity.Rotate(-ang + PI / 2).GetY() * velocity.Rotate(-ang + PI / 2).GetY() / velocity.GetAbs() * 0.5);		// 力 = (1/2mv^2)/変位
		if (velocity.Rotate(-ang + PI / 2).GetX() < 0) force.SetX(-force.GetX());	//絶対値を符号付へ変換
		if (velocity.Rotate(-ang + PI / 2).GetY() < 0) force.SetY(-force.GetY());
	}

	if (input.GetKey(KEY_INPUT_C)) {	//プレイヤー位置、速度をリセット
		center.Set(DISP_WIDTH / 2, DISP_HEIGHT / 2);
		velocity.Set(0, 0);
	}

	/*-------------ループ処理-------------------*/
	if (center.GetX() > DISP_WIDTH) center.SetX(0);
	if (center.GetX() < 0) center.SetX(DISP_WIDTH);
	if (center.GetY() > DISP_HEIGHT) center.SetY(0);
	if (center.GetY() < 0) center.SetY(DISP_HEIGHT);

	//ニュートンの運動方程式
	force = force + accelerator.Rotate(PI / 2) * weight;
}

Dot a;
Dot b;
Dot c;
Dot d;
void Player::Draw() {
	decoi.Set(- P_WIDTH / 2, - P_HEIGHT / 2);
	a = decoi.Rotate(ang) * enlarge + center;
	decoi.Set(+ P_WIDTH / 2, - P_HEIGHT / 2);
	b = decoi.Rotate(ang) * enlarge + center;
	decoi.Set(+ P_WIDTH / 2, + P_HEIGHT / 2);
	c = decoi.Rotate(ang) * enlarge + center;
	decoi.Set(- P_WIDTH / 2, + P_HEIGHT / 2);
	d = decoi.Rotate(ang) * enlarge + center;
	DrawModiGraph(	//自由四角形描画
		a.GetX(), a.GetY(),
		b.GetX(), b.GetY(), 
		c.GetX(), c.GetY(), 
		d.GetX(), d.GetY(), 
		image, true
		);
}

void Player::End() {
	;
}

Dot Player::GetCenter() {
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
int Player::GetState() {
	return state;
}


