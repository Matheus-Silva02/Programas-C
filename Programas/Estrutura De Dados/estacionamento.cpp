#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARROS 100

struct Carro 
{
    char placa[10];
};
struct Estacionamento
{
    struct Carro carros[MAX_CARROS];
    int ocupados;
};

void entraEstacionamento(struct Estacionamento *estacionamento, char placa[]);
int saiEstacionamento(struct Estacionamento *estacionamento, char placa[]);

int main() 
{
    struct Estacionamento estacionamento;
    estacionamento.ocupados = 0;

    while (1) {
        char opcao;
        char placa[10];
        printf("Digite a operacao (E para entrada, S para saida, Q para sair): ");
        scanf(" %c", &opcao);

        if (opcao == 'Q' || opcao == 'q') 
        {
            break;
        }

        printf("Digite a placa do carro: ");
        scanf("%s", placa);

        if (opcao == 'E' || opcao == 'e') 
        {
            entraEstacionamento(&estacionamento, placa);
        } 
        else if (opcao == 'S' || opcao == 's')
        {
            int manobras = saiEstacionamento(&estacionamento, placa);
            if (manobras == -1) 
            {
                printf("Carro %s nao encontrado no estacionamento.\n", placa);
            }
        } 
        else 
        {
            printf("Opcao invalida.\n");
        }
    }

    return 0;
}

void entraEstacionamento(struct Estacionamento *estacionamento, char placa[]) 
{
    if (estacionamento->ocupados < MAX_CARROS) 
    {
        strcpy(estacionamento->carros[estacionamento->ocupados].placa, placa);
        estacionamento->ocupados++;
        printf("Carro %s entrou no estacionamento.\n", placa);
    } 
    else 
    {
        printf("Carro %s nao pode entrar no estacionamento, nao ha vagas disponiveis.\n", placa);
    }
}
int saiEstacionamento(struct Estacionamento *estacionamento, char placa[])
{
    int manobras = 0;
    for (int i = 0; i < estacionamento->ocupados; i++) 
    {
        if (strcmp(estacionamento->carros[i].placa, placa) == 0)
        {
            printf("Carro %s saiu do estacionamento apos %d manobras.\n", placa, manobras);
            for (int j = i; j < estacionamento->ocupados - 1; j++) 
            {
                strcpy(estacionamento->carros[j].placa, estacionamento->carros[j + 1].placa);
            }
            estacionamento->ocupados--;
            return manobras;
        }
        manobras++;
    }
    return -1; // Carro não encontrado
}
