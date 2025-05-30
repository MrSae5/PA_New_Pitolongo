#include "Vidas.h"

void Vidas::daño()
{
    this->SetVidas(this->GetVidas() - 1);
}
void Vidas::Update(const float& time) {
    float speed = 90.0f; // grados por segundo
    float newY = this->GetOrientation().GetY() + speed * time;
    this->SetOrientation(Vector3D(0.0f, newY, 0.0f));
}
