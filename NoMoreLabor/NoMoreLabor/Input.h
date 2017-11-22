#ifndef INPUT_H
#define INPUT_H
#include"Obj.h"
#include"Value.h"

class Input
{
public:
	Input() {}
	~Input() {}
	void MouseUpdata();
	void KeyUpdata();
	void Updata();
	int GetKey(int code);
	int GetClick();
	Dot GetMouse();
	void DrawMouse();
	void DrawKey();
private:
	Dot m;
	int click;
	int key[256];
};

//Input::Input(){
//	//m = Dot();
//	key[256] = { 0 };
//}
//
//Input::~Input(){
//	//m.~Dot();
//	key[256] = { 0 };
//}


#endif // !INPUT_H
