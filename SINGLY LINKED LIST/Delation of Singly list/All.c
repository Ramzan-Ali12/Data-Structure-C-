/**
 * C program to delete middle node of Singly Linked List
 */

#include <stdio.h>
#include <stdlib.h>


/* Structure of a node */
struct node {
    int data;          // Data 
    struct node *next; // Address 
} *head;


/* Functions used in program */
void createList(int n);
void delete_all_node();
void displayList();


int main()
{
    int n,choice;

    /*
     * Create a singly linked list of n nodes
     */
    printf("\nEnter the total number of nodes you want to Insert:\n");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();
    
    printf("\nPress 1 to Delete all nodes from the  singly linked list:\n");
    scanf("%d", &choice);

   if(choice == 1)
   {
    /* Delete All node from list */
    delete_all_node();
    displayList();
    
   }
else
{
    printf("\nNodes not Deleted\n");
}
    
    printf("\n");

    return 0;
}

/*
 * Create a list of n nodes
 */
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    /*
     * If unable to allocate memory for head node
     */
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        /*
         * Read data of node from the user
         */
        printf("\nEnter the data of node 1:\n");
        scanf("%d", &data);

        head->data = data; // Link the data field with data
        head->next = NULL; // Link the address field to NULL

        temp = head;

        /*
         * Create n nodes and adds to linked list
         */
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            /* If memory is not allocated for newNode */
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("\nEnter the data of node %d:\n ", i);
                scanf("%d", &data);

                newNode->data = data; // Link the data field of newNode with data
                newNode->next = NULL; // Link the address field of newNode with NULL

                temp->next = newNode; // Link previous node i.e. temp to the newNode
                temp = temp->next;
            }
        }

        printf("\n CONGURLATIONS SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
/*
 * Delete middle node of the linked list
 * Difficult Method to delete Middle node from linked list
 */
void delete_all_node()
{

    struct node *temp;

    temp=head;
    while (head!=NULL)
    {
      temp=head;
      head=head->next; 
      /*Deallocate the memory of last node*/
      free(temp);
    }
    
    printf("\nCONGURLATIONS YOU DELATED ALL NODES FROM THE LIST\n");
}

/*
 * Display entire list
 */
void displayList()
{
    struct node *temp;

    /*
     * If the list is empty i.e. head = NULL
     */
     if (head==NULL)
     {
         printf("LIST IS EMPTY");
     }
   else
   {
       
   
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); // Print the data of current node
            temp = temp->next;                 // Move to next node
        }
   }
}

