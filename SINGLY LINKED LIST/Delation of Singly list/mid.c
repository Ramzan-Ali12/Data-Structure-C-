#include<stdio.h>
#include<stdlib.h>

/* Structure of a node */
struct node {
    int data;          // Data 
    struct node *next; // Address 
} *head;


/* Functions used in program */
void createList(int n);
void deleteMiddleNode(struct node**head,int position);
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

    printf("\nEnter the node position you want to delete:\n");
    scanf("%d", &position);

    /* Delete middle node from list */
    deleteMiddleNode(&head,position);

    printf("\nData in the list \n");
    displayList();
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
                printf("\nEnter the data of node %d:\n", i);
                scanf("%d", &data);

                newNode->data = data; // Link the data field of newNode with data
                newNode->next = NULL; // Link the address field of newNode with NULL

                temp->next = newNode; // Link previous node i.e. temp to the newNode
                temp = temp->next;
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
//Easy way to Delete middle node from list
//Neso Acadmy function 
void deleteMiddleNode(struct node**head,int position)
{
struct node*todelete,*temp;
    todelete=*head;
    temp=*head;
if(*head==NULL)
    printf("\nList is Already Empty\n");
else if (position==1)
{
    *head=todelete->next;
    free(todelete);
    todelete=NULL;
}
else
{
    while(position !=1)
    {
        temp=todelete;
        todelete=todelete->next;
        position--;

    }
    temp->next=todelete->next;
    free(todelete);
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

