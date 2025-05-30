#pragma once
#include "Model.h"

class Vidas : public Model
{
private:
    int vidas;

public:

    //Constructor
    Vidas(const Model& model, const Vector3D& position, const Vector3D& orientation, const Color& color, const Vector3D& speed) :
        Model(model, position, orientation, color, speed){


    }

    void Update(const float& time) override;

    inline int GetVidas() { return this->vidas; }

    void SetVidas(float vidasToSet) { this->vidas = vidasToSet; }

    void daño();

};

