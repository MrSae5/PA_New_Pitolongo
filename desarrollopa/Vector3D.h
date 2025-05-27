#pragma once
class Vector3D
{
private:

	float x;
	float y;
	float z;

public:

	Vector3D() : x(0.0), y(0.0), z(0.0) {}

	Vector3D(float xArgument, float yArgument, float zArgument)
	{
		this->x = xArgument;
		this->y = yArgument;
		this->z = zArgument;
	}

	inline float GetX() { return this->x; }
	inline float GetY() { return this->y; }
	inline float GetZ() { return this->z; }

	inline void SetX(const float& xToSet) { this->x = xToSet; }
	inline void SetY(const float& yToSet) { this->y = yToSet; }
	inline void SetZ(const float& zToSet) { this->z = zToSet; }

	Vector3D Add(Vector3D other);
	Vector3D operator+(Vector3D other);

	Vector3D Product(float a);
	Vector3D operator*(float a);

	Vector3D operator-(Vector3D other);

	void Normalize();

};