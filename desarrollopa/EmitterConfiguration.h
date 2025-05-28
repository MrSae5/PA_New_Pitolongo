#pragma once
#include <GL/glut.h>
#include "Solid.h"
#include "Teapot.h"
#include "Sphere.h"

class EmitterConfiguration
{
private:
	int numParticulas;
	int miliSeconds;
	Solid* particula;

public:
	EmitterConfiguration(int particulasToSet, int miliSecondsToSet) 
	{ 
		SetnumParticulas(particulasToSet);
		SetmiliSeconds(miliSecondsToSet);
	}

	//Constructor de copia profunda
	EmitterConfiguration(const EmitterConfiguration& other) {
		numParticulas = other.numParticulas;
		miliSeconds = other.miliSeconds;
		particula = other.particula ? other.particula->Clone() : nullptr;
	}

	inline int GetnumParticulas() { return this->numParticulas; }
	void SetnumParticulas(int particulasToSet) { this->numParticulas = particulasToSet; }

	inline int GetmiliSeconds() { return this->miliSeconds; }
	void SetmiliSeconds(int miliSecondsToSet) { this->miliSeconds = miliSecondsToSet; }

	inline Solid* GetParticula() { return this->particula; }
	void SetParticula(Solid* particulaToSet) { this->particula = particulaToSet; }

};

