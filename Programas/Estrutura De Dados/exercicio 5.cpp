//5.	Uma pizzaria precisa cadastrar produtos, clientes e fazer o controle de vendas. É preciso ter o cadastro de produto-pizza (código, nome da pizza, preço), um cadastro de cliente (código, nome, endereço) e um cadastro de venda (código da pizza e código do cliente, qtd de pizza, valor pago)

//Faça um menu para:  
    //Gravar dados das pizzas / 
    //Gravar dados dos clientes /
    //Gravar venda
    //Ler dados das pizzas
    //Ler dados dos clientes
     //Ler vendas


//a.	Grave os dados em arquivos.
//b.	Faça a leitura dos arquivos
//c.	Ao final do dia, imprimir a quantidade de pizzas vendidas e o valor total recebido.
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <cstring>

typedef struct pizza 
{
int codigo_pizza;
char nome_pizza[20];
float preco_pizza;
struct pizza *proximo;


}piza;

typedef struct cliente 
{
int codigo_cliente;
char nome_cliente[20];
char endereco_cliente[30];
struct cliente *proximo;


}client;

typedef struct venda
{
int codigo_venda;
int quantidade_vendas;
float valor_vendas;
struct venda *proximo;


}vendas;

void inserir_pizza(piza ** topo,int codigo,char nome[20],float preco);
void inserir_cliente(client ** topo,int codigo,char nome[20],char endereco[30]);
void inserir_venda(vendas ** topo,int codigo,int quantidade,float valor);



int main()
{
FILE *arq;
arq=fopen("Lista","ab");   

 int o=0,codigop=1,codigoc=0,codigov=0,quantidadev=0;
 char nomep[20],nomec[20],enderecoc[20];
 float precop,valorv;
 client *lista_cliente=NULL;
 piza *lista_pizza=NULL;
 vendas *lista_vendas=NULL;
 while(o!=7)
 {
 printf("\n1-Inserir informacoes de pizza:");
 printf("\n2-Inserir informacoes de cliente:");
 printf("\n3-Inserir informacoes de vendas:");
 printf("\n4-Listas informacoes de pizza:");
 printf("\n5-Listas informacoes de cliente:");
 printf("\n6-Listas informacoes de vendas:");
 printf("\n7-Sair");
 printf("\nInserir informcao:");
 scanf("%i",&o);

    switch(o)
    {

    case 1:
    printf("\nInserir codigo da pizza:");
    scanf("%i",&codigop);
    printf("\nInserir nome da pizza:");
    scanf("%s",nomep);
    printf("\nInserir preco da pizza:");
    scanf("%f",&precop);
    inserir_pizza(&lista_pizza,codigop,nomep,precop);
    fwrite(&lista_pizza,sizeof(piza),1,arq);
    break;

    case 2:
    printf("\nInserir codigo do cliente:");
    scanf("%i",&codigoc);
    printf("\nInserir nome do cliente:");
    scanf("%s",nomec);
    printf("\nInserir endereco do cliente:");
    scanf("%s",enderecoc);
    inserir_cliente(&lista_cliente,codigoc,nomec,enderecoc);
    fwrite(&lista_cliente,sizeof(client),1,arq);
    break;

    case 3:
    printf("\nInserir codigo de vendas:");
    scanf("%i",&codigov);
    printf("\nInserir nome do cliente:");
    scanf("%i",&quantidadev);
    printf("\nInserir endereco do cliente:");
    scanf("%f",&valorv);
    inserir_venda(&lista_vendas,codigov,quantidadev,valorv);
    fwrite(&lista_vendas,sizeof(vendas),1,arq);
    break;

    case 4:
    fread(&lista_pizza,sizeof(piza),1,arq);
    break;

    case 5:
    fread(&lista_cliente,sizeof(client),1,arq);
    break;

    case 6:
    fread(&lista_vendas,sizeof(vendas),1,arq);
    break;
    

    }





 }





  return 0;  
}


void inserir_pizza(piza ** topo,int codigo,char nome[20],float preco)
{
piza *novo =(piza*)malloc(sizeof(piza));
novo->codigo_pizza=codigo; 
strcpy(novo->nome_pizza,nome);
novo->preco_pizza=preco;

novo->proximo= *topo;
*topo=novo;

}

void inserir_cliente(client ** topo,int codigo,char nome[20],char endereco[30])
{
client *novo =(client*)malloc(sizeof(client));
novo->codigo_cliente=codigo; 
strcpy(novo->nome_cliente,nome);
strcpy(novo->endereco_cliente,endereco);

novo->proximo= *topo;
*topo=novo;

}

void inserir_venda(vendas ** topo,int codigo,int quantidade,float valor)
{
vendas *novo =(vendas*)malloc(sizeof(vendas)); 
novo->codigo_venda=codigo;
novo->quantidade_vendas=quantidade;
novo->valor_vendas=valor; 


novo->proximo= *topo;
*topo=novo;

}
