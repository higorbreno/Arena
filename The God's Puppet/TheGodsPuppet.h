#ifndef THEGODSPUPPET_H
#define THEGODSPUPPET_H

#include "Game.h"
#include "Audio.h"
#include "Font.h"
#include "Resources.h"

enum Sounds { };

class TheGodsPuppet : public Game {
private:
	static Game* level;
public:

	static Audio* audio;
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

