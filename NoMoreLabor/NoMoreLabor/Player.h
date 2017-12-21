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
	Dot GetVelocity();
	Dot GetAccelerator();
	Dot GetForce();
	double GetAng();
	int GetWeight();

private:
	//Dot precenter;
	Dot center;
	Dot velocity;//c•ûŒü‚Ì‚İ‚¾‚©‚çint‚Å‚æ‚¢H
	Dot accelerator;
	Dot force;
	int weight;
	double ang;//•`‰æ—pŠp“x
	int image;
};


#endif // !PLAYER_H
