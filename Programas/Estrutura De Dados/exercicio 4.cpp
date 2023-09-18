//4.	Qual a diferença entre Passar Parâmetros para uma função por referência e por valor? Apresente exemplos (pode fazer um código e explicar nos comentários do código).
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>

// Função que recebe um valor por valor
void valor(int x) 
{
    x = 20; // A mudança aqui não afetará a variável original


}

// Função que recebe um ponteiro por referência
void referencia(int *x) 
{
    *x = 20; // A mudança aqui afetará a variável original
}

int main()
{
    int num1 = 10;
    int num2 = 10;

    printf("Valores originais: num1 = %d, num2 = %d\n", num1, num2);

    valor(num1);
    referencia(&num2);

    printf("Valores apos as funcoes: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}