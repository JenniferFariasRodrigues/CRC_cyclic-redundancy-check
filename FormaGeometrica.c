#include "FormaGeometrica.h"

void inicializar_forma_geometrica(FormaGeometrica *forma, float (*calcular_area)(void *), float (*calcular_perimetro)(void *), void (*imprimir)(void *))
{
    forma->calcular_area = calcular_area;
    forma->calcular_perimetro = calcular_perimetro;
    forma->imprimir = imprimir;
}
