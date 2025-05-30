#pragma once
#include "Teapot.h"
#include "Vector3D.h"

class Enemigo : public Teapot {
public:
    Enemigo();
    Enemigo(const Enemigo& other);
    Solid* Clone() override;

    // Nueva función para mover el enemigo hacia el jugador
    void Update(float dt, Vector3D playerPos);
};
