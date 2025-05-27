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
	Emitter() : Solid()
	{

		this->configuracion = new EmitterConfiguration();
		this->configuracion->Setparticula(new Teapot);
		this->configuracion->Setparticula(new Sphere);
		this->initialMilliseconds = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		this->lastUpdatedTime = 0;
		this->angulo = 0;
	}
	
	void Render();

	void Update();
	void Update(const float& time);
	Solid* Clone();
};


