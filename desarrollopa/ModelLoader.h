#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include "Model.h"

using namespace std;

class ModelLoader
{
private:
	Model model;
	float scale;

	vector<Vector3D> vertexes;
	vector<Vector3D> normals;

	float maxX, maxY, maxZ;
	float minX, minY, minZ;

	inline float getWidth() { return this->maxX - this->minX; }
	inline float getHeight() { return this->maxY - this->minY; }
	inline float getLength() { return this->maxZ - this->minZ; }

	Vector3D parseObjLineToVector3D(const string& line);
	Triangle parseObjLineToTriangle(const string& line);
	void calcBoundaries(Vector3D vector);
	Triangle center(Triangle triangle);

public:
	ModelLoader(): maxX(0), maxY(0), maxZ(0), minX(0), minY(0), minZ(0)
	{
		this->scale = 1;
	}

	inline Model GetModel() { return this->model; }

	inline float GetScale() { return this->scale; }
	inline void SetScale(const float& scaleToSet) { this->scale = scaleToSet; }

	void LoadModel(const string& filePath);
};

