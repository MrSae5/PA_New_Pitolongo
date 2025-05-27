#include "ModelLoader.h"

void ModelLoader::LoadModel(const string& filePath)
{
	try
	{
		ifstream objFile(filePath);
		if (objFile.is_open())
		{
			string line;
			while (getline(objFile, line))
			{
				//cout << line << endl;
				if (line[0] == 'v' && line[1] == 'n')
				{
					Vector3D normal = this->parseObjLineToVector3D(line);
					this->normals.push_back(normal);
				}
				else if (line[0] == 'v')
				{
					Vector3D vertex = this->parseObjLineToVector3D(line);
					this->calcBoundaries(vertex);
					this->vertexes.push_back(vertex);
				}
				else if (line[0] == 'f')
				{
					Triangle triangle = this->parseObjLineToTriangle(line);
					this->model.AddTriangle(this->center(triangle));
				}
				else
				{

				}
			}
			objFile.close();
		}
		else
		{
			cout << "No se ha podido abrir el archivo: " << filePath << endl;
		}
	}
	catch (exception& ex)
	{
		cout << "Excepcion al procesar el archivo: " << filePath << endl;
		cout << ex.what() << endl;
	}
}

Vector3D ModelLoader::parseObjLineToVector3D(const string& line)
{
	//v -0.021345 -0.021345 -0.021345 
	//vn -0.021345 -0.021345 -0.021345 
	float xCoord, yCoord, zCoord;
	string typeOfPoint;
	istringstream stringStream(line);
	stringStream >> typeOfPoint >> xCoord >> yCoord >> zCoord;
	Vector3D vectorPoint(xCoord, yCoord, zCoord);
	return vectorPoint * this->GetScale();
}

Triangle ModelLoader::parseObjLineToTriangle(const string& line)
{
	//f 7//10 9//10 11//10
	char c;
	int idxVertex0, idxVertex1, idxVertex2;
	int idxNormal0, idxNormal1, idxNormal2;

	istringstream stringStream(line);
	stringStream >> c;
	stringStream >> idxVertex0 >> c >> c >> idxNormal0;
	stringStream >> idxVertex1 >> c >> c >> idxNormal1;
	stringStream >> idxVertex2 >> c >> c >> idxNormal2;

	Vector3D vertex0 = this->vertexes[idxVertex0 - 1];
	Vector3D vertex1 = this->vertexes[idxVertex1 - 1];
	Vector3D vertex2 = this->vertexes[idxVertex2 - 1];

	Vector3D normal = this->normals[idxNormal0 - 1];

	Triangle parsedTriangle(vertex0, vertex1, vertex2, normal, normal, normal);
	return parsedTriangle;
}

void ModelLoader::calcBoundaries(Vector3D vector)
{
	this->maxX = fmax(this->maxX, vector.GetX());
	this->maxY = fmax(this->maxY, vector.GetY());
	this->maxZ = fmax(this->maxZ, vector.GetZ());

	this->minX = fmin(this->minX, vector.GetX());
	this->minY = fmin(this->minY, vector.GetY());
	this->minZ = fmin(this->minZ, vector.GetZ());
}

Triangle ModelLoader::center(Triangle triangle)
{
	Vector3D modelCenter(
		this->minX + this->getWidth() / 2.0,
		this->minY + this->getHeight() / 2.0,
		this->minZ + this->getLength() / 2.0
	);
	Triangle centeredTriangle(
		triangle.GetVertex0() - modelCenter,
		triangle.GetVertex1() - modelCenter,
		triangle.GetVertex2() - modelCenter,
		triangle.GetNormal0(),
		triangle.GetNormal1(),
		triangle.GetNormal2()
	);
	return centeredTriangle;
}

