#pragma once
#include "Model.h" 
#include "BulletEmitter.h"

class Player : public Model // hereda de Model
{
private:
    float movementSpeed;
    BulletEmitter* balaEmisor;

public:
    // Constructor y Destructor
    
	Player(const Model& model, const Vector3D& position, const Vector3D& orientation, const Color& color, const Vector3D& speed)
		: Model(model, position, orientation, color, speed) 
    {
        movementSpeed = 0.25f;
        balaEmisor = new BulletEmitter();
    }

    void Avanzar();
    void Retroceder();
    void GiroDerecha();
    void GiroIzquierda();

    void Disparar();


};
