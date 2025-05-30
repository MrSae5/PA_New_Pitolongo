#include "BulletEmitter.h"
#include <iostream>


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;



void BulletEmitter::Update(const float& time) {

	Emitter::Update(time);
}


void BulletEmitter::Render(){
	Emitter::Render();
}


Solid* BulletEmitter::Clone() {
	return new BulletEmitter(*this);

};

void BulletEmitter::DispararBala() {

	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	
	Solid* particle = this->configuracion->GetParticula()->Clone();

	particle->SetOrientation(this->GetOrientation());


    const float bulletSpeed = 0.2f; // ajustar aquí
    Vector3D velocidad = Vector3D(
        bulletSpeed * cos((GetOrientation().GetZ() - 90.0f) * M_PI / 180.0f),
        bulletSpeed * sin((GetOrientation().GetZ() - 90.0f) * M_PI / 180.0f),
        0
    );

	particle->SetSpeed(velocidad);
	particle->SetOrientationSpeed(Vector3D(0, 0, 0));

	float red = fabs(velocidad.GetX()) * 50.0f;  // Multiplicamos para hacer los colores más perceptibles
	float green = fabs(velocidad.GetY()) * 50.0f;
	float blue = 0.0f; //Se queda en 0 ya que no hay velocidad en Z
	particle->SetColor(Color(red, green, blue, 1.0f));

	particle->SetPosition(this->GetPosition());

	this->particulas.push_back(particle);

	//se reinicia el contador de tiempo
	this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();

	cout << this->lastUpdatedTime << endl;

}
