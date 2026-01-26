            // 2026 - 01 - 12
            //Singly Circular Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }
    struct Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

void deleteBegin()
{
    if(head == NULL)
    {
        printf("List is Empty");
        return;
    }
    if(head->next == head)
    {
        printf("Deleted %d \n", head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node* temp=head;
    struct Node* last = head;
    while(last->next != head)
    {
        last = last->next;
    }
    head = head->next;
    last->next=head;
    printf("Deleted %d \n", temp->data);
    free(temp);
}

void display()
{
    if (head==NULL)
    {
        printf("List is Empty. \n");
        return;
    }
    struct Node* temp = head;
    printf("____Circular Linked LIst____ \n");
    do{
        printf("%d ->", temp->data);
        temp = temp->next;
    }while(temp != head);
}

int main()
{
    int choice, value;
    while(1)
    {
        printf("\n______CIRCULAR__LINKED__LIST_MENU_____\n");
        printf("1. Insert at any position \n");
        printf("2.Delete at begining\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);
    
        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                deleteBegin();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);

            default:
                printf("Invalid Choice.");
        
        }
    }
}