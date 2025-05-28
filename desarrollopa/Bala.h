#pragma once
#include "Sphere.h"

class Bala : public Sphere {
public:
    Bala();
    Bala(const Bala& other);
    Solid* Clone() override;
};
