#pragma once


#include <string>
#include <GL/glut.h>
#include "Vector3D.h"

class Text {
private:
    float red, green, blue, alpha; // Colores del texto
    Vector3D position;        // Posición del texto en el espacio 3D 
    void* font;              // Puntero a la fuente (por ejemplo, GLUT_BITMAP_8_BY_13)
    std::string text; 

public:
    // Constructor
    Text() : red(1.f), green(1.f), blue(1.f), alpha(1.f),
        position(0.f, 0.f, -5.f), font(GLUT_BITMAP_TIMES_ROMAN_24), text("") {}

    // Setters
    inline void SetColor(float r, float g, float b, float a) { red = r; green = g; blue = b; alpha = a; };
    inline void SetPosition(Vector3D coordsToSet) { this->position = coordsToSet; }
    inline void SetFont(void* fontType){ font = fontType; }
    inline void SetText(const std::string& textToRender) { text = textToRender; } 

    inline std::string GetText() { return this->text; }

    // Función para dibujar el texto
    void Render();
};

