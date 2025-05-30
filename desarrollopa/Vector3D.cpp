#include "Vector3D.h"
#include <cmath>

Vector3D Vector3D::Add(const Vector3D& other) const
{
    return Vector3D(
        this->GetX() + other.GetX(),
        this->GetY() + other.GetY(),
        this->GetZ() + other.GetZ());
}

Vector3D Vector3D::operator+(const Vector3D& other) const
{
    return this->Add(other);
}

Vector3D Vector3D::Product(float a) const
{
    return Vector3D(
        this->GetX() * a,
        this->GetY() * a,
        this->GetZ() * a);
}

Vector3D Vector3D::operator*(float a) const
{
    return this->Product(a);
}

Vector3D Vector3D::operator-(const Vector3D& other) const
{
    return Vector3D(
        this->GetX() - other.GetX(),
        this->GetY() - other.GetY(),
        this->GetZ() - other.GetZ());
}

void Vector3D::Normalize()
{
    float length = std::sqrt(x * x + y * y + z * z);
    if (length != 0)
    {
        x /= length;
        y /= length;
        z /= length;
    }
}

float Vector3D::Length() {
    return sqrt(x * x + y * y + z * z);
}