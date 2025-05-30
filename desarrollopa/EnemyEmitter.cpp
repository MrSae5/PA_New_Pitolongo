#include "EnemyEmitter.h"

void EnemyEmitter::Update(float dt) {
    elapsedTime += dt;
    if (elapsedTime >= spawnInterval) {
        elapsedTime = 0;

        Enemigo* enemy = new Enemigo();

        // Generar posición aleatoria en los bordes X o Y con Z=0 (por ejemplo)
        int side = rand() % 4; // 0: izquierda, 1: derecha, 2: abajo, 3: arriba
        Vector3D pos;
        switch (side) {
        case 0: pos = Vector3D(0, static_cast<float>(rand()) / RAND_MAX * boundary.GetY(), 0); break;
        case 1: pos = Vector3D(boundary.GetX(), static_cast<float>(rand()) / RAND_MAX * boundary.GetY(), 0); break;
        case 2: pos = Vector3D(static_cast<float>(rand()) / RAND_MAX * boundary.GetX(), 0, 0); break;
        case 3: pos = Vector3D(static_cast<float>(rand()) / RAND_MAX * boundary.GetX(), boundary.GetY(), 0); break;
        }

        enemy->SetPosition(pos);

        enemy->SetSpeed(Vector3D(0, 0, 0));

        enemies.push_back(enemy);
    }

    // Actualizar enemigos moviéndolos hacia el jugador
    for (Enemigo* e : enemies) {
        e->Update(dt, player->GetPosition());
    }
}

void EnemyEmitter::Render() {
    for (Enemigo* e : enemies) {
        e->Render();
    }
}

void EnemyEmitter::RemoveEnemy(Enemigo* enemy) {
    auto it = std::find(enemies.begin(), enemies.end(), enemy);
    if (it != enemies.end()) {
        delete* it;
        enemies.erase(it);
    }
}
