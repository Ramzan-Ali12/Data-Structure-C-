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
void delete_last_node();
void displayList();


int main()
{
    int n,choice;

    /*
     * Create a singly linked list of n nodes
     */
    printf("\nEnter the total number of nodes you want to enter:\n");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    printf("\nPress 1 to Delete Last Node from the list:\n");
    scanf("%d", &choice);

    
    if(choice == 1)
    {
 /* Delete Last node from list */
    delete_last_node();
    printf("\n Congrats you deleted the Last Node from the List \n");
    printf("\n After Delating the Last Node from the list is \n");
    printf("\n Data in the list is \n");
    displayList();
     
    }
    else
    {
        printf("\n Invalid Entry Unable to Delete  last Node from the list\n");
        printf("\nData in the list \n");
        displayList();
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

        printf("\nSINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
/*
 * Delete middle node of the linked list
 * Difficult Method to delete Middle node from linked list
 */
void delete_last_node()
{

    struct node *temp1,*temp2;

    temp1=head;
    while (temp1->next!=NULL)
    {
      temp2=temp1;
      temp1=temp1->next; 
    }
    temp2->next=NULL;
    /*Deallocate the memory of last node*/
    printf("\nData Deleted= %d\n",temp1->data);
    free(temp1);
    
    //printf("\nSUCCESSFULY DELATED LAST NODE FROM THE LIST\n");
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
   
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); // Print the data of current node
            temp = temp->next;                 // Move to next node
        }
    
}

