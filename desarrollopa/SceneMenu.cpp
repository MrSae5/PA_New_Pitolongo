#include "SceneMenu.h"

/*void SceneMenu::AddGameObject(Solid* gameObjectToAdd)
{
	this->gameObjects.push_back(gameObjectToAdd);
}*/

bool SceneMenu::IsClickInsideButton(int x, int y) {
    // Obtener las dimensiones de la ventana
    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    // Convertir coordenadas de pantalla a coordenadas normalizadas (-1 a 1)
    float normX = (2.0f * x) / windowWidth - 1.0f;
    float normY = 1.0f - (2.0f * y) / windowHeight; // Invertir eje Y

    // Obtener coordenadas del botón
    float buttonX = button.GetPosition().GetX();
    float buttonY = button.GetPosition().GetY();
    float buttonWidth = button.GetWidth();
    float buttonHeight = button.GetHeight();

    // Verificar si el clic está dentro de los límites del botón
    return (normX >= buttonX - buttonWidth / 2 && normX <= buttonX + buttonWidth / 2 &&
        normY >= buttonY - buttonHeight / 2 && normY <= buttonY + buttonHeight / 2);
}


void SceneMenu::Render() {
    this->GetCamera().Render();
    button.Render(); // Dibuja el botón
    texto.Render();
}

void SceneMenu::Update()
{
	/*for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Update(0.1f);
	}*/

}

