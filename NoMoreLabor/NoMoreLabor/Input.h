#ifndef INPUT_H
#define INPUT_H
#include"Obj.h"
#include"Value.h"

class Input
{
public:
	Input();
	~Input();
	void MouseUpdata();
	void KeyUpdata();
	void Updata();
	void DrawMouse();
	void DrawKey();
private:
	Dot m;
	int key[KEY_NUM];
};

Input::Input()
{
}

Input::~Input()
{
}


#endif // !INPUT_H
