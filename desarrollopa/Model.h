#pragma once
#include <vector>
#include "Solid.h"
#include "Triangle.h"
#include <GL/glut.h>

using namespace std;

class Model : public Solid
{
private:
	vector<Triangle> triangles;

public:

	//modelos que se mueven
	Model(const Model& other, const Vector3D& position, const Vector3D& orientation, const Color& color, const Vector3D& speed)
		: Solid(color, position, orientation, speed) {

		// Copia triángulos
		this->triangles = other.triangles;
		this->SetPosition(position);
		this->SetColor(color);
		this->SetOrientation(orientation);
		this->SetSpeed(speed);
	}


	Model(const Vector3D& position, const Vector3D& orientation, const Color& color) : Solid(color, position, orientation) {

		this->SetColor(color);
		this->SetPosition(position);
		this->SetOrientation(orientation);
	}

	Solid* Clone();
	void Render();

	void AddTriangle(Triangle triangle);
	void Clear();

	void SetColor(Color colorToSet) override;

	Model(const vector<Triangle>& triangles, const Vector3D& position,
		const Vector3D& orientation, const Color& color) : triangles(triangles), Solid(color, position,
			orientation) { }

	Model() = default;
};

