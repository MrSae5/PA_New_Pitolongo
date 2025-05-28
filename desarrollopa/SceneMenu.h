#pragma once
#include <GL/glut.h>
#include <string>
#include "Scene.h"
#include "Cuboid.h"

class SceneMenu : public Scene //Hereda de Scene
{
private:
	Cuboid* button; // Un cubo que hará de botón
	Text texto;

public:
	// void AddGameObject(Solid* gameObject); 

    SceneMenu() {
		
		button = new Cuboid(0.2f, 1.0f, 3.0f, Vector3D(0, 0, -5), Vector3D(0, 90, 180), Color(1, 0, 0, 1), Vector3D(0, 0, 0));

		texto.SetPosition(Vector3D(-0.03, 0, -1));
		texto.SetText("Play");
    }

	~SceneMenu() { delete button; };

	bool IsClickInsideButton(int x, int y);

	void Render() override;
	void Update() override;
};

