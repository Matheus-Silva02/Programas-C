#include <stdio.h>
#include <stdlib.h>

typedef struct estrutura
{
int valor;

struct estrutura *proximo;


}pilha;

void inserir(pilha **topo, int valor_funcao);
void imprimir(pilha *topo);
void remover(pilha **topo);
int menu();

int main()
{
    pilha *topo=NULL;
    int opcao,valor_main;

    while(opcao!=4)
    {
        opcao=menu();

        switch(opcao)
        {
            case 1:
            printf("\nValor a ser colocado na pilha:");
            scanf("%i",&valor_main);
            inserir(&topo,valor_main);
            break;

            case 2:
            remover(&topo);
            printf("\nRemovido com sucesso.");
            break;


            case 3:
            imprimir(topo);





        }

    }
    return 0;   
}

int menu()
{
    int o;

    printf("\n\nEscolha uma opcao:");
    printf("\n1-Adicionar elemento");
    printf("\n2-Remover elemento");
    printf("\n3-Imprimir pilha");
    printf("\n4-Sair");
    printf("\nEscolha uma opcao:");
    scanf("%i",&o);




    return o;   
}
void inserir(pilha **topo,int valor_funcao)
{
    pilha *novo=(pilha*)malloc(sizeof(pilha));

    novo->valor=valor_funcao;

    novo->proximo=*topo;

    *topo=novo;

}
void imprimir(pilha *topo)
{
    if(topo==NULL)
    {
        printf("\nPilha vazia");

    }
    else
    {
        pilha *temp= topo;
        printf("\nPilha:");
        while(temp != NULL)
        {
            printf("\nValor: %i",temp->valor);

            temp=temp->proximo;
        }
        printf("\n\n");
    }
}
void remover(pilha **topo)
{
    pilha *temp=*topo;

    if(*topo==NULL)
    {
        printf("Pilha vazia");
    }
    else
    {
    *topo=temp->proximo;
     free(temp);
     


    }





}




