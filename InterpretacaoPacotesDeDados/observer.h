#ifndef OBSERVER_H
#define OBSERVER_H

#include <stdint.h>

// Definição da estrutura para o pacote de dados
typedef struct
{
    uint8_t tipo;
    uint16_t comprimento;
    char dados[50]; // Tamanho máximo dos dados
    uint16_t crc;
} PacoteDados;

// Definição do tipo de função do observador
typedef void (*ObserverCallback)(PacoteDados *pacote);

// Estrutura para o observador
typedef struct
{
    uint8_t tipoInteresse;
    ObserverCallback callback;
} Observer;

// Estrutura para o objeto observável
typedef struct
{
    Observer observers[10]; // Lista de observadores
    int numObservers;       // Número atual de observadores registrados
} Observable;

// Função para adicionar um observador ao objeto observável
void addObserver(Observable *observable, uint8_t tipoInteresse, ObserverCallback callback);

// Função para notificar os observadores quando um novo pacote de dados é recebido
void notifyObservers(Observable *observable, PacoteDados *pacote);

#endif
