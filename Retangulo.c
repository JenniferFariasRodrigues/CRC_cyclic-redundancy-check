#include <stdio.h>
#include <stdlib.h>
#include "Retangulo.h"

Retangulo *criar_retangulo(float largura, float altura)
{
    Retangulo *retangulo = (Retangulo *)malloc(sizeof(Retangulo));
    if (retangulo == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para o retângulo\n");
        exit(EXIT_FAILURE);
    }
    retangulo->base.calcular_area = calcular_area_retangulo;
    retangulo->base.calcular_perimetro = calcular_perimetro_retangulo;
    retangulo->base.imprimir = imprimir_retangulo;
    retangulo->largura = largura;
    retangulo->altura = altura;
    return retangulo;
}

float calcular_area_retangulo(void *self)
{
    Retangulo *retangulo = (Retangulo *)self;
    return retangulo->largura * retangulo->altura;
}

float calcular_perimetro_retangulo(void *self)
{
    Retangulo *retangulo = (Retangulo *)self;
    return 2 * (retangulo->largura + retangulo->altura);
}

void imprimir_retangulo(void *self)
{
    Retangulo *retangulo = (Retangulo *)self;
    printf("Retângulo:\n");
    printf("Largura: %.2f\n", retangulo->largura);
    printf("Altura: %.2f\n", retangulo->altura);
    printf("Área: %.2f\n", retangulo->base.calcular_area(self));
    printf("Perímetro: %.2f\n", retangulo->base.calcular_perimetro(self));
}
