#ifndef Effects_H
#define Effects_H

#include "Resources.h"
#include "Mouse.h"
#include "Buttons.h"

class Effects : public Game {
private:
	Sprite* background;
	Sprite* backgrounds[6];
	Buttons* back = nullptr;
	Buttons* arrowR = nullptr;
	Buttons* arrowL = nullptr;
	int contagem = 0;
	Mouse* mouse = nullptr;

public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};


#endif
