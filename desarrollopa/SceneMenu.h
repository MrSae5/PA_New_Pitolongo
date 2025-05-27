#pragma once
#include <GL/glut.h>
#include <string>
#include "Scene.h"
#include "Cuboid.h"

class SceneMenu : public Scene //Hereda de Scene
{
private:
	Cuboid button; // Un cubo que hará de botón
	Text texto;

public:
	// void AddGameObject(Solid* gameObject); 

    SceneMenu() {
		button.SetPosition(Vector3D (0, 0, -5));
		button.SetOrientation(Vector3D (0, 90, 180));
		button.SetColor(Color(1, 0, 0, 1));
		button.SetWidth(3.0);
		button.SetHeight(1.);

		texto.SetPosition(Vector3D(-0.03, 0, -1));
		texto.SetText("Play");
    }

	bool IsClickInsideButton(int x, int y);

	void Render() override;
	void Update() override;
};

