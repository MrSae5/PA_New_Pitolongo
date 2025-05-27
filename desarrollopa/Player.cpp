#include "Player.h"

//variable que usaremos para convertir de grados a radianes
//ya que las funciones del movimiento cos y sin esperan radianes
//y las orientaciones del tanque están definidas en grados
//la definimos porque no nos dejaba utilizar la biblioteca de cmath
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Player::~Player() {};

void Player::Render() {
    if (playerObj) {
        playerObj->Render();
    }
}


void Player::Update(const float& time)
{
    this->playerObj->SetPosition(GetPosition());
    this->playerObj->SetOrientation(GetOrientation());

    this->playerObj->Update(time); 

}

//movimiento del jugador (controles tanque)
void Player::ProcessKeyPressed(unsigned char key, int px, int py)
{
    switch (key) {
    case 'w': // Mover hacia adelante según hacia donde esté mirando el jugador 
        this->SetPosition(Vector3D (this->GetPosition().GetX() + movementSpeed * cos((GetOrientation().GetZ() - 90.0f) * M_PI / 180.0f),
                this->GetPosition().GetY() + movementSpeed * sin((GetOrientation().GetZ() - 90.0f) * M_PI / 180.0f),
                this->GetPosition().GetZ()));
       
        break;

    case 's': // Mover hacia atrás según hacia donde esté mirando el jugador

        this->SetPosition(Vector3D(this->GetPosition().GetX() - movementSpeed * cos((GetOrientation().GetZ() - 90.0f) * M_PI / 180.0f),
            this->GetPosition().GetY() - movementSpeed * sin((GetOrientation().GetZ() - 90.0f) * M_PI / 180.0f),
            this->GetPosition().GetZ()));

        
        break;

    case 'a': // Girar a la izquierda (rotación antihoraria)

        this->SetOrientation(Vector3D(this->GetOrientation().GetX(), this->GetOrientation().GetY(), this->GetOrientation().GetZ() + 5.0f));
        
        if (this->GetOrientation().GetZ() < 0) {
            this->SetOrientation(Vector3D(this->GetOrientation().GetX(), this->GetOrientation().GetY(), this->GetOrientation().GetZ() + 360.0f));
        }
        
        break;

    case 'd': // Girar a la derecha (rotación horaria)
        this->SetOrientation(Vector3D(this->GetOrientation().GetX(), this->GetOrientation().GetY(), this->GetOrientation().GetZ() - 5.0f));
        
        if (this->GetOrientation().GetZ() >= 360.0f) {
            this->SetOrientation(Vector3D(this->GetOrientation().GetX(), this->GetOrientation().GetY(), this->GetOrientation().GetZ() - 360.0f));
        }
        break;

    default:
        break;
    }
    std::cout << "x:" << GetPosition().GetX() << "y:" << GetPosition().GetY() << endl;

    balaEmisor->ProcessKeyPressed(key, px, py);
}

Solid* Player::Clone() {
    return new Player(*this);
}

