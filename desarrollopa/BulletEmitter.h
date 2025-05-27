#pragma once

#include "Emitter.h"

class BulletEmitter : public Emitter {
public:
	BulletEmitter() :Emitter() {};
	
	void Render();

	

	void Update(const float& time);
	Solid* Clone();

	void ProcessKeyPressed(unsigned char key, int px, int py);

};

