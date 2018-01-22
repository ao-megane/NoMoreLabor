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
	intDot GetMouse();
	void DrawMouse();
	void DrawKey();
private:
	intDot m;
	int click;
	int key[256];
};

#endif // !INPUT_H
