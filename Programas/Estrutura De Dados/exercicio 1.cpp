//1.	Suponha que em um laboratório, cada paciente quando chega escolhe uma senha para atendimento. Essa senha pode ser para realizar exames de sangue ou exames de imagem. Quando um paciente é chamado pelo atendente ele deve informar o número da senha, seu nome, o plano de saúde(Unimed/Ipê) e o tipo de exame a fazer(sangue/imagem). Ao término do dia, cada atendente gera a listagem dos pacientes que ele atendeu. Apresente:

//a)	A listagem dos pacientes atendidos
//b)	A quantidade de pacientes atendidos que possuem Unimed.
//c)	A quantidade de pacientes atendidos para realizar exames de Sangue.

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <cstring>

//Struct dos pacientes

struct pacientes
{
int senha;
char nome[30];
int plano_saude;
int tipo_exame;
struct pacientes* proximo;

};
//função de inserir
void inserir(struct pacientes** topo,int senha1,char nome2[30],int plano2,int tipo2)
    {
    struct pacientes* novo = (struct pacientes*)malloc(sizeof(struct pacientes));
	
    novo->senha=senha1;
    //novo->nome=nome2;  nao da pra passa uma string pra outra assim kkkkk
    strcpy(novo->nome, nome2);
    novo->plano_saude =plano2;
    novo->tipo_exame = tipo2;
    
    novo->proximo= *topo;   // tem que definir para aonde o novo nodo vai apontar, nesse caso
                            // botei pra o novo sempre aponta pro topo antigo
    *topo = novo;           // e transformei o novo no topo.
    }

// função de listagem
void listar(struct pacientes* topo)
    {
    
    struct pacientes* temp = topo;

        while(temp != NULL)
        {
        
        printf("\n\nSenha:%d",temp->senha);
        printf("\nNome:%s",temp->nome);
        printf("\nPlano de saude:%d",temp->plano_saude);
        printf("\nTipo de exame:%d",temp->tipo_exame);
        temp = temp->proximo;

        }
    printf("\n\n");
    }

    int main()
{
     struct pacientes* topo = NULL;
     int o=0,senha2,plano,tipo,contador=0,contador2=0;
     char nome1[30];
     
     
     while(o!=3) //Menu
    {
      printf("\n1-Inserir informacao de paciente");
      printf("\n2-Mostrar informacoes do dia");
      printf("\n3-Desligar programa");
      printf("\nSeleciona uma opcao:");
      scanf("%i",&o);

        switch(o)
        {
            case 1: 
            printf("\nDigite a senha do paciente:");
            scanf("%i",&senha2);
            printf("\nDigite o nome do paciente:");
            scanf("%s",nome1);
            printf("\nDigite o plano do paciente [1-Unimed e 2-Ipe]:");
            scanf("%i",&plano);
            if(plano==1)
            {
              contador=contador+1;

            }
            printf("\nDigite o tipo de exame [1-sangue 2-imagem]:");
            scanf("%d",&tipo);
             if(tipo==1)
            {
              contador2=contador2+1;

            }
            printf("\n");
            inserir(&topo,senha2,nome1,plano,tipo); 
            break;

            case 2:
            printf("Numero de pessoas que possuem Unimed:%i",contador);
            printf("\nNumero de pessoas que fizeram exame de sangue:%i\n",contador2);
            listar(topo);
            break;

        }
    }
      return 0;  
}