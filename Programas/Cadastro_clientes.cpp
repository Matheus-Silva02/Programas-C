//Utilizar "-" quando quiser dar espaço,devido as próprias limitações do scanf.

#include <stdio.h>
#include <string.h>



 struct cadastro
{
 char nome[50];
 char numero[11];
 char ende[30];
 char bairro[30];
 char nascimento[11];
 char ultima_compra[11];
 float valor_acumulado;
};


int menu();
void cadastro();
void case4();
int validar_data(char data[]);
int validar_cpf(char cpf[11]);

int main()
{
   FILE *file2;
   int i,o,contagem=0;
   char data[20];
   char temp[30];
   int validar_c2=0;
   int variavel;
  
   
  
struct cadastro y;
   
   
o=menu();
   
  while(o != 5)
     {
    while(o>5 || o<1)
    {
      printf("Informe um valor válido:");
      scanf("%i",&o);
    }
      switch(o)
    {
    
         case 1:
        {
         cadastro();
         break;
        
        }
        
        
        case 2:
         {
           file2=fopen("ficha_cadastro","rb");
      
            if(file2==NULL)
              {
                printf("\nNao existem usarios cadastrados...\n");
          
               }
           else
               {
             printf("\nInforme a data:");
             gets(data);
                    while(validar_data(data)!=1)
                    {
                    printf("\nInforme uma data valida:");   
                    gets(data); 
                    }
                 while(fread(&y,sizeof(struct cadastro),1,file2)==1)
                   { 
                            
                     if(strcmp(y.ultima_compra,data)==0)
                      {
                       validar_c2=1; 
                       printf("\n--------------------\n");     
                       printf("\nNome: %s",y.nome);
                       printf("\nCPF:");
                      for(i=0;i<11;i++)
                      {
                          if(i==3 || i==6)
                          {
                          printf(".");
                          }
                          if(i==9)
                          {
                          printf("-");
                          }
                          printf("%c",y.numero[i]);
                      }
                      
                       printf("\nEndereco: %s",y.ende);
                       printf("\n------------------\n");
                       }
                
                    }
            if(validar_c2 == 0)
            {
                printf("Nao existem cadastros nesta data.");
            }
                }
            validar_c2=0;    
         fclose(file2);   
         
       
         break; 
         }
        case 3:
         {
           file2=fopen("ficha_cadastro","rb");
      
           if(file2==NULL)
             {
          printf("\nNao existem usarios cadastrados...\n");
             }
      
           else
             {
               printf("informe o bairro:");
               scanf("%s",temp); 
      
               while(fread(&y,sizeof(struct cadastro),1,file2)==1)
                 {
                    if(strcmp(y.bairro,temp)==0)
                      {
                        contagem++;
                         variavel=1;
                       }
                      
                  
                 }
                if(variavel==1)
                {
                printf("Numero de pessoas do bairro [%s]: %i",temp,contagem); 
                
                }
                else
                {
                printf("\nNao existe cadastro neste bairro.");    
                }
               }
                contagem=0;
                variavel=0;
                fclose(file2); 
                
      
                break;
           }
   
   
        case 4:
         {
        
         case4();   
        
        break;
          }   
    }

   o=menu();
   
       
   }
   
    return 0;
}

int menu()
{
    
int opcao;

printf("\n----------------------MENU-------------------------");
printf("\n1-Cadastrar cliente");
printf("\n2-Listar clientes que fizeram compra em uma data especifica");
printf("\n3-Contar quantos clientes moram em certo bairro");
printf("\n4-cliente que tem o maior valor acumulado de compras");
printf("\n5-Fim");
printf("\n---------------------------------------------------\n");
scanf("%i",&opcao);

return opcao;
    
}

void cadastro()
{  
   
   FILE *FICHA;
   FILE *file2;
   struct cadastro y;
   file2=fopen("ficha_cadastro","ab");
   FICHA=fopen("Lista de cadastros.txt","a");
   if(file2==NULL || FICHA==NULL)
   {
      printf("Erro ao abrir!\n"); 
   } 
   else
   {    
        printf("\nInforme o nome do cadastro :");
        gets(y.nome);
        fprintf(FICHA," \nNome: %s",y.nome);
        
        printf("\nInforme o CPF do cadastro:");
        gets(y.numero);
       while(validar_cpf(y.numero)!=1)
        {
          printf("\nCPF invalido.Informe um CPF valido:");
         gets(y.numero);
        } 
        fprintf(FICHA,"\nCPF: %s",y.numero);
    
        printf("\nInforme o bairro do cadastro :");
        gets(y.bairro);
        fprintf(FICHA,"\nBairro: %s",y.bairro);
        
        printf("\nInforme o endereco do cadastro :");
        gets(y.ende);
        fprintf(FICHA,"\nEndereco: %s", y.ende);
        
        printf("\nInforme a data de nascimento do cadastro dd/mm/aaaa :");
        gets(y.nascimento);
        while(validar_data(y.nascimento)!=1)
        {
        printf("\nInforme uma data valida:");   
        gets(y.nascimento); 
        }
        fprintf(FICHA,"\nData de nascimento:%s",y.nascimento);
        
        printf("\nInforme a data da ultima compra do cadastro dd/mm/aaaa :");
        gets(y.ultima_compra);
        while(validar_data(y.ultima_compra)!=1)
      
        {
       
         printf("\nInforme uma data valida.");
         gets(y.ultima_compra);
         
        }
            
        fprintf(FICHA,"\nData da ultima compra: %s",y.ultima_compra);
        
        printf("\nInforme o valor acumulado do cadastro:");
        scanf("%f",&y.valor_acumulado);
        fprintf(FICHA,"\nValor acumulado: %f",y.valor_acumulado);
        
        fprintf(FICHA,"\n------------------\n");
       
       fwrite(&y,sizeof(struct cadastro),1,file2);
       if(ferror(file2))
       {
           printf("Erro na gravacao");
         
       }
       else
       {
            
           printf("Cadastro feito com sucesso!");
       }
     
   }
   fclose(file2);
   fclose(FICHA);
 
}

void case4()
{
   FILE *file2;
   char temp[30];
   float maior_valor=0;
   struct cadastro y;
    
    file2=fopen("ficha_cadastro","rb");
      
      if(file2==NULL)
        {
          printf("Nao existem usuarios cadastrados...\n");
          
        }
      
      else
        {
         while(fread(&y,sizeof(struct cadastro),1,file2)==1)
        {
          if(y.valor_acumulado > maior_valor)
          {
            maior_valor=y.valor_acumulado;  
            strcpy(temp,y.nome);
          }
          
        } 
      
        printf("\nCliente com o maior valor acumulado é o %s é contem o valor de : %.2f R$",temp,maior_valor); 
      } 
     
      fclose(file2);  
}

int validar_data(char data[])
{
    
int dia,mes,ano=0;
int i;

     if((data[2]!='/') || (data[5] != '/'))
    {
        printf("\nA data foi escrita errada,utilize dd/mm/aaaa.");
        return 0;
    }
    
    for(i=0;i<10;i++)
    {
     if(data[i]<47 || data[i]>57)
     {
     printf("\nA data foi escrita errada,utilize dd/mm/aaaa.");
     
     return 0;  
     }
    }
     
    
    dia=((data[0]-48)*10)+(data[1]-48);
    mes=((data[3]-48)*10)+(data[4]-48);
    ano=((data[6]-48)*1000)+((data[7]-48)*100)+((data[8]-48)*10)+(data[9]-48);
  
    
 
 if((mes>12 || mes < 1) && (ano>2030 || ano<1900) )
  {
      printf("\nNumero de mes e de ano invalido.");
      return 0;
  }   
  if((mes>12 || mes < 1))
  {
      printf("\nNumero de mes invalido.");
      return 0;
  }
  
  if(ano>2030 || ano<1900)
  {
      printf("\nAno inválido.");
      return 0;
  }
  

  

    switch (mes)
{
        case 1:
        {    
            if((dia>31 || dia <1))
            {
              printf("\nO mes de janeiro possui no maximo 31 dias."); 
              return 0;  
              
            }
            
            break;
        }    
        case 2:
        {    
            
                    if(ano%4==0 && (dia>29 || dia <1))
                    {
                       printf("\nAno bisiesto possui 29 dias em fevereiro.");
                        return 0;
                    }
                    
                    if(ano%4!=0 && (dia>28 || dia<1))
                    {
                       printf("\nAno nao bisiesto possui 28 dias em fevereiro");
                      return 0;
                    }
                    
           
            break;

        }    
        case 3:
        {    
            if(dia>31 || dia <1)
            {
                 printf("\nO mes de marco possui no maximo 31 dias."); 
              return 0;
            }
            
            break;
        }    
    
       case 4:
        {    
            if(dia>30 || dia <1)
            {
                 printf("\nO mes de abril possui no maximo 30 dias.") ;
              return 0;
            }
            
            break;
        }    
    
      case 5:
       {    
            if((dia>31 || dia <1) )
            {
                 printf("\nO mes de maio possui no maximo 31 dias.");
              return 0;
            }
            
            break;
        }    
       case 6:
        {    
           if((dia>30 || dia <1))
            {
                 printf("\nO mes de junho possui no maximo 30 dias.");
              return 0;
            }
            
            break;
        }    
    
      case 7:
       {    
            if((dia>30 || dia <1))
            {
             printf("\nO mes de julho possui no maximo 30 dias.");
              return 0;
            }
            
            break;
        }  
      case 8:
       {    
            if((dia>31 || dia <1) )
            {
              printf("\nO mes de agosto possui no maximo 31 dias."); 
              return 0;
            }
            
            break;
        }
        
        case 9:
         {    
            if((dia>30 || dia <1) )
            {
                 printf("\nO mes de setembro possui no maximo 30 dias.");
              return 0;
            }
            
            break;
        } 
        
        case 10:
         {    
            if((dia>31 || dia <1) )
            {
                 printf("\nO mes de outubro possui no maximo 31 dias."); 
              return 0;
            }
            
            break;
        }
        case 11:
         {    
            if((dia>30 || dia <1))
            {
              printf("\nO mes de novembro possui no maximo 30 dias.");
              return 0;
            }
            
            break;
        } 
        case 12:
         {    
           if(dia>31 || dia <1) 
            {
             printf("\nO mes de dezembro possui no maximo 31 dias.");
              return 0;
            }
            
            break;
        }    
}
  
  return 1;  
}
int validar_cpf(char cpf[11])
{
FILE *file2; 
struct cadastro y;
int i;
int resto1=0,resto2=0;
int contador=0; 
   
   file2=fopen("ficha_cadastro","rb");
   if(file2==NULL)
   {
       printf("Erro");
   }
   else
   {
      
      while(fread(&y,sizeof(struct cadastro),1,file2)==1)
      {
        y.numero[11]='\0';  
          
        if(strcmp(cpf,y.numero)==0) 
        {
            contador=1;
        }
        
      }
   }

   fclose(file2);
   if(contador==1)
   { 
      printf("CPF ja cadastrado.");
     return 0;
   }
   for(i=0;i<11;i++)
   {
      if(cpf[i]<48 || cpf[i]>57) 
      {
     return 0; 
      }
      if(cpf[i]==cpf[i+1])
      {
        contador++;  
      }
   }
   
   if(contador==10)
   {
       return 0;
   }
   
   
   for(i=0;i<10;i++)
   {
        resto2=((cpf[i]-48)*(11-i))+resto2;
   }
   for(i=0;i<9;i++)
   {
        resto1=((cpf[i]-48)*(10-i))+resto1;
   }
   
  resto1=resto1%11;
  resto2=resto2%11;
   if(resto1 < 2)
	{
		resto1=0;		
	}
	else
	{
		resto1 = (11-resto1);
	}
	if(resto2 < 2)
	{
		resto2=0;		
	}
	else
	{
		resto2 = (11 - resto2);
	}

           if((resto1==(cpf[9]-48)) && (resto2==(cpf[10]-48)))
           {
              return 1;
           }
           else
           {
              
               return 0;
           }
}
    









