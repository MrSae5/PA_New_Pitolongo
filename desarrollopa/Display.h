#pragma once
#include <iostream>
#include "Cuboid.h"

using namespace std;

class Display
{
private:

	Cuboid segmentA;
	Cuboid segmentB;
	Cuboid segmentC;
	Cuboid segmentD;
	Cuboid segmentE;
	Cuboid segmentF;
	Cuboid segmentG;

public:
	Display()
	{
		this->segmentA.SetPosition(Vector3D(0.0, 2.0, -8.0));
		this->segmentA.SetOrientation(Vector3D(this->segmentA.GetOrientation().GetX(), this->segmentA.GetOrientation().GetY(), 90.0f));

		this->segmentB.SetPosition(Vector3D(1.0, 1.0, -8.0));

		this->segmentC.SetPosition(Vector3D(1.0, -1.0, -8.0));

		this->segmentD.SetPosition(Vector3D(0.0, -2.0, -8.0));
		this->segmentD.SetOrientation(Vector3D(this->segmentD.GetOrientation().GetX(), this->segmentD.GetOrientation().GetY(), 90.0f));

		this->segmentE.SetPosition(Vector3D(-1.0, -1.0, -8.0));

		this->segmentF.SetPosition(Vector3D(-1.0, 1.0, -8.0));

		this->segmentG.SetPosition(Vector3D(0.0, 0.0, -8.0));
		this->segmentG.SetOrientation(Vector3D(this->segmentG.GetOrientation().GetX(), this->segmentG.GetOrientation().GetY(), 90.0f));

	}

	inline Cuboid GetSegmentA() { return this->segmentA; }
	inline Cuboid GetSegmentB() { return this->segmentB; }
	inline Cuboid GetSegmentC() { return this->segmentC; }
	inline Cuboid GetSegmentD() { return this->segmentD; }
	inline Cuboid GetSegmentE() { return this->segmentE; }
	inline Cuboid GetSegmentF() { return this->segmentF; }
	inline Cuboid GetSegmentG() { return this->segmentG; }

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
};

