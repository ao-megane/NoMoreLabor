#ifndef PLAYER_H
#define PLAYER_H
#include"Obj.h"
#include"Input.h"
#include"Value.h"

class Player
{
public:
	Player(){}
	~Player(){}
	void Initialize();
	void Updata(Input input,bool Jflag, int count);
	void SetJump(int count);
	void UpdataJump(int count);
	void Draw();
	void End();
	Dot GetCenter();
	Dot GetVelocity();
	Dot GetAccelerator();
	Dot GetForce();
	double GetAng();
	int GetWeight();
	int GetState();

private:
	//Dot precenter;
	Dot center;
	Dot velocity;//ècï˚å¸ÇÃÇ›ÇæÇ©ÇÁintÇ≈ÇÊÇ¢ÅH
	Dot accelerator;
	Dot force;
	int weight;
	int state;//0 normal 1 jumping
	int bodyClock;
	double enlarge;
	double ang;//ï`âÊópäpìx
	int image;
};


#endif // !PLAYER_H
