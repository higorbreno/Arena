#ifndef THEGODSPUPPET_H
#define THEGODSPUPPET_H

#include "Game.h"
#include "Audio.h"
#include "Font.h"
#include "Resources.h"

enum Sounds { BUTTONOVER, MENU, FORESTAREA, SNOWAREA, 
	MINEAREA, SWAMPAREA, BLOODAREA, BOSSAREA, 
	BASICATTACK, BRANG, KBACK, HEAL, SPEED };

enum Inimigos { DEMON1, DEMON2, DEMON3, GHOST1, GHOST2, 
				GOBLIN1, GOBLIN2, GOBLIN3, GOBLIN4, GOBLIN5,
				ZOMBIE1, ZOMBIE2, ZOMBIE3, DEMONATTACK, ICEZOMBIEATTACK, MELEEATTACK};

class TheGodsPuppet : public Game {
private:
	static Game* level;
public:

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

