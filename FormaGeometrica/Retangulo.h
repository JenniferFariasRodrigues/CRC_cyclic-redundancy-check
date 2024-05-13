#ifndef RETANGULO_H
#define RETANGULO_H

#include "FormaGeometrica.h"

typedef struct
{
    FormaGeometrica base;
    float largura;
    float altura;
} Retangulo;

Retangulo *criar_retangulo(float largura, float altura);
float calcular_area_retangulo(void *self);
float calcular_perimetro_retangulo(void *self);
void imprimir_retangulo(void *self);

#endif
