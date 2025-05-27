#pragma once
#include "Display.h"
#include "Scene.h"
#include "SceneGame.h"
#include "SceneMenu.h"
#include "Triangle.h"
#include "Model.h"
#include "ModelLoader.h"
#include "Player.h" 
#include <chrono>

using namespace std;
using namespace std::chrono;

class Game
{
private:

	const double TIME_INCREMENT = 0.4; //ms tiempo en el juego 
	const long UPDATE_PERIOD = 10; //ms tiempo en el mundo real 

	milliseconds initialMilliseconds;
	long lastUpdatedTime;

	vector<Scene*> scenes;
	Scene* activeScene;


public:

	Game() : activeScene(nullptr), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdatedTime(0) { }

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClicked(int button, int state, int x, int y);
};

