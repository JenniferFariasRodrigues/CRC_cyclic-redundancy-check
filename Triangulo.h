#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "FormaGeometrica.h"

typedef struct
{
    FormaGeometrica base;
    float lado1;
    float lado2;
    float lado3;
} Triangulo;

Triangulo *criar_triangulo(float lado1, float lado2, float lado3);
float calcular_area_triangulo(void *self);
float calcular_perimetro_triangulo(void *self);
void imprimir_triangulo(void *self);

#endif /* TRIANGULO_H */
