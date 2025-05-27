#pragma once
#include "Vector3D.h" 
#include "Model.h" 
#include "ModelLoader.h"
#include "Solid.h"
#include "BulletEmitter.h"

class Player : public Solid // hereda de Solid
{
private:
	Model* playerObj;
	float movementSpeed;
	BulletEmitter* balaEmisor;

public:
    // Constructor y Destructor
    
	Player() : movementSpeed(0.2f), Solid()
	{
		//Instanciamos un loader para leer el archivo obj
		ModelLoader* loader = new ModelLoader();
		//fijamos la escala para ajustar el tamaño
		loader->SetScale(0.5);
		loader->LoadModel("..\\3dModels\\Tank.obj");
		//una vez cargado el modelo, instanciamos un Model usando memoria din?mica
		Model* tank = new Model();
		//Asignamos el modelo del loader a lo apuntado por el puntero llamado bolt
		*tank = loader->GetModel();
		//lo colocamos m?s cerca del centro de la escena
		tank->SetPosition(Vector3D(6, 3, 0));
		this->SetPosition(tank->GetPosition());
		tank->SetOrientation(Vector3D(0, 0, 180)); //180 para que mire hacia arriba
		this->SetOrientation(tank->GetOrientation());
		tank->SetColor(Color(0.0, 1.0, 0.0, 1.0));

		this->SetModel(tank);
	}

	~Player();

	inline Model* GetModel() { return this->playerObj; } 
	
	inline void SetModel(Model* modelToSet) { this->playerObj = modelToSet; }

	void Render() override;
	void Update(const float& time) override;
	void ProcessKeyPressed(unsigned char key, int px, int py); 

	Solid* Clone();

};
