#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *prox;

};

void printList(struct Node* head) 
{
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertNodeAtEnd(struct Node** head, int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } 
		else 
		{
			struct Node* temp = *head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
}

int main()
{
struct Node* head = NULL;
int nome=0,valor=0;
	
    while(nome !=4)
	{
	printf("\nMenu:\n");
	printf("1-Inserir valor no inicio\n");
	printf("2-Mostrar lista\n");
	printf("3-Inserir valor no final\n");
	printf("4-Sair\n");
	printf("Escolha uma opcao:");
	scanf("%d",&nome);

		switch(nome)
		{
			case 1:
			{
			printf("\nSelecione o valor a ser inserido:");
			scanf("%i",&valor);
			insertNodeAtBeginning(&head, valor);
			break;	 
			}
			case 2:
			{
			printf("\nValor mostrado:");
			printList(head);
			break;	 
			}
			case 3:
			{
			printf("\nSelecione o valor a ser inserido:");
			scanf("%i",&valor);
			insertNodeAtEnd(&head, valor);
			break;	 
			}
			
		 }
	}
   return 0; 
   
}