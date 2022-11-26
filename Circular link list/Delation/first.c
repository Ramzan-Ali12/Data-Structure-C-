/**
 * C program to create and traverse Circular Linked List
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Basic structure of Node
 */
struct node {
    int data;
    struct node * next;
}*head;


/*
 * Functions used in this program
 */
void createList(int n);
void displayList();
void deletefirst();
void deletelast();
void delete_any_pos(int pos);


int main()
{
    int n, data, choice=1,pos;

   // head = NULL;

    /*
     * Run forever until user chooses 0
     */
    while(choice != 0)
    {
        printf("============================================\n");
        printf("CIRCULAR LINKED LIST PROGRAM\n");
        printf("============================================\n");
        printf("1. Create List\n");
        printf("2. Display list\n");
        printf("3. Delete Beginning\n");
        printf("4. Delete Last\n");
        printf("5. Delete Any Position\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                displayList();
                break;
            case 3:
                deletefirst();
                break;
            case 4:
                deletelast();
                break;
            case 5:
            printf("\nEnter any position you want to delete\n");
            scanf("%d",&pos);
                delete_any_pos(pos);
                break;
            case 0:
                break;
            default:
                printf("Error! Invalid choice. Please choose between 0-5");
        }

        printf("\n\n\n\n\n");
    }

    return 0;
}


/**
 * Creates a circular linked list of n nodes.
 * @n Number of nodes to be created
 */
void createList(int n)
{
    int i, data;
    struct node *prevNode,*newNode;

    if(n >= 1)
    {
        /*
         * Creates and links the head node
         */
        head = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->next = NULL;

        prevNode = head;

        /*
         * Creates and links rest of the n-1 nodes
         */
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->next = NULL;

            // Link the previous node with newly created node
            prevNode->next = newNode;

            // Move the previous node ahead
            prevNode = newNode;
        }

        // Link the last node with first node
        prevNode->next = head;

        printf("\nCIRCULAR LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

/**
 * Delete first Node of the list
 */
void deletefirst()
{
    struct node *temp,*tail;
    temp=head;
    tail=head;

     if (head->next==head)
    {
        
        free(temp);
        head->next=NULL;
    }
    else
    {
        
    temp=head;
    tail=head;

    while (temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=tail->next;
    head=head->next;
    printf("Element Deleted is %d",tail->data);
    free(tail);
   tail->next=NULL;
   
  

}
}

/**
 * Delete Last Node of the list
 */
void deletelast()
{
struct node*temp,*tail;
    temp=head;
     if (head->next==head)
    {   
        free(head);
        head->next=NULL;
        printf("Element Deleted is %d",head->data);
 
    }
    else
    {
    temp=head;
    while (temp->next!=head)
    {
        tail=temp;
        temp=temp->next;
    }
    tail->next=temp->next;
    
    printf("Element Deleted is %d",temp->data);
    free(temp);
    temp->next=NULL;

    }
}

void delete_any_pos(int pos)
{

struct node*temp,*ptr;
temp=head;
int i=1;
if (pos==1)
{
    deletefirst();
    
}

else
{
temp=head;
while (pos!=i+1)
{
    temp=temp->next;
    i++;
}
ptr=temp->next;
temp->next=ptr->next;
printf("Element Deleted is %d",ptr->data);

free(ptr);
}
}


/**
 * Display the content of the list
 */
void displayList()
{
    struct node *current;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        current = head;
        printf("DATA IN THE LIST:\n");

        do {
            printf("Data %d = %d\n", n, current->data);

            current = current->next;
            n++;
        }
        while(current != head);
    }
}