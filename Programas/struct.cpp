#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node *next;
};

void start(struct node** head,int value)
{
struct node* newnode = (struct node*)malloc(sizeof(struct node));
newnode -> data = value;
newnode -> next = *head;
*head=newnode;

}

int main()
{
    
struct Node* head = NULL;
int choice, value;

    while (choice>1 && choice<4) {
        printf("\nMenu:\n");
        printf("1. Inserir valor no começo da lista\n");
        printf("2. Inserir valor no fim da lista\n");
        printf("3. Mostrar lista\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice)
        {
                case 1:
                    printf("Digite o valor a ser inserido: ");
                    scanf("%d", &value);
                    start(&head, value);
                    printf("Valor inserido no começo da lista com sucesso!\n");
                    break;

        }
    }


return 0;    
}