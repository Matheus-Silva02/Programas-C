//Faça uma função para retirar elementos repetidos de uma lista. Deixe o usuários entrar com os valores, imprimir os valores e selecionar a opção remoção de valores repetidos. Mostre quantos elementos foram excluídos com repetição.

//Escreva uma função que multiplica todos os elementos de uma lista por um valor, crie o último nó de checagem, que sempre irá conter qual é esse valor usado para multiplicação. Permita sempre ao usuário digitar elementos para a lista, imprimir a lista e digitar o valor para multiplicar os demais elementos. 
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

typedef struct listas
{

int valor;
struct listas *proximo;

}lista;

void inserir(lista **topo,int valor_funcao);
void remover(lista **topo);
void listar(lista *topo);
int menu();
void remover_repetidos(lista **topo);
void multiplicar(lista *topo,int x);

int main()
{
    lista *topo=NULL;
    int opcao,valor_main,x;

    while(opcao != 5)
    {
        opcao=menu();

        switch(opcao)
        {

            case 1:
            printf("\nInforme o valor a ser adicionado a lista:");
            scanf("%i",&valor_main);
            inserir(&topo,valor_main);
            break;

            case 2:
            remover(&topo);
            break;

            case 3:
            printf("Lista:");
            listar(topo);
            break;

            case 4:
            remover_repetidos(&topo);
            break;

            case 6:
            printf("\nInforme o valor a ser multiplicado:");
            scanf("%i",&x);
            multiplicar(topo,x);
            break;
        }
    }
    return 0;
}

void inserir(lista **topo, int valor_funcao) 
{
     lista *novo = (lista*)malloc(sizeof(lista)); 
     novo->valor = valor_funcao;
     novo->proximo= *topo;
     *topo = novo;
}
void remover(lista **topo) 
{
   lista *auxiliar;
   auxiliar=*topo; 
   *topo=auxiliar->proximo; 
   free(auxiliar); 
   printf("\nExcluido com sucesso");

}
void listar(lista *topo) 
{ 
    lista *temporario = topo;
    while(temporario != NULL)
    {   
        printf("\nValor:%i", temporario->valor);
        temporario = temporario->proximo;
    }    
    printf("\n\n");
}
int menu()
{
int o;

printf("\n\n1-Inserir valor");
printf("\n2-Remover valor");
printf("\n3-Listar valores");
printf("\n4-Remover valores repetidos");
printf("\n5-Sair");
printf("\n6-Multiplicar valores da lista por x valor");
printf("\nSelecione uma opcao:");
scanf("%i",&o);


return o;





}
void remover_repetidos(lista **topo)
{
    lista *auxiliar=*topo;
    while(auxiliar != NULL)
    {
        lista *auxiliar2=auxiliar;

        while (auxiliar2->proximo != NULL)
        {
            if(auxiliar2->proximo->valor == auxiliar->valor)
            {
                lista *temp = auxiliar2->proximo;
                auxiliar2->proximo=auxiliar2->proximo->proximo;
                free(temp);
            }
            else
            {
                auxiliar2 = auxiliar2->proximo;
            }  
        }
    auxiliar=auxiliar->proximo;
    }

}
void multiplicar(lista *topo, int x)
{

    lista *aux=topo;
    while(aux != NULL)
    {
        aux->valor=(aux->valor)*(x);
        aux=aux->proximo;

    }
    //Criar nó de checagem
    lista *base = (lista*)malloc(sizeof(lista));
    base->valor=x;
    base->proximo=NULL;


    //Adicionar nó de checagem na base da lista
    if(topo == NULL)
    {
        topo= base;
    }
    else
    {
        lista *temp = topo;
        while(temp->proximo != NULL)
        {
            temp=temp->proximo;
        }
    temp->proximo=base;
    }
}

