#include "Vector3D.h"
#include <iostream>

Vector3D Vector3D::Add(Vector3D other)
{
	return Vector3D(
		this->GetX() + other.GetX(),
		this->GetY() + other.GetY(),
		this->GetZ() + other.GetZ());
}

Vector3D Vector3D::operator+(Vector3D other)
{
	return this->Add(other);
}

Vector3D Vector3D::Product(float a)
{
	return Vector3D(
		this->GetX() * a,
		this->GetY() * a,
		this->GetZ() * a);
}

Vector3D Vector3D::operator*(float a)
{
	return this->Product(a);
}

Vector3D Vector3D::operator-(Vector3D other)
{
	return Vector3D(
		this->GetX() - other.GetX(),
		this->GetY() - other.GetY(),
		this->GetZ() - other.GetZ());
}

//método de tinka
void Vector3D::Normalize() {
	float length = sqrt(x * x + y * y + z * z);  // Calculamos la longitud del vector
	if (length != 0) {  // Evitamos la división por 0
		x /= length;
		y /= length;
		z /= length;
	}
}