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

	Cuboid() : Solid(), length(0.2f), height(1.4f), width(1.0f)
	{}

	Cuboid(float length, float height, float width, const Vector3D& position, const Vector3D& orientation, const Color& color, const Vector3D& speed) 
		: Solid(color, position, orientation, speed)
	{
		SetLength(length);
		SetHeight(height);
		SetWidth(width);
	}

	inline float GetLength() { return this->length; }
	inline float GetHeight() { return this->height; }
	inline float GetWidth() { return this->width; }

	void SetLength(float lengthToSet) { this->length = lengthToSet; }
	void SetHeight(float heightToSet) { this->height = heightToSet; }
	void SetWidth(float widthToSet) { this->width = widthToSet; }

	void Render();

	Solid* Clone();

};

