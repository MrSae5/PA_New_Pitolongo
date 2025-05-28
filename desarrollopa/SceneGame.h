#pragma once
#include "Scene.h"
#include "Player.h"

class SceneGame : public Scene
{
private:
	
	Player* player;
	Vector3D boundary;
	bool drawBoundary;
	void checkBoundary();
	void renderBoundary();

protected:
	void checkBoundary(Solid*);

public: 

	SceneGame(Vector3D boundaryArgument = Vector3D(14, 7, 4)) : boundary(boundaryArgument)
	{
		this->drawBoundary = true;
		this->GetCamera().SetPosition(Vector3D(boundary.GetX() / 2, boundary.GetY() / 2, boundary.GetZ() * 3.5));
	}

	inline Player* GetPlayer() { return this->player; }


	void AddPlayer(Player* playerToSet) { this->player = playerToSet; };

	inline Vector3D GetBoundary() { return this->boundary; }
	inline bool GetDrawBoundary() { return this->drawBoundary; }

	inline void SetDrawBoundary(bool drawBoundaryToSet) { this->drawBoundary = drawBoundaryToSet; }

	void Render() override;
	void Update() override;
	void ProcessKeyPressed(unsigned char key, int px, int py);

};

