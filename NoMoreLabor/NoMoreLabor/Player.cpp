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
	state = 1;			//�W�����v��Ԃ�
	bodyClock = count;	//�A�j���[�V�����̃X�^�[�g�N���b�N�̕ێ�
}
void Player::UpdataJump(int count) {
	enlarge = 1.0 + sin(PI / JUMPING_TIME * (count - bodyClock));	//�g�嗦�̍X�V
	center = center + velocity;										//�ړ�

	/*-------------���[�v����-------------------*/
	if (center.GetX() > DISP_WIDTH) center.SetX(0);					
	if (center.GetX() < 0) center.SetX(DISP_WIDTH);
	if (center.GetY() > DISP_HEIGHT) center.SetY(0);
	if (center.GetY() < 0) center.SetY(DISP_HEIGHT);

	if ((count - bodyClock) >= JUMPING_TIME) {	//�w�莞�ԉ߂����猳�̏�Ԃ�
		enlarge = 1.0;
		state = 0;
	}
}

Dot decoi;
void Player::Updata(Input input,bool Jflag,int count) {

	/*----------�W�����v����-------------*/
	if (Jflag && GetState() == 0) {
		//printfDx("JUMP!!!");
		SetJump(count);
	}
	if (GetState() == 1) {
		UpdataJump(count);
		return;
	}

	force.Set(0, 0);	//force������

	/*---�v���C���[����Ɍ������Ɖ��肵�āA���͂ɑΉ������e�ϐ��̍X�V�i��ŉ񂷁j---*/
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
	if (velocity.GetAbs() < LIMIT)	//�������x�ȏ�ɂȂ�Ȃ��悤�ɏ���
		velocity = velocity + accelerator.Rotate(ang);	//���x�ɉ����x�����Z
	
	velocity.Set(velocity.Rotate(-ang).GetX() * DECAY_STRAIGHT, velocity.Rotate(-ang).GetY() *DECAY_SIDE);	//�c���ɉ�������R���|���Z

	velocity = velocity.Rotate(ang);	//���x���v���C���[���猩�����x�����ʂɑΉ��������x�֕ϊ��i��R���j

	velocity.Updata();
	center = center + velocity;			//���x��ψʂɉ��Z

	if (velocity.GetAbs() != 0) {		//�͂��X�V
		force.SetX(-0.5 * weight * velocity.Rotate(-ang + PI / 2).GetX() * velocity.Rotate(-ang + PI / 2).GetX() / velocity.GetAbs() * 0.5);	// �� = (1/2mv^2)/�ψ�
		force.SetY(0.5 * weight * velocity.Rotate(-ang + PI / 2).GetY() * velocity.Rotate(-ang + PI / 2).GetY() / velocity.GetAbs() * 0.5);		// �� = (1/2mv^2)/�ψ�
		if (velocity.Rotate(-ang + PI / 2).GetX() < 0) force.SetX(-force.GetX());	//��Βl�𕄍��t�֕ϊ�
		if (velocity.Rotate(-ang + PI / 2).GetY() < 0) force.SetY(-force.GetY());
	}

	if (input.GetKey(KEY_INPUT_C)) {	//�v���C���[�ʒu�A���x�����Z�b�g
		center.Set(DISP_WIDTH / 2, DISP_HEIGHT / 2);
		velocity.Set(0, 0);
	}

	/*-------------���[�v����-------------------*/
	if (center.GetX() > DISP_WIDTH) center.SetX(0);
	if (center.GetX() < 0) center.SetX(DISP_WIDTH);
	if (center.GetY() > DISP_HEIGHT) center.SetY(0);
	if (center.GetY() < 0) center.SetY(DISP_HEIGHT);

	//�j���[�g���̉^��������
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
	DrawModiGraph(	//���R�l�p�`�`��
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


