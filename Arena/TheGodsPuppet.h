#ifndef THEGODSPUPPET_H
#define THEGODSPUPPET_H

#include "Game.h"
#include "Audio.h"
#include "Font.h"
#include "Resources.h"

enum Sounds { BUTTONOVER, MENU, BOSSAREA, 
	BASICATTACK, BRANG, KBACK, HEAL, SPEED };

enum Inimigos { DEMON1, DEMON2, DEMON3, GHOST1, GHOST2, 
				GOBLIN1, GOBLIN2, GOBLIN3, GOBLIN4, GOBLIN5,
				ZOMBIE1, ZOMBIE2, ZOMBIE3, DEMONATTACK, ICEZOMBIEATTACK, MELEEATTACK};

class TheGodsPuppet : public Game {
private:
	static Game* level;

public:
	static Font* arcade15;
	static Font* arcade30;
	static Font* arcade55;
	static Audio* audio;
	static Audio* inimigosAudio;

	static bool viewBBox;

	template<class T>
	static void NextLevel() {
		if (level) {
			level->Finalize();
			delete level;
			level = new T();
			level->Init();
		}
	};

	void Init();
	void Update();
	void Draw();
	void Finalize();
};

#endif

