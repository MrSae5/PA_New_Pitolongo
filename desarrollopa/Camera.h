#pragma once
#include "Solid.h"
class Camera : public Solid
{
private:

public:
	Camera() {}

	void Render();
	Solid* Clone();
};


