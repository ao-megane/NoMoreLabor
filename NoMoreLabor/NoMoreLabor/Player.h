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
	Dot velocity;//ècï˚å¸ÇÃÇ›ÇæÇ©ÇÁintÇ≈ÇÊÇ¢ÅH
	Dot accelerator;
	Dot force;
	int weight;
	double ang;//ï`âÊópäpìx
	int image;
};


#endif // !PLAYER_H
