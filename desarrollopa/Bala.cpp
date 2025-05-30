#include "Bala.h"

Bala::Bala() : Sphere(0.1f, 8, 8) {
    this->SetColor(Color(1.0f, 1.0f, 0.0f, 1.0f)); // Amarilla
}

Bala::Bala(const Bala& other) : Sphere(other) {
    this->SetColor(this->GetColor());
}

Solid* Bala::Clone() {
    return new Bala(*this);
}
