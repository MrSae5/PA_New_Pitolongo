#pragma once
#include <vector>
#include <cstdlib> // rand()
#include <algorithm>
#include "Enemigo.h"
#include "Vector3D.h"
#include "Player.h"

class EnemyEmitter {
private:
    std::vector<Enemigo*> enemies;
    float spawnInterval;    // Tiempo entre spawns en segundos
    float elapsedTime;
    Vector3D boundary;
    Player* player;

public:
    EnemyEmitter(Vector3D boundary_, Player* player_, float interval = 1.0f)
        : boundary(boundary_), player(player_), spawnInterval(interval), elapsedTime(0.0f) {}

    ~EnemyEmitter() {
        for (Enemigo* e : enemies)
            delete e;
        enemies.clear();
    }

    const std::vector<Enemigo*>& GetEnemies() const { return enemies; }

    void Update(float dt);

    void Render();

    void RemoveEnemy(Enemigo* enemy);
};
