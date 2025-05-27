#include "Torus.h"

void Torus::Render()
{
	glPushMatrix();
	glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(),
		this->GetPosition().GetZ());
	glColor4f(this->GetColor().GetRed(),
		this->GetColor().GetGreen(),
		this->GetColor().GetBlue(),
		this->GetColor().GetAlpha());
	glRotatef(this->GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientation().GetZ(), 0.0, 0.0, 1.0);
	if (!this->GetWired()) { glutSolidTorus(this->GetInternalRadius(), this->GetExternalRadius(), this->GetFaces(), this->GetRings()); }
	else { glutWireTorus(this->GetInternalRadius(), this->GetExternalRadius(), this->GetFaces(), this->GetRings()); }
	glPopMatrix();
}


Solid* Torus::Clone() {
	return new Torus(*this);
}

