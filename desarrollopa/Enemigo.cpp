#include "Enemigo.h"
#include <cmath>

Enemigo::Enemigo() : Teapot() {}

Enemigo::Enemigo(const Enemigo& other) : Teapot(other) {}

Solid* Enemigo::Clone() {
    return new Enemigo(*this);
}

void Enemigo::Update(float dt, Vector3D playerPos) {
    // Obtener vector direcci�n hacia el jugador
    Vector3D dir = playerPos - this->GetPosition();

    // Normalizar direcci�n
    dir.Normalize();

    // Velocidad constante, ajusta este valor para la rapidez del enemigo
    float speed = 0.20f;

    // Mover enemigo hacia el jugador
    Vector3D newPos = this->GetPosition() + dir * speed * dt;
    this->SetPosition(newPos);
}
