#pragma once
#include "Solid.h"
#include <GL/glut.h>

class Cylinder : public Solid
{
private:
    float baseRadius;
    float topRadius;
    float height;
    int slices;
    int slacks;
public:
    Cylinder() : baseRadius(0.5), topRadius(0.5), height(0.8), slices(16), slacks(16), Solid() {}

    inline float GetBaseRadius() const { return this->baseRadius; }
    inline void SetBaseRadius(const float& baseRadiusToSet) { this->baseRadius = baseRadiusToSet; }
    inline float GetTopRadius() const { return this->topRadius; }
    inline void SetTopRadius(const float& topRadiusToSet) { this->topRadius = topRadiusToSet; }
    inline float GetHeight() const { return this->height; }
    inline void SetHeight(const float& heightToSet) { this->height = heightToSet; }
    inline int GetSlices() const { return this->slices; }
    inline void SetSlices(const int& slicesToSet) { this->slices = slicesToSet; }
    inline int GetSlacks() const { return this->slacks; }
    inline void SetSlacks(const int& slacksToSet) { this->slacks = slacksToSet; }

    void Render();

    Solid* Clone();

};
