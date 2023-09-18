//Crie uma pilha (pilha1) e peça ao usuário para dizer qual elemento da pilha deve ser removido. Caso seja o último que foi inserido, apresente a pilha impressa. Caso o elemento que se deseja excluir não seja o último, crie uma nova pilha(pilha2), desempilhe os elementos pilha 1 para a pilha 2, até que chegue ao elemento que se desejou desempilhar. Neste momento imprima as duas pilhas. Posteriormente, volte a pilha 1, sendo que os elementos da pilha 2, devam ser novamente empilhados para a pilha 1.
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define MAX 5    

typedef struct    
{
int valor[MAX];
int topo;
}pilhas;

void ininicializar(pilhas *aux); //ok
int verificar_vazia(pilhas *aux); //ok
int verificar_cheia(pilhas *aux);//ok
void empilhar(pilhas *aux,int valor_funcao);//ok
int desempilhar(pilhas *aux);//ok
void imprimir(pilhas *aux);//ok

int main()
{
    pilhas pilha1,pilha2;
    int opcao=0,valor_main_adicionar,valor_topo,valor_main_remover;

    ininicializar(&pilha1);
    ininicializar(&pilha2);

    

    while (opcao !=3)
    {
        printf("\nDeseja Empilhar[1] Desempilhar [2] ou Sair do programa[3]?:");
        scanf("%i",&opcao);
        while (opcao>3 || opcao<1)
        {
            printf("\nOpcao invalida.\nDeseja Empilhar[1] Desempilhar [2] ou Sair do programa[3]:");
            scanf("%i",&opcao);
        }

        switch (opcao)
        {
            case 1:
            printf("\nInforme o valor que deseja empilhar:");
            scanf("%i",&valor_main_adicionar);
            empilhar(&pilha1,valor_main_adicionar);
            break;

            case 2:
            printf("\nInforme o valor que deseja remover:");
            scanf("%i",&valor_main_remover);
            
                if(valor_topo==valor_main_remover)
                {   
                    valor_topo=desempilhar(&pilha1);
                    printf("\nValor removido do topo,%i",valor_topo);
                    printf("\nPilha 1:");
                    imprimir(&pilha1);
                    break;

                }
            else
            {   
            while(!verificar_vazia(&pilha1))
            {
                valor_topo=desempilhar(&pilha1);
                if(valor_topo==valor_main_remover)
                {
                    printf("\nValor removido,%i",valor_topo);
                    break;
                }
                empilhar(&pilha2,valor_topo);

            }
            printf("\nPilha 1:");
            imprimir(&pilha1);
            printf("\nPilha 2:");
            imprimir(&pilha2);
            while(!verificar_vazia(&pilha2))
            {
                int valor_topo2=desempilhar(&pilha2);
                empilhar(&pilha1,valor_topo2);
            }
            printf("\nPilha 1 apos a transferencia:");
            imprimir(&pilha1);
            break;

            }

        }
        
    }
    
    return 0;
}


void ininicializar(pilhas *aux)
{
aux->topo= -1;

}
int verificar_vazia(pilhas *aux)
{
    return aux->topo== -1;
}
int verificar_cheia(pilhas *aux)
{
return aux->topo==MAX-1;
}
void empilhar(pilhas *aux,int valor_funcao)
{

    if(!verificar_cheia(aux))
    {
        aux->topo++;
        aux->valor[aux->topo]=valor_funcao;
    }
    else
    {
       printf("\nPilha cheia.");
    }
}
int desempilhar(pilhas *aux)
{
int valor_funcao;
    if(!verificar_vazia(aux))
    {
        valor_funcao=aux->valor[aux->topo];
        aux->topo--;
        return valor_funcao;

    }
    else
    {
       printf("\nPilha vazia.");
       return -1;
    }


}
void imprimir(pilhas *aux)
{

    for(int i=0;i<=aux->topo;i++)
    {
        printf("\nValor:%i",aux->valor[i]);
    }


}




