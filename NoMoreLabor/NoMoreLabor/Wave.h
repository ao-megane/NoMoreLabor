#ifndef WAVE_H
#define WAVE_H
#include"Obj.h"
#include"Value.h"

class Wave
{
public:
	Wave() {}
	~Wave() {}
	void Initialize();
	void Set(int count);
	int Updata(int count);
	void Draw();
	bool IsJump(Dot center);

private:
	Dot Point1;
	Dot Point2;
	bool dir_x;//�g�̐i�ޕ�����x�������Ȃ�true
	double ang;
	int image;
};

#endif // !WAVE_H
