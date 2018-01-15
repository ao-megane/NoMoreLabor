#ifndef PLAYER_H
#define PLAYER_H
#include"Obj.h"
#include"Input.h"

class Player
{
public:
	Player(){}
	~Player(){}
	void Initialize();
	void Updata(Input input,int Jflag);
	void Draw();
	void End();
	Dot GetPosi();
	Dot GetVelocity();
	Dot GetAccelerator();
	Dot GetForce();
	double GetAng();
	int GetWeight();

private:
	//Dot precenter;
	Dot center;
	Dot velocity;//�c�����݂̂�����int�ł悢�H
	Dot accelerator;
	Dot force;
	int weight;
	double ang;//�`��p�p�x
	int image;
};


#endif // !PLAYER_H
