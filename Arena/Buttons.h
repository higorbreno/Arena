#ifndef BUTTONS_H
#define BUTTONS_H

#include "Types.h"
#include "Object.h"
#include "Sprite.h"

enum TypeButtons { ARROWL, ARROWR, BACK, CONTINUE, 
	CONTROLS, EFFECTS, PLAY, QUIT, RESTART, START };

class Buttons : public Object {

private:
	Sprite* button = nullptr;
	Sprite* sobre = nullptr;
	Sprite* atual = nullptr;
	bool mouseOver = false;

public:

	Buttons(float posx, float posy, uint tipo); //Construtor
	~Buttons(); //Destrutor

	bool MouseOver(bool aux);
	bool MouseOver();
	void Draw();
	void Update();

};

#endif

