#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "crc32.h"
#include "observer.h"

// Definição do cabeçalho do pacote
#define PACKET_TYPE_DATA 0x01
#define START_SYMBOL PACKET_TYPE_DATA

bool validarPacote(PacoteDados *pacote);
void pacoteRecebido(PacoteDados *pacote);

bool checa(char *nome, int serial)
{
    int serial_correto = 0;

    while (*nome)
        serial_correto += *nome++;
    printf("Serial correto: %d\n", serial_correto);
    return (serial == serial_correto);
}

int main(void)
{
    char nome[50];
    int serial;
    uint8_t tipoPacote;
    // Instância de Observable para representar o objeto observável
    Observable observable;
    observable.numObservers = 0; // Inicialização do número de observadores

    printf("Digite o Nome: ");
    scanf("%s", nome);

    printf("Digite a Serial: ");
    scanf("%d", &serial);

    // Calcular o CRC para o nome inserido
    uint32_t crc = crc32((unsigned char *)nome, strlen(nome));
    // Dados após o cálculo do CRC do nome
    printf("CRC calculado - nome: %08X\n", crc);
    uint32_t crc_function = crc32((unsigned char *)checa, 63);
    // Dados após o cálculo do CRC da funcao checa
    printf("CRC calculado - função: %08X\n", crc_function);

    // Criar um pacote de dados com o nome, serial e CRC
    PacoteDados pacote;
    pacote.tipo = PACKET_TYPE_DATA; // Definição do tipo de pacote conforme necessário
    pacote.comprimento = strlen(nome);
    strcpy(pacote.dados, nome);
    pacote.crc = crc;

    if (checa(nome, serial))
    {
        printf("\nResultado:\nDados corretos!\n");

        // Verificar se o pacote de dados é válido
        if (validarPacote(&pacote))
        {
            // Registrar os observadores usando a função addObserver
            addObserver(&observable, pacote.tipo, pacoteRecebido);

            // Quando um novo pacote de dados for recebido e validado, chama a função notifyObservers
            notifyObservers(&observable, &pacote);
        }
    }
    else
    {
        printf("\nResultado:\nTente outra vez...\n");
    }

    return 0;
}

// Função para verificar se o pacote de dados é válido
bool validarPacote(PacoteDados *pacote)
{
    // //     // Verificar o cabeçalho do pacote
    if (pacote->dados[0] != START_SYMBOL)
    {
        printf("Erro: Cabeçalho do pacote inválido!\n");
        // return false;
    }
    else
    {
        printf("Cabeçalho do pacote válido!\n");
    }
    // Verificar se o comprimento dos dados é válido (não vazio)
    if (pacote->comprimento == 0)
    {
        printf("Erro: Comprimento dos dados inválido!\n");
        return false;
    }

    // Verificar se os dados são os mesmos antes e depois do cálculo do CRC
    if (strncmp(pacote->dados, pacote->dados, pacote->comprimento) != 0)
    {
        printf("Erro: Os dados foram alterados entre o cálculo do CRC e a criação do pacote.\n");
        // return false;
    }
    // Verificar se o CRC é correto para os dados
    uint16_t crc_calculado = crc32((unsigned char *)pacote->dados, pacote->comprimento);
    if (crc_calculado != pacote->crc)
    {
        printf("Erro: CRC inválido!\n");
        return false;
    }

    // Pacote válido
    return true;
}

// Função de callback para o observer
void pacoteRecebido(PacoteDados *pacote)
{
    printf("\nPacote de dados recebido:\n");
    printf("Tipo: %d\n", pacote->tipo);
    printf("Comprimento: %d\n", pacote->comprimento);
    printf("Dados: %s\n", pacote->dados);
    printf("CRC: 0x%04X\n", pacote->crc);
}
