#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Torus : public Solid
{
private:
	float internalRadius;
	float externalRadius;
	int faces;
	int rings;

public:
	Torus():internalRadius(0.2), externalRadius(0.4), faces(16), rings(16), Solid() {}

	inline float GetInternalRadius() const { return this->internalRadius; }
	inline void SetInternalRadius(const float& internalRadiusToSet) { this->internalRadius = internalRadiusToSet; }

	inline float GetExternalRadius() const { return this->externalRadius; }
	inline void SetExternalRadius(const float& externalRadiusToSet) { this->externalRadius = externalRadiusToSet; }

	inline int GetFaces() const { return this->faces; }
	inline void SetFaces(const int& facesToSet) { this->faces = facesToSet; }

	inline int GetRings() const { return this->rings; }
	inline void SetRings(const int& ringsToSet) { this->rings = ringsToSet; }

	void Render();

	Solid* Clone();
};

