#include "Game.h"
#include <iostream>
#include <chrono>

using namespace std::chrono;


void Game::Init()
{
	cout << "[GAME] Init..." << endl;
	SceneMenu* scene1 = new SceneMenu(); //Menú de juego
	SceneGame* scene2 = new SceneGame(); //Juego
	SceneMenu* scene3 = new SceneMenu(); //Pantalla de perder/ganar

	// Crear el jugador

	Player* player1 = new Player();

	// Añadir el jugador a la escena como objeto del juego
	scene2->AddPlayer(player1);


	this->scenes.push_back(scene1);
	this->scenes.push_back(scene2);
	this->scenes.push_back(scene3);
	this->activeScene = scene1; // Se cambiará al menú cuando esté implementado

}

void Game::Render()
{
	this->activeScene->Render();
}

void Game::Update()
{
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdatedTime > UPDATE_PERIOD)
	{
		//this->activeScene->Update(TIME_INCREMENT); 
		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	}

	//actualizamos el estado de la escena que esté en uso
	this->activeScene->Update();
}

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
	cout << "tecla pulsada: " << key << endl;


	SceneGame* sceneGame = dynamic_cast<SceneGame*>(activeScene);
	if (sceneGame) { // Verificamos que activeScene sea SceneGame
		sceneGame->GetPlayer()->ProcessKeyPressed(key, px, py);
	}

}

void Game::ProcessMouseClicked(int button, int state, int x, int y)
{
	cout << "[GAME] Click:" << button << endl;

	if (state == 0) { // 0 = clic presionado en GLUT
		SceneMenu* sceneMenu = dynamic_cast<SceneMenu*>(activeScene);
		if (sceneMenu && sceneMenu->IsClickInsideButton(x, y)) {
			cout << "[GAME] Click en el botón, cambiando a SceneGame..." << endl;
			activeScene = scenes[1]; // Cambia a SceneGame
		}
	}
}

void Game::ProcessMouseMovement(int x, int y)
{
	cout << "[GAME] Movement:" << x << ", " << y << endl;
}
