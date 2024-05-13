#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Triangulo.h"

Triangulo *criar_triangulo(float lado1, float lado2, float lado3)
{
    Triangulo *triangulo = (Triangulo *)malloc(sizeof(Triangulo));
    if (triangulo == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para o triângulo\n");
        exit(EXIT_FAILURE);
    }
    triangulo->base.calcular_area = calcular_area_triangulo;
    triangulo->base.calcular_perimetro = calcular_perimetro_triangulo;
    triangulo->base.imprimir = imprimir_triangulo;
    triangulo->lado1 = lado1;
    triangulo->lado2 = lado2;
    triangulo->lado3 = lado3;
    return triangulo;
}

float calcular_area_triangulo(void *self)
{
    Triangulo *triangulo = (Triangulo *)self;
    float s = (triangulo->lado1 + triangulo->lado2 + triangulo->lado3) / 2;
    return sqrt(s * (s - triangulo->lado1) * (s - triangulo->lado2) * (s - triangulo->lado3));
}

float calcular_perimetro_triangulo(void *self)
{
    Triangulo *triangulo = (Triangulo *)self;
    return triangulo->lado1 + triangulo->lado2 + triangulo->lado3;
}

void imprimir_triangulo(void *self)
{
    Triangulo *triangulo = (Triangulo *)self;
    printf("Triângulo:\n");
    printf("Lado 1 = %.2f\n", triangulo->lado1);
    printf("Lado 2 = %.2f\n", triangulo->lado2);
    printf("Lado 3 = %.2f\n", triangulo->lado3);
    printf("Área = %.2f\n", triangulo->base.calcular_area(self));
    printf("Perímetro = %.2f\n", triangulo->base.calcular_perimetro(self));
}
