#include "Model.h"

Solid* Model::Clone()
{
	return new Model(*this);
}

void Model::AddTriangle(Triangle triangle)
{
	this->triangles.push_back(triangle);
}

void Model::Clear()
{
	this->triangles.clear();
}

void Model::Render()
{
	glPushMatrix();
	
	glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
	glRotatef(this->GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientation().GetZ(), 0.0, 0.0, 1.0);

	for (Triangle triangle : this->triangles)
	{
		triangle.Render();
	}
	glPopMatrix();
}

void Model::SetColor(Color colorToSet)
{
	for (Triangle& triangle : this->triangles)
	{
		triangle.SetColor0(colorToSet);
		triangle.SetColor1(colorToSet);
		triangle.SetColor2(colorToSet);
	}
}
