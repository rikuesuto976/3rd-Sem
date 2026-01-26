        //Singly Linear Linked LIst
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node* next;
    int data;
};
struct Node* head=NULL;
void insertAtPosition(int value, int pos)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    newNode -> data = value;

    if(pos == 1){
        newNode -> next = head;
        head= newNode;
        printf("Inserted %d at position %d \n", value, pos);
        return;
    }
    for(int i=1; i<pos-1 && temp!=NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Invalid Position \n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next=newNode;
    printf("Inserted %d at position %d \n",value, pos);
}

void insertEnd(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head==NULL)
    {   
        head=newNode;
    }
    else{
        struct Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next=newNode;
    }
    printf("Inserted at %d at end \n", value);
}

void deleteEnd()
{
    struct Node* temp=head;
    struct Node* prev=NULL;
    if(head==NULL)
    {
        printf("List is Empty \n");
        return;
    }
    if(head->next == NULL){
        printf("Deleted %d \n", head->data);
        free(head);
        head=NULL;
        return;
    }
    while(temp->next !=NULL)
    {
        prev= temp;
        temp = temp->next;
    }
    prev->next=NULL;
    printf("Deleted %d \n", temp->data);
    free(temp);
}

void display()
{
    struct Node* temp = head;
    if(temp==NULL){
        printf("List is empty \n");
        return;
    }
    printf("\n ____Linked List:____ \n");
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("Null \n");
}

int main()
{
    int choice, value, pos;
    while(1)
    {
        printf("\n______LINKED__LIST_MENU_____\n");
        printf("1. Insert at any position \n");
        printf("2. Insert at end\n");
        printf("3.Delete at end\n");
        printf("4.Display\n");
        printf("5.Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);
    
        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(value, pos);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 3:
                deleteEnd();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);

            default:
                printf("Invalid Choice.");
        
        }
    }
}