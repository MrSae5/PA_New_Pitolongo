#pragma once
#include "Solid.h"
#include <GL/glut.h>

class Triangle : public Solid
{

private:

	Vector3D vertex0;
	Vector3D vertex1;
	Vector3D vertex2;
	Vector3D normal0;
	Vector3D normal1;
	Vector3D normal2;
	Color color0;
	Color color1;
	Color color2;

public:

	Triangle(
		Vector3D vertex0Argument = Vector3D(),
		Vector3D vertex1Argument = Vector3D(),
		Vector3D vertex2Argument = Vector3D(),
		Vector3D normal0Argument = Vector3D(),
		Vector3D normal1Argument = Vector3D(),
		Vector3D normal2Argument = Vector3D(),
		Color color0Argument = Color(1,0,0,1),
		Color color1Argument = Color(0,1,0,1),
		Color color2Argument = Color(0,0,1,1)) :
		vertex0(vertex0Argument), vertex1(vertex1Argument), vertex2(vertex2Argument),
		normal0(normal0Argument), normal1(normal1Argument), normal2(normal2Argument),
		color0(color0Argument), color1(color1Argument), color2(color2Argument)
	{}

	inline Vector3D GetVertex0() const { return this->vertex0; }
	inline void SetVertex0(const Vector3D& vertexToSet) { this->vertex0 = vertexToSet; }

	inline Vector3D GetVertex1() const { return this->vertex1; }
	inline void SetVertex1(const Vector3D& vertexToSet) { this->vertex1 = vertexToSet; }

	inline Vector3D GetVertex2() const { return this->vertex2; }
	inline void SetVertex2(const Vector3D& vertexToSet) { this->vertex2 = vertexToSet; }

	inline Vector3D GetNormal0() const { return this->normal0; }
	inline void SetNormal0(const Vector3D& normalToSet) { this->normal0 = normalToSet; }

	inline Vector3D GetNormal1() const { return this->normal1; }
	inline void SetNormal1(const Vector3D& normalToSet) { this->normal1 = normalToSet; }

	inline Vector3D GetNormal2() const { return this->normal2; }
	inline void SetNormal2(const Vector3D& normalToSet) { this->normal2 = normalToSet; }

	inline Color GetColor0() const { return this->color0; }
	inline void SetColor0(const Color& colorToSet) { this->color0 = colorToSet; }

	inline Color GetColor1() const { return this->color1; }
	inline void SetColor1(const Color& colorToSet) { this->color1 = colorToSet; }

	inline Color GetColor2() const { return this->color2; }
	inline void SetColor2(const Color& colorToSet) { this->color2 = colorToSet; }

	void Render() override;
	Solid* Clone();

};

