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
void deleteMiddleNode(int position);
void displayList();


int main()
{
    int n, position;

    /*
     * Create a singly linked list of n nodes
     */
    printf("\nEnter the total number of nodes you want to enter:\n");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    printf("\nEnter the Node position you want to Delete:\n");
    scanf("%d", &position);

    /* Delete middle node from list */
    deleteMiddleNode(position);

    printf("\nData in the list \n");
    displayList();
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
void deleteMiddleNode(int position)
{
    int i;
    struct node *temp1,*temp2;
    
        temp1 = head;
        temp2 = head;
        //This for loop runs only one time
        for(i=2; i<=position; i++)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }

        if(temp1!= NULL)
        {
            if(temp1 == head)
            
            head = head->next;

            temp2->next = temp1->next;
            
            /* Delete nth node */
            free(temp1);

            printf("\nSUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n");  
        }
        else
        {
            printf("Invalid position unable to delete.");
        }  
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

