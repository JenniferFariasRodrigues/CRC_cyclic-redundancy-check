#include <stdio.h>
#include <stdlib.h>
#include "Retangulo.h"
#include "Triangulo.h"

int main()
{
    //  Instância do retângulo
    Retangulo *retangulo = criar_retangulo(5.0, 3.0);

    // Instância do triângulo
    Triangulo *triangulo = criar_triangulo(3.0, 4.0, 5.0);

    // Imprimir dados do retângulo
    printf("----------------------\n");
    printf("\nDados do Retângulo\n");
    printf("\n----------------------\n");
    retangulo->base.imprimir(retangulo);

    // Imprimir dados do triângulo
     printf("\n \n----------------------\n");
    printf("\nDados do Triângulo\n");
    printf("\n----------------------\n");
    triangulo->base.imprimir(triangulo);

    // Liberar memória alocada
    free(retangulo);
    free(triangulo);

    return 0;
}
