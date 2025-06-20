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
	//currentTime es el tiempo desde 1970 (tiempo donde windows comenz� a contar) y se lo resta a initialMilliseconds
	//que es el tiempo en milisegundos hasta ahora, y eso se lo resta al tiempo transcurrido desde al �ltima iteraci�n
	//de una part�cula y se compara con el periodo de emisi�n
	//&& (currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdatedTime > this->configuracion->GetmiliSeconds()
	
	Solid* particle = this->configuracion->GetParticula()->Clone();


	//if (this->angulo >= 360.0f) this->angulo -= 360.0f;
	//this->angulo += 20.0f;


	//double radianes = angulo * (3.14159265358979323846 / 180.0);
	//double seno = sin(radianes);
	//double coseno = cos(radianes);

	particle->SetOrientation(this->GetOrientation());


    const float bulletSpeed = 0.2f; // ajustar aqu�
    Vector3D velocidad = Vector3D(
        bulletSpeed * cos((GetOrientation().GetZ() - 90.0f) * M_PI / 180.0f),
        bulletSpeed * sin((GetOrientation().GetZ() - 90.0f) * M_PI / 180.0f),
        0
    );



	//Vector3D velocidad = Vector3D(seno * 0.01, coseno * 0.01, 0); //Se crea una variable para que sea m�s f�cil darle el color despu�s
	particle->SetSpeed(velocidad);
	particle->SetOrientationSpeed(Vector3D(0, 0, 0));

	float red = fabs(velocidad.GetX()) * 50.0f;  // Multiplicamos para hacer los colores m�s perceptibles
	float green = fabs(velocidad.GetY()) * 50.0f;
	float blue = 0.0f; //Se queda en 0 ya que no hay velocidad en Z
	particle->SetColor(Color(red, green, blue, 1.0f));

	particle->SetPosition(this->GetPosition());

	this->particulas.push_back(particle);
	//this->particulas[this->particulas.size() - 1]->);
	//this->particulas[this->particulas.size() - 1];

	//se reinicia el contador de tiempo
	this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();

	cout << this->lastUpdatedTime << endl;

}
