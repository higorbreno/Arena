#ifndef MENU_H
#define MENU_H

#include "Resources.h"
#include "Mouse.h"
#include "Buttons.h"
#include "Animation.h"

class Menu : public Game {
private:
	Sprite* background = nullptr;
	TileSet* tileset = nullptr;
	Animation* animacao = nullptr;
	Buttons* play = nullptr;
	Buttons* controls = nullptr;
	Buttons* effects = nullptr;
	Buttons* quit = nullptr;
	Mouse* mouse = nullptr;

public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};


#endif
