#pragma once
#include <GL/glut.h>
#include <vector>
#include "Emitterconfiguration.h"
#include <chrono>

using namespace std;
using namespace chrono;

class Emitter : public Solid
{
private:
protected:
	EmitterConfiguration* configuracion;
	vector<Solid*> particulas;
	milliseconds initialMilliseconds;
	long lastUpdatedTime;
	float angulo;

public:

	Emitter(EmitterConfiguration& configuracionToSet, Solid* particula) : Solid()
	{
		this->configuracion = new EmitterConfiguration(configuracionToSet); 
		this->configuracion->SetParticula(particula);
	}

	void Render();

	void Update();
	void Update(const float& time);
	Solid* Clone();
};


