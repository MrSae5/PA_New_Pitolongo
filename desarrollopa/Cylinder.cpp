#include "Cylinder.h"

void Cylinder::Render() {
	GLUquadricObj* quadricTemp = gluNewQuadric();
	glPushMatrix();
	glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
	glColor4f(this->GetColor().GetRed(), this->GetColor().GetGreen(), this->GetColor().GetBlue(), this->GetColor().GetAlpha());
	glRotatef(this->GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientation().GetZ(), 0.0, 0.0, 1.0);
	gluCylinder(quadricTemp, this->GetBaseRadius(), this->GetTopRadius(), this->GetHeight(), this->GetSlices(), this->GetSlacks());
	glPopMatrix();
	gluDeleteQuadric(quadricTemp);
}

Solid* Cylinder::Clone() {
	return new Cylinder(*this);
}

