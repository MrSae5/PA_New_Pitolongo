#include "Triangle.h"

void Triangle::Render()
{
	glEnable(GL_COLOR_MATERIAL);

	glBegin(GL_TRIANGLES);

	glColor4f(this->GetColor0().GetRed(), this->GetColor0().GetGreen(), this->GetColor0().GetBlue(), this->GetColor0().GetAlpha());
	glNormal3f(this->GetNormal0().GetX(), this->GetNormal0().GetY(), this->GetNormal0().GetZ());
	glVertex3f(this->GetVertex0().GetX(), this->GetVertex0().GetY(), this->GetVertex0().GetZ());

	glColor4f(this->GetColor1().GetRed(), this->GetColor1().GetGreen(), this->GetColor1().GetBlue(), this->GetColor1().GetAlpha());
	glNormal3f(this->GetNormal1().GetX(), this->GetNormal1().GetY(), this->GetNormal1().GetZ());
	glVertex3f(this->GetVertex1().GetX(), this->GetVertex1().GetY(), this->GetVertex1().GetZ());

	glColor4f(this->GetColor2().GetRed(), this->GetColor2().GetGreen(), this->GetColor2().GetBlue(), this->GetColor2().GetAlpha());
	glNormal3f(this->GetNormal2().GetX(), this->GetNormal2().GetY(), this->GetNormal2().GetZ());
	glVertex3f(this->GetVertex2().GetX(), this->GetVertex2().GetY(), this->GetVertex2().GetZ());

	glEnd();
}

Solid* Triangle::Clone()
{
	return new Triangle(*this);
}
