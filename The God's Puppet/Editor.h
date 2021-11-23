#include "Game.h"
#include "Scene.h"
#include "Audio.h"
#include "EditorTile.h"
#include "Background.h"

#ifndef EDITOR_H
#define EDITOR_H

class Editor : public Game {
private:
    Background* backg;

public:
    static std::list<EditorTile*> tiles;
    static Scene* scene;

    void Init();                        // inicialização
    void Update();                      // atualização
    void Draw();                        // desenho
    void Finalize();                    // finalização
    void createLevelFile();
};

#endif // !LEVELCREATOR_H