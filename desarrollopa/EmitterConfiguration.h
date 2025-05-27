#pragma once
#include <GL/glut.h>
#include "Solid.h"
#include "Teapot.h"
#include "Sphere.h"

class EmitterConfiguration
{
private:
	int numTeteras;
	int miliSeconds;
	Solid* particula;

public:
	EmitterConfiguration() : numTeteras(0), miliSeconds(500) { }

	 inline int GetnumTeteras() { return this->numTeteras; }
	 void SetnumTeteras(int teterasToSet) { this->numTeteras = teterasToSet; }

	 inline int GetmiliSeconds() { return this->miliSeconds; }
	 void SetmiliSeconds(int miliSecondsToSet) { this->miliSeconds = miliSecondsToSet; }

	 inline Solid* GetParticula() { return this->particula; }
	 void Setparticula(Solid* particulaToSet) { this->particula = particulaToSet; }

};

