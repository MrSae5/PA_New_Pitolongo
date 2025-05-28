#include "SceneGame.h"
#include <iostream>
#include <algorithm>

void SceneGame::Render() {
	this->GetCamera().Render();

	if (this->GetDrawBoundary()) { this->renderBoundary(); }
	
	this->player->Render();
    this->player->GetBulletEmitter()->Render();

    if (enemyEmitter) {
        enemyEmitter->Render();
    }
}

void SceneGame::Update()
{
	this->checkBoundary();
	this->player->Update(0.1f);
    this->player->GetBulletEmitter()->Update(0.1f);  

    if (enemyEmitter) {
        enemyEmitter->Update(0.1f);

        // Chequeo colisiones balas-enemigos
        auto& bullets = this->player->GetBulletEmitter()->GetBullets(); 
        auto& enemies = enemyEmitter->GetEnemies();

        for (auto bulletIt = bullets.begin(); bulletIt != bullets.end(); ) {
            Solid* bullet = *bulletIt;
            bool bulletRemoved = false;

            for (auto enemyIt = enemies.begin(); enemyIt != enemies.end(); ) {
                Enemigo* enemy = *enemyIt;

                // Distancia entre enemigo y bala (puedes ajustar el margen)
                float dist = (enemy->GetPosition() - bullet->GetPosition()).Length();
                if (dist < 0.5f) { // choque detectado
                    enemyEmitter->RemoveEnemy(enemy);
                    bulletIt = bullets.erase(bulletIt);
                    bulletRemoved = true;
                    break; // sale del for enemies
                }
                else {
                    ++enemyIt;
                }
            }

            if (!bulletRemoved) {
                ++bulletIt;
            }
        }

        // Chequeo colisiones enemigos - player
        for (Enemigo* enemy : enemies) {
            float dist = (enemy->GetPosition() - player->GetPosition()).Length();
            if (dist < 0.7f) {  // colisión jugador-enemigo
                std::cout << "[SceneGame] El jugador fue tocado por un enemigo!" << std::endl;
                // Aquí manejar vida, game over, o eliminar enemigo
                enemyEmitter->RemoveEnemy(enemy);
                break;
            }
        }
    }
}

void SceneGame::checkBoundary()
{
	this->checkBoundary(this->player);
}

void SceneGame::checkBoundary(Solid* element)
{
	if (element->GetPosition().GetX() > this->boundary.GetX())
	{
		element->SetPosition(Vector3D(this->boundary.GetX(), element->GetPosition().GetY(), element->GetPosition().GetZ()));
		element->SetSpeed(Vector3D(-1 * element->GetSpeed().GetX(), element->GetSpeed().GetY(), element->GetSpeed().GetZ()));
	}

	if (element->GetPosition().GetX() < 0)
	{
		element->SetPosition(Vector3D(0, element->GetPosition().GetY(), element->GetPosition().GetZ()));
		element->SetSpeed(Vector3D(-1 * element->GetSpeed().GetX(), element->GetSpeed().GetY(), element->GetSpeed().GetZ()));
	}

	if (element->GetPosition().GetY() > this->boundary.GetY())
	{
		element->SetPosition(Vector3D(element->GetPosition().GetX(), this->boundary.GetY(), element->GetPosition().GetZ()));
		element->SetSpeed(Vector3D(element->GetSpeed().GetX(), -1 * element->GetSpeed().GetY(), element->GetSpeed().GetZ()));
	}

	if (element->GetPosition().GetY() < 0)
	{
		element->SetPosition(Vector3D(element->GetPosition().GetX(), 0, element->GetPosition().GetZ()));
		element->SetSpeed(Vector3D(element->GetSpeed().GetX(), -1 * element->GetSpeed().GetY(), element->GetSpeed().GetZ()));
	}

	if (element->GetPosition().GetZ() > this->boundary.GetZ())
	{
		element->SetPosition(Vector3D(element->GetPosition().GetX(), element->GetPosition().GetY(), this->boundary.GetZ()));
		element->SetSpeed(Vector3D(element->GetSpeed().GetX(), element->GetSpeed().GetY(), -1 * element->GetSpeed().GetZ()));
	}

	if (element->GetPosition().GetZ() < 0)
	{
		element->SetPosition(Vector3D(element->GetPosition().GetX(), element->GetPosition().GetY(), 0));
		element->SetSpeed(Vector3D(element->GetSpeed().GetX(), element->GetSpeed().GetY(), -1 * element->GetSpeed().GetZ()));
	}
}


void SceneGame::renderBoundary()
{
    float z = 0; // profundidad fija

    // Borde inferior
    Cuboid* bottom = new Cuboid();
    bottom->SetLength(this->GetBoundary().GetX());
    bottom->SetHeight(0.1f); // muy delgado
    bottom->SetWidth(0.1f);  // casi sin profundidad
    bottom->SetPosition(Vector3D(this->GetBoundary().GetX() / 2, 0, z));
    bottom->SetWired(true);
    bottom->Render();

    // Borde superior
    Cuboid* top = new Cuboid();
    top->SetLength(this->GetBoundary().GetX());
    top->SetHeight(0.1f);
    top->SetWidth(0.1f);
    top->SetPosition(Vector3D(this->GetBoundary().GetX() / 2, this->GetBoundary().GetY(), z));
    top->SetWired(true);
    top->Render();

    // Borde izquierdo
    Cuboid* left = new Cuboid();
    left->SetLength(0.1f);
    left->SetHeight(this->GetBoundary().GetY());
    left->SetWidth(0.1f);
    left->SetPosition(Vector3D(0, this->GetBoundary().GetY() / 2, z));
    left->SetWired(true);
    left->Render();

    // Borde derecho
    Cuboid* right = new Cuboid();
    right->SetLength(0.1f);
    right->SetHeight(this->GetBoundary().GetY());
    right->SetWidth(0.1f);
    right->SetPosition(Vector3D(this->GetBoundary().GetX(), this->GetBoundary().GetY() / 2, z));
    right->SetWired(true);
    right->Render();
}

//emisor enemigos
void SceneGame::InitEnemyEmitter() {
    enemyEmitter = new EnemyEmitter(boundary, player, 50.0f); 
}


//Función que procesa los inputs del teclado. Controla el movimiento  de la cára y el jugador.
void SceneGame::ProcessKeyPressed(unsigned char key, int px, int py) {

	std::cout << "Tecla pulsada: " << key << std::endl;

	switch (key) {

	case 'D':
	case 'd':
		//al pulsar la "D", tanto el personaje como la cámara llaman a su función para moverse a la derecha
		this->player->GiroDerecha();
		break;

	case 'A':
	case 'a':
		this->player->GiroIzquierda();
		break;

	case 'S':
	case 's':
		this->player->Retroceder();
		break;

	case 'W':
	case 'w':
		this->player->Avanzar();
		break;

	case 'e':
    case 'E':
		this->player->Disparar();
		break;

	default:
		cout << "La tecla " << key << " no hace nada." << endl;
		break;
	}
}