#include <stdio.h>
#include <stdlib.h>
#include <cstring>



typedef struct no
{
char cpf[11];
int numero;
int prioridade;

no *proximo;
}nodo;

void insercao(nodo **topo,int num_funcao,char cpf_funcao[11],int prioridade_funcao);
void imprimir(nodo *topo);
int menu();
void remover(nodo **topo);


int main()
{

nodo *topo=NULL;
int numero_main,opcao,prioridade_main;
char cpf_main[11];


while(opcao != 3)
{
    opcao=menu();
    switch(opcao)
    {
        case 1:
            printf("\nNumero do documento:");
            scanf("%i",&numero_main);
            printf("\nCpf:");
            scanf("%s",cpf_main);
            printf("\nPrioridade:");
            scanf("%i",&prioridade_main);
            insercao(&topo,numero_main,cpf_main,prioridade_main);
            break;

        case 2:
            if(topo==NULL)
                {
                printf("Lista vazia.\n");
                break;
                }
            else
            {
                printf("Fila de impressao:\n\n");
                imprimir(topo);                
                remover(&topo);
                break;
            }
            

    }

}

return 0;    
}

void insercao(nodo **topo,int num_funcao,char cpf_funcao[11],int prioridade_funcao)
{
nodo *novo=(nodo*)malloc(sizeof(nodo));

novo->numero=num_funcao;
strcpy(novo->cpf,cpf_funcao);
novo->prioridade=prioridade_funcao;

novo->proximo= *topo;
*topo=novo;
}
void imprimir(nodo *topo)
{


nodo *temp=topo;


while(temp !=NULL)
{
    printf("\nNumero do documento: %i",temp->numero);
    printf("\tCpf:%s",temp->cpf);
    printf("\tPrioridade: %i",temp->prioridade);
    printf("\t endereco atual:%p \t endereco proximo:%p ",temp,temp->proximo);
    printf("\n%p",topo);
    printf("\n");
    temp=temp->proximo;

}

printf("\n");

}
int menu()
{
int o;

printf("\n1-Inserir cadastro:");
printf("\n2-Imprimir documento(remover o primeiro da lista)");
printf("\n3-Sair");
printf("\nSelecione uma opcao:");
scanf("%i",&o);
return o;

}
void remover(nodo **topo)
{
    nodo *aux = *topo;
    nodo *anterior;
    if(*topo == NULL)
    {
        printf("Lista vazia.\n");

    }
    else
    {  
        if (aux->prioridade == 1)
        {
            *topo = aux->proximo;
            free(aux);
            printf("Excluido no com prioridade 1.\n");
            return;
        }
 
        while(aux->proximo != NULL)
        {   
            
            
            anterior=aux;
            aux=aux->proximo;

            if (aux->prioridade == 1)
            {
                anterior->proximo = aux->proximo;
                free(aux);
                printf("Excluido no com prioridade 1.\n");
                return;
            }
            
             
        }

        if(aux==*topo)
        {
            free(aux);
            *topo=NULL;
            printf("Excluido primeiro valor");
        }
        else
        {   
            
            
            anterior->proximo=NULL;
            free(aux);
            printf("Excluido");
            
        }
    }


}