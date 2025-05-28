#pragma once

#include "Emitter.h"

class BulletEmitter : public Emitter {
public:
	BulletEmitter(EmitterConfiguration& configuracion, Solid* particula) : Emitter(configuracion, particula) {};
	
	void Render();

	void Update(const float& time);
	Solid* Clone();

	void DispararBala();

};

