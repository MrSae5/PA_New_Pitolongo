#pragma once
class Vector3D
{
private:
    float x;
    float y;
    float z;

public:

    Vector3D() : x(0.0f), y(0.0f), z(0.0f) {}

    Vector3D(float xArgument, float yArgument, float zArgument)
        : x(xArgument), y(yArgument), z(zArgument) {}

    // Getters const para que puedan usarse en operadores const
    inline float GetX() const { return this->x; }
    inline float GetY() const { return this->y; }
    inline float GetZ() const { return this->z; }

    // Setters pueden quedarse igual
    inline void SetX(const float& xToSet) { this->x = xToSet; }
    inline void SetY(const float& yToSet) { this->y = yToSet; }
    inline void SetZ(const float& zToSet) { this->z = zToSet; }

    // Declaración con const y referencias
    Vector3D Add(const Vector3D& other) const;
    Vector3D operator+(const Vector3D& other) const;

    Vector3D Product(float a) const;
    Vector3D operator*(float a) const;

    Vector3D operator-(const Vector3D& other) const;

    void Normalize();

    float Length();
};
