#ifndef CONTROLS_H
#define CONTROLS_H
#include "Resources.h"
#include "Mouse.h"
#include "Buttons.h"

class Controls : public Game {
private:
	Sprite* background = nullptr;
	Buttons* back = nullptr;
	Mouse* mouse = nullptr;

public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};


#endif



#endif
