#include "SceneGame.h"

void SceneGame::Render() {
	this->GetCamera().Render();

	if (this->GetDrawBoundary()) { this->renderBoundary(); }
	
	this->player->Render();
}

void SceneGame::Update()
{
	this->checkBoundary();
	this->player->Update(0.1f);
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
	Cuboid* bottom = new Cuboid();
	bottom->SetLength(this->GetBoundary().GetX());
	bottom->SetHeight(0.1);
	bottom->SetWidth(this->GetBoundary().GetZ());
	bottom->SetPosition(Vector3D(this->GetBoundary().GetX() / 2, 0, this->GetBoundary().GetZ()));
	bottom->SetWired(true);
	bottom->Render();

	Cuboid* top = new Cuboid();
	top->SetLength(this->GetBoundary().GetX());
	top->SetHeight(0.1);
	top->SetWidth(this->GetBoundary().GetZ());
	top->SetPosition(Vector3D(this->GetBoundary().GetX() / 2, this->GetBoundary().GetY(), this->GetBoundary().GetZ()));
	top->SetWired(true);
	top->Render();

	Cuboid* left = new Cuboid();
	left->SetLength(0.1);
	left->SetHeight(this->GetBoundary().GetY());
	left->SetWidth(this->GetBoundary().GetZ());
	left->SetPosition(Vector3D(0, this->GetBoundary().GetY() / 2, this->GetBoundary().GetZ()));
	left->SetWired(true);
	left->Render();

	Cuboid* right = new Cuboid();
	right->SetLength(0.1);
	right->SetHeight(this->GetBoundary().GetY());
	right->SetWidth(this->GetBoundary().GetZ());
	right->SetPosition(Vector3D(this->GetBoundary().GetX(), this->GetBoundary().GetY() / 2, this->GetBoundary().GetZ()));
	right->SetWired(true);
	right->Render();
}