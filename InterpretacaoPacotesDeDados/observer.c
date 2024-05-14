#include "observer.h"
#include <stdio.h> // Adicione esta linha

// Função para adicionar um observador ao objeto observável
void addObserver(Observable *observable, uint8_t tipoInteresse, ObserverCallback callback)
{
    if (observable->numObservers < 10)
    {
        Observer *observer = &observable->observers[observable->numObservers];
        observer->tipoInteresse = tipoInteresse;
        observer->callback = callback;
        observable->numObservers++;
    }
    else
    {
        printf("Limite de observadores atingido!\n");
    }
}

// Função para notificar os observadores quando um novo pacote de dados é recebido
void notifyObservers(Observable *observable, PacoteDados *pacote)
{
    printf("\n---Aviso---\nNotificando observadores para o tipo de pacote: %d\n", pacote->tipo);
    for (int i = 0; i < observable->numObservers; i++)
    {
        if (observable->observers[i].tipoInteresse == pacote->tipo)
        {
            observable->observers[i].callback(pacote);
        }
    }
}
