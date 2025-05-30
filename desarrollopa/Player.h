#pragma once
#include "Model.h" 
#include "BulletEmitter.h"
#include "Bala.h"

class Player : public Model // hereda de Model
{
private:
    float movementSpeed;
    BulletEmitter* balaEmisor;
    long long utltmDisparo = 0;
    long long cooldown = 500; // milisegundos

public:
    // Constructor y Destructor
    
	Player(const Model& model, const Vector3D& position, const Vector3D& orientation, const Color& color, const Vector3D& speed)
		: Model(model, position, orientation, color, speed) 
    {
        movementSpeed = 0.25f;
        Solid* particulaBase = new Bala(); 

        EmitterConfiguration config(100, 100); // 100 partículas máx, 100 ms entre disparos
        config.SetParticula(particulaBase);

        this->balaEmisor = new BulletEmitter(config, particulaBase);
        balaEmisor->SetPosition(this->GetPosition());
        balaEmisor->SetOrientation(this->GetOrientation());
    }

    void Avanzar();
    void Retroceder();
    void GiroDerecha();
    void GiroIzquierda();
    void SetBulletEmitter(BulletEmitter* emisor) {
        this->balaEmisor = emisor;
    }

    BulletEmitter* GetBulletEmitter() {
        return this->balaEmisor;
    }

    void Disparar();


};
