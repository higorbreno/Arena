#include "Editor.h"
#include "MouseEditor.h"
#include <fstream>
using std::ifstream;
using std::ofstream;

std::list<EditorTile*> Editor::tiles;
Scene* Editor::scene = nullptr;

const string ARQUIVO = "3.lvl";

void Editor::Init()
{
	scene = new Scene();
	MouseEditor* mouse = new MouseEditor();
	scene->Add(mouse, MOVING);

	backg = new Background("Resources/Map.png");

	float difx = (game->Width() - window->Width()) / 2.0f;
	float dify = (game->Height() - window->Height()) / 2.0f;

	viewport.left = difx;
	viewport.right = difx + window->Width();
	viewport.top = dify;
	viewport.bottom = dify + window->Height();

	ifstream fin;
	fin.open(ARQUIVO);

	if (fin.is_open()) {
		int tilesCount;
		fin >> tilesCount;

		for (int i = 0; i < tilesCount; ++i) {
			int type, id;
			float x, y;
			fin >> type >> id >> x >> y;
			EditorTile* tile = new EditorTile(x, y, TileType(type), id);
			tile->MoveTo(x, y);
			scene->Add(tile, STATIC);
			tiles.push_back(tile);
		}
		fin.close();
	}
}

void Editor::Update()
{
	if (window->KeyDown('A')) {
		viewport.left -= 300 * gameTime;
		viewport.right -= 300 * gameTime;
	}
	if (window->KeyDown('D')) {
		viewport.left += 300 * gameTime;
		viewport.right += 300 * gameTime;
	}
	if (window->KeyDown('W')) {
		viewport.top -= 300 * gameTime;
		viewport.bottom -= 300 * gameTime;
	}
	if (window->KeyDown('S')) {
		viewport.top += 300 * gameTime;
		viewport.bottom += 300 * gameTime;
	}

	if (viewport.left < 0) {
		viewport.left = 0;
		viewport.right = window->Width();
	}
	if (viewport.top < 0) {
		viewport.top = 0;
		viewport.bottom = window->Height();
	}
	if (viewport.right > game->Width()) {
		viewport.right = game->Width();
		viewport.left = game->Width() - window->Width();
	}
	if (viewport.bottom > game->Height()) {
		viewport.bottom = game->Height();
		viewport.top = game->Height() - window->Height();
	}

	if (window->KeyPress('T'))
		createLevelFile();

	scene->Update();
	scene->CollisionDetection();
}

void Editor::Draw()
{
	backg->Draw(viewport);

	scene->Draw();
	//scene->DrawBBox();
}

void Editor::Finalize()
{
	delete scene;
	if (!EditorTile::objects.empty()) {
		for (auto block : EditorTile::objects) {
			if (block)
				delete block;
		}
		EditorTile::objects.clear();
	}
	if (!EditorTile::enemies.empty()) {
		for (auto enemy : EditorTile::enemies) {
			if (enemy)
				delete enemy;
		}
		EditorTile::enemies.clear();
	}
}

void Editor::createLevelFile()
{
	ofstream fout;

	fout.open(ARQUIVO);

	fout << tiles.size() << "\n";

	for (EditorTile* tile : tiles) {
		fout << tile->tileType << " " << tile->Id() << " " << tile->X() << " " << tile->Y() << "\n";
	}

	fout.close();
}