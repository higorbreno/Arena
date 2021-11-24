#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "Resources.h"
#include "Mouse.h"
#include "Buttons.h"

class GameOver : public Game {
private:

	Sprite* background = nullptr;
	Buttons* restart = nullptr;
	Buttons* back = nullptr;
	Mouse* mouse = nullptr;

public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};


#endif

