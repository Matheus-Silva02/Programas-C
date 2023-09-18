#include <stdio.h>
#include <stdlib.h>

struct nodo  //nodo da lista
{
int valor;
struct nodo *proximo;
};

void inserir_final(struct nodo **topo,int valor_funcao); //OK
void inserir_inicio(struct nodo **topo,int valor_funcao); //OK
void listar(struct nodo *topo); //OK
void excluir_final(struct nodo **topo); //OK
void excluir_inicio(struct nodo **topo); //ok
void excluir_meio(struct nodo **topo,int posicao); //OK
int buscar(struct nodo *topo,int valor_funcao); //OK
void inserir_antes_k(struct nodo **topo,int valor_escolhido,int valor_funcao); //OK
void inserir_depois_k(struct nodo **topo,int valor_escolhido,int valor_funcao); //OK
int menu(); // OK
void inserir_meio(struct nodo **topo,int valor_funcao, int posicao); //OK

int main() //Função main

{
    struct nodo *topo=NULL;
    int o=0,valor_main=0;
    int valor_buscado=0;


    while(o!=9)
    {
        o=menu();
        switch(o)
        {
            case 1:
            printf("Digite o valor a ser inserido no inicio:");
            scanf("%i",&valor_main);
            inserir_inicio(&topo, valor_main);
            break;


            case 2:
            printf("Digite o valor a ser inserido no final:");
            scanf("%i",&valor_main);
            inserir_final(&topo, valor_main);
            break; 

            case 3:
             printf("\nEscolha o valor a ser buscado:");
            scanf("%i",&valor_buscado);
            printf("Digite o valor a ser inserido:");
            scanf("%i",&valor_main);
            inserir_antes_k(&topo,valor_buscado,valor_main);
            break;

            case 4:
            printf("\nEscolha o valor a ser buscado:");
            scanf("%i",&valor_buscado);
            printf("Digite o valor a ser inserido:");
            scanf("%i",&valor_main);
            inserir_depois_k(&topo,valor_buscado,valor_main);
            break;


            case 5:
            excluir_inicio(&topo);
            break;

            case 6:
            excluir_final(&topo);
            break;

            case 7:
            int buscar_valor;
            int posicao;
            printf("Digite o valor a ser procurado:");
            scanf("%i",&buscar_valor);
            posicao= buscar(topo,buscar_valor);

            if (posicao != -1)
            {
                printf("O valor foi encontrado na posicao: %i",posicao);
            }
            else
            {
                printf("Valor nao encontrado na lista.\n");

            }
            break;

            case 8:
            printf("Valores:");
            listar(topo);
            break;

            case 10:
            printf("Digite o valor a ser inserido no meio:");
            scanf("%i",&valor_main);
            inserir_meio(&topo,valor_main,2);
            break;

            case 11:
            excluir_meio(&topo,2);
            printf("Valor excluido com sucesso\n");
            break;


        }
















            
    }


        return 0;
}


int menu() //função do menu
{
    int opcao;

    printf("\n\n1-Inserir no Inicio da lista\n");
    printf("2-Inserir no final da lista\n");
    printf("3-Inserir antes do K\n");
    printf("4-Inserir depois do K\n");
    printf("5-Apagar no inicio da lista\n");
    printf("6-Apagar no final da lista\n");
    printf("7-Buscar valor\n");
    printf("8-Listar valores da lista\n");
    printf("9-Sair do programa\n");
    printf("10-Inserir no meio da lista\n");
    printf("11-Apagar no meio da lista\n");
    printf("Selecione uma opcao:");
    scanf("%i",&opcao);


    return opcao;   



}
void inserir_inicio(struct nodo** topo, int valor_funcao) //função de inserir no inicio. O ponteiro duplo é para ele enviar o valor apontado pelo ponteiro topo, se fosse um único ponteiro,ele enviaria o valor apontado pelo topo

{
    //primeiro é colocar a lista como um vetor infinito

    //Se cria um novo tipo de variável struct nodo e o iguala ao struct nodo 

     struct nodo* novo = (struct nodo*)malloc(sizeof(struct nodo)); //malloc(sizeof(struct nodo)) aloca espaço indefinido para a estrutura nodo e (struct nodo*) é para definir o ponteiro genérico do tipo void como um struct nodo

     //agora é preciso colocar os valores da função para apontar para a struct

     novo->valor = valor_funcao;

     //é preciso que o novo aponte para a struct original,e o iguale a variável que está sendo usada na função para usar na main

     novo->proximo= *topo;
    
    //iguala o valor do topo ao novo
     *topo = novo;
}
void inserir_final(struct nodo **topo,int valor_funcao) //Função de inserir no final
{
    struct nodo *novo = (struct nodo*)malloc(sizeof(struct nodo));
    novo->valor = valor_funcao;

    if (*topo == NULL) 
    {
        novo->proximo = novo; // Lista vazia, o novo nó aponta para si mesmo
        *topo = novo; // Define o topo como o novo nó
    }
    else 
    {
        novo->proximo = (*topo)->proximo; // Aponta para o primeiro nó
        (*topo)->proximo = novo; // Define o próximo do último nó como o novo nó
        *topo = novo; // Define o novo nó como o último nó
    }
}
void listar(struct nodo* topo) //Função de listagem
{
     
     struct nodo *temporario = topo;
    while(temporario != NULL)
    {   
        
        printf("\nValor:%i", temporario->valor);
        temporario = temporario->proximo;
    }    
    printf("\n\n");

}
void excluir_inicio(struct nodo **topo) //Função de excluir no inicio
{
   struct nodo *auxiliar; //Cria um ponteiro auxiliar do tipo struct nodo
   auxiliar=*topo; //Iguala esse valor ao endereço apontado pelo topo
   *topo=auxiliar->proximo; //o auxiliar aponta pro endereço que o topo deu, e pega o valor do proximo, e iguala ao topo
   free(auxiliar); //apaga este valor da memória
   printf("\nExcluido com sucesso");

}
void excluir_final(struct nodo **topo) //Função de excluir no final
{
if (*topo == NULL) 
    {
        printf("Lista vazia.\n");
        return;
    }

    struct nodo *atual = *topo;
    while (atual->proximo != *topo) 
    {
        // Enquanto não chegar  de volta ao primeiro nó, continua avançando
        atual = atual->proximo;
    }

    if (atual == *topo) {
        // Se só houver um nó na lista, libere-o e defina o topo como NULL
        free(*topo);
        *topo = NULL;
    } 
    else 
    {
        // Caso contrário, ajuste o próximo do penúltimo nó para apontar para o novo primeiro nó
        struct nodo *temporario = *topo;
        while (temporario->proximo != atual) {
            temporario = temporario->proximo;
        }
        temporario->proximo = (*topo)->proximo;
        free(atual);
    }
}
void inserir_meio(struct nodo **topo,int valor_funcao, int posicao)//Função de inserir no meio da lista
{
    struct nodo *novo = (struct nodo*)malloc(sizeof(struct nodo));
    if (novo==NULL)
    {
        printf("Erro"); //mensagem de erro
        return;
    }
    novo->valor=valor_funcao;

    if(posicao == 1 || *topo==NULL)
    {
        novo->proximo = *topo; //Inserção em uma lista vazia
        *topo = novo;

    }
    else
    {
        struct nodo *atual = *topo;
        int contador=1;
        while(atual !=NULL && contador < posicao-1)
        {
            atual = atual->proximo;
            contador++;    
        }

    novo->proximo = atual->proximo;
    atual->proximo = novo;
    }

}
void excluir_meio(struct nodo **topo,int posicao)//Função de excluir no meio da lista
{
    if(*topo == NULL)
    {
        printf("Lista vazia.");
        return;

    }
    if(posicao == 1)
    {
        struct nodo *temporario = *topo;
        *topo = (*topo)->proximo;
        free(temporario);
        return;
    }
   struct nodo *atual = *topo;
   struct nodo *anterior = NULL;
   int contador=1;

   while(atual != NULL && contador < posicao)
   {
    anterior=atual;
    atual= atual->proximo;
    contador++;

   }
   anterior -> proximo = atual->proximo;
   free(atual);

}
int buscar(struct nodo *topo, int valor_funcao)//Função de buscar um valor especifico na lista
{
    int posicao=1;
    struct nodo *atual=topo;

    while(atual != NULL) //Roda a lista para achar o valor
    {
        if(atual->valor == valor_funcao) 
        {           

            return posicao; //posição achada e retornada
        }
        atual = atual->proximo;
        posicao++;
    }
return -1; //caso não achar o valor, retorna -1


}
void inserir_depois_k(struct nodo **topo,int valor_escolhido,int valor_funcao) //Função de inserir um valor depois de um outro escolhido
{
    struct nodo *novo = (struct nodo*)malloc(sizeof(struct nodo));
    novo->valor = valor_funcao;
    

    if((*topo)->valor == valor_escolhido) //Verificar se está no primeiro nodo
    {
        novo->proximo = *topo; //iguala o proximo ao topo
        *topo = novo; // Igualar o valor apontado pelo topo ao novo
        return;
    }

    struct nodo *atual = *topo;
    while(atual->proximo != NULL) //Rodar a lista para achar o valor
    {
        if(atual->proximo->valor == valor_escolhido) //achar o valor escolhido
        {   
            novo->proximo=atual->proximo; 
            atual->proximo=novo;
        return; // Caso achado, retorna o valor
        }
        atual = atual->proximo;
    }
    printf("Valor %i nao achado na lista",valor_escolhido);
    free(novo);
}
void inserir_antes_k(struct nodo **topo,int valor_escolhido,int valor_funcao)//Função de inserir antes de um valor escolhido
{
    struct nodo *novo = (struct nodo*)malloc(sizeof(struct nodo));
    novo->valor=valor_funcao; //Novo aponta para o valor na struct
   

    struct nodo *atual = *topo;
    while(atual !=NULL) //Buscar valor
    {
        if(atual->valor == valor_escolhido) //Achar o valor
        {
            novo->proximo = atual->proximo;
            atual->proximo= novo;
            return; // retorna caso achado o valor

        }
        atual= atual->proximo;


    }

    printf("Valor %i nao encontrado na lista",valor_escolhido);
}






