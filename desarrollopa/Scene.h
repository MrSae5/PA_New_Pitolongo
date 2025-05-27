#pragma once
#include <vector>
#include "Solid.h"
#include "Camera.h"
#include "Cuboid.h"
#include "Player.h"
#include "Text.h"

using namespace std;

class Scene
{
private:
	Camera camera;

public:
	//Getters & Setters
	inline Camera& GetCamera() { return this->camera; }
	inline void SetText(){}

	virtual void Render() = 0;
	virtual void Update() = 0;

	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClicked(int button, int state, int x, int y);
};

