#include "Player.h"
//variable que usaremos para convertir de grados a radianes
//ya que las funciones del movimiento cos y sin esperan radianes
//y las orientaciones del tanque están definidas en grados
//la definimos porque no nos dejaba utilizar la biblioteca de cmath
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

//Girar a la ziquierda (rotación antihoraria)
void Player::GiroIzquierda() {

    this->SetOrientation(Vector3D(this->GetOrientation().GetX(), this->GetOrientation().GetY(), this->GetOrientation().GetZ() + 5.0f));

    if (this->GetOrientation().GetZ() < 0) {
        this->SetOrientation(Vector3D(this->GetOrientation().GetX(), this->GetOrientation().GetY(), this->GetOrientation().GetZ() + 360.0f));
    }
}

// Girar a la derecha (rotación horaria)
void Player::GiroDerecha() {

    this->SetOrientation(Vector3D(this->GetOrientation().GetX(), this->GetOrientation().GetY(), this->GetOrientation().GetZ() - 5.0f));

    if (this->GetOrientation().GetZ() >= 360.0f) {
        this->SetOrientation(Vector3D(this->GetOrientation().GetX(), this->GetOrientation().GetY(), this->GetOrientation().GetZ() - 360.0f));
    }
}

//Mover hacia adelante según hacia donde esté mirando el jugador 
void Player::Avanzar() {

    this->SetPosition(Vector3D(this->GetPosition().GetX() + movementSpeed * cos((GetOrientation().GetZ() - 90.0f) * M_PI / 180.0f),
        this->GetPosition().GetY() + movementSpeed * sin((GetOrientation().GetZ() - 90.0f) * M_PI / 180.0f),
        this->GetPosition().GetZ()));
    
}

//Mover hacia atrás según hacia donde esté mirando el jugador
void Player::Retroceder() {

    this->SetPosition(Vector3D(this->GetPosition().GetX() - movementSpeed * cos((GetOrientation().GetZ() - 90.0f) * M_PI / 180.0f),
        this->GetPosition().GetY() - movementSpeed * sin((GetOrientation().GetZ() - 90.0f) * M_PI / 180.0f),
        this->GetPosition().GetZ()));

}

void Player::Disparar() {
    balaEmisor->SetPosition(this->GetPosition());
    balaEmisor->SetOrientation(this->GetOrientation());

    auto currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    if (currentTime - utltmDisparo < cooldown) {
        return; // no han pasado suficientes ms, no dispara
    }

    utltmDisparo = currentTime;
    balaEmisor->DispararBala();
}


