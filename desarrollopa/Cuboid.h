#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Cuboid : public Solid
{
private:

	float length;
	float height;
	float width;

public:

	Cuboid() : Solid(), length(0.2), height(1.4), width(1.0)
	{}

	inline float GetLength() { return this->length; }
	inline float GetHeight() { return this->height; }
	inline float GetWidth() { return this->width; }

	void SetLength(float lengthToSet) { this->length = lengthToSet; }
	void SetHeight(float heightToSet) { this->height = heightToSet; }
	void SetWidth(float widthToSet) { this->width = widthToSet; }

	void Render();

	Solid* Clone();

};

