#include "Sphere.h"

void Sphere::Render()
{
	glPushMatrix();
	glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
	glColor4f(this->GetColor().GetRed(), this->GetColor().GetGreen(), this->GetColor().GetBlue(), this->GetColor().GetAlpha());
	glRotatef(this->GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientation().GetZ(), 0.0, 0.0, 1.0);
	if (!this->GetWired()) { glutSolidSphere(GetRadius(), GetSlices(), GetSlacks()); }
	else { glutWireSphere(GetRadius(), GetSlices(), GetSlacks()); }
	glPopMatrix();
}


Solid* Sphere::Clone() {
	return new Sphere(*this);
}

