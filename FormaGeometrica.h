#ifndef FORMA_GEOMETRICA_H
#define FORMA_GEOMETRICA_H

typedef struct
{
    float (*calcular_area)(void *);
    float (*calcular_perimetro)(void *);
    void (*imprimir)(void *);
} FormaGeometrica;

void inicializar_forma_geometrica(FormaGeometrica *forma, float (*calcular_area)(void *), float (*calcular_perimetro)(void *), void (*imprimir)(void *));

#endif 
