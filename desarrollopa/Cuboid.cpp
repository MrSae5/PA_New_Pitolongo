#include "Cuboid.h"

void Cuboid::Render()
{
	glPushMatrix();
	glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(),this->GetPosition().GetZ());
	glColor4f(this->GetColor().GetRed(), this->GetColor().GetGreen(),this->GetColor().GetBlue(), this->GetColor().GetAlpha());
	glRotatef(this->GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientation().GetZ(), 0.0, 0.0, 1.0);
	glScalef(this->GetLength(), this->GetHeight(), this->GetWidth());
	if (!this->GetWired()) { glutSolidCube(1); }
	else { glutWireCube(1); }
	glPopMatrix();
}

Solid* Cuboid::Clone() {
	return new Cuboid(*this);
}
