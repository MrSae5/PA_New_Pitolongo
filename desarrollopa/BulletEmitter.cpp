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

void BulletEmitter::ProcessKeyPressed(unsigned char key, int px, int py) {

	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	//currentTime es el tiempo desde 1970 (tiempo donde windows comenzó a contar) y se lo resta a initialMilliseconds
	//que es el tiempo en milisegundos hasta ahora, y eso se lo resta al tiempo transcurrido desde al última iteración
	//de una partícula y se compara con el periodo de emisión
	if ((key == 32) && (currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdatedTime > this->configuracion->GetmiliSeconds())
	{
		Solid* particle = this->configuracion->GetParticula()->Clone();


		//if (this->angulo >= 360.0f) this->angulo -= 360.0f;
		//this->angulo += 20.0f;


		//double radianes = angulo * (3.14159265358979323846 / 180.0);
		//double seno = sin(radianes);
		//double coseno = cos(radianes);

		particle->SetOrientation(this->GetOrientation());


		Vector3D velocidad= Vector3D(0.1 * cos((GetOrientation().GetZ() - 90.0f) * M_PI / 180.0f),
			0.1 * sin((GetOrientation().GetZ() - 90.0f) * M_PI / 180.0f),
			0);


		//Vector3D velocidad = Vector3D(seno * 0.01, coseno * 0.01, 0); //Se crea una variable para que sea más fácil darle el color después
		particle->SetSpeed(velocidad);
		particle->SetOrientationSpeed(Vector3D(0, 0, 0));

		float red = fabs(velocidad.GetX()) * 50.0f;  // Multiplicamos para hacer los colores más perceptibles
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

}
