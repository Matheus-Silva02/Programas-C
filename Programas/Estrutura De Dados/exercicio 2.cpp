//2.	Faça um código em C que permite ao usuário criar uma lista com os seguintes dados: CPF usuário, Nome do curso, ano de início. Realize as seguintes operações utilizando funções:
//a.	Inserir nó na lista – final 
//b.	Imprimir a lista 
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

struct aluno
{
char cpf[11];
char curso[30];
char data[10];

struct aluno *proximo;

};

void inserir_final(struct aluno** topo,char cpf2[11],char curso2[30],char data2[10])
{
struct aluno *novo = (struct aluno*)malloc(sizeof(struct aluno));

strcpy(novo->cpf, cpf2);
strcpy(novo->curso, curso2);
strcpy(novo->data, data2);
(novo->cpf[11])= '\0';
novo->proximo = NULL;

if(*topo == NULL)
{
 *topo=novo;
}

else
{
struct aluno* temp = *topo;
    while(temp->proximo != NULL)
    {
     temp= temp->proximo;   

    }
  temp->proximo=novo;
}

}

void listar(struct aluno* topo)
    {
    
    struct aluno* temp = topo;

        while(temp != NULL)
        {
        
        printf("\n\nCpf do aluno:%s",temp->cpf);
        printf("\nCurso do aluno:%s",temp->curso);
        printf("\nData de ingresso do aluno:%s",temp->data);
        temp = temp->proximo;
        }
    printf("\n\n");
    }
    int validarcpf(char cpf[11]);

    int main()
{
     struct aluno* topo = NULL;
     char cpf3[11],data3[11],curso3[30];
     int o=0;
     
     
     while(o!=3) //Menu
    {
      printf("\n1-Inserir informacao ");
      printf("\n2-Mostrar informacoes");
      printf("\n3-Desligar programa");
      printf("\nSeleciona uma opcao:");
      scanf("%i",&o);

        switch(o)
        {
            case 1: 
            do
            {
            printf("\nDigite o CPF do aluno:");
            scanf("%s",cpf3);
            }
            while(validarcpf(cpf3) != 0);
            fflush(stdin);         
            printf("\nDigite o curso do aluno:");
            scanf("%s",curso3);
            printf("\nDigite a data de inscricao do aluno:");
            scanf("%s",data3);
            printf("\n");
            inserir_final(&topo,cpf3,curso3,data3); 
            break;

            case 2:
            
            listar(topo);
            break;

        }
    }
      return 0;  
}

int validarcpf(char cpf[11])
{
    int num=0,r1=0,r2=0,j,a=0;

    for(j=0; j<11;j++)
    {
        if((cpf[j] > 47) && (cpf[j] < 59))
        {
            if(cpf[j]==cpf[j+1])
            {
                a++;
            }
            if(j < 10)
            {
                num = (cpf[j] - '0');
                r2 += (num*(11-j));
            }
            if(j < 9)
            {
                r1 += (num*(10-j));
            }
        }
        else
        {
            printf("\n  CPF Digitado incorretamente\n");
            return 1;
        }
    }
    if(j!=11)
    {

       return 1; 
    }
    if(a==10)
    {
        printf("\n  Invalido\n");
        return 1;
    }
    r1 %=11;
    r2 %=11;
    if(r1 < 2)
    {
        r1=0;
    }
    else
    {
        r1 = (11 - r1);
    }
    if(r2 < 2)
    {
        r2=0;
    }
    else
    {
        r2 = (11 - r2);
    }
    if((r1 != (cpf[9] - '0')) || (r2 != (cpf[10] - '0')))
    {
        printf("\n  Invalido\n");
        return 1;
    }
    else
    {
        printf("\n  Valido\n");
        return 0;
    }
}
    

