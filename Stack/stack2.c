/**
 * Stack implementation using linked list in C language.
 */

#include <stdio.h>
#include <stdlib.h>
// Define stack node structure
struct stack 
{
    int data;
    struct stack *next;
} *top;

/* Function declaration to perform push and pop on stack */
void push(int element);
int  pop();
void display();
void topfun();


int main()
{
    int choice, data;

    while(1)
    {
        /* Menu */
        printf("------------------------------------\n");
        printf("    STACK IMPLEMENTATION PROGRAM    \n");
        printf("------------------------------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Show Top Most Element\n");
        printf("5. Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice) 
        {
            case 1: 
                printf("Enter data to push into stack: ");
                scanf("%d", &data);
                
                // Push element to stack
                push(data);
                break;
            case 2: 
                data = pop();
                // If stack is not empty
                if (data !=-1)
                  printf("Data => %d\n", data);
                break;
            case 3: 
               display();
                break;
            case 4:
               topfun();
               break;
            case 5: 
                printf("Exiting from app.\n");
                exit(0);
                break;

            default: 
                printf("Invalid choice, please try again.\n");
        }

        printf("\n\n");
    }
    return 0;
}
/**
 * Functiont to push a new element in stack.
 */
void push(int element)
{
    int data;
    // Create a new node and push to stack
    struct stack * newNode = (struct stack *) malloc(sizeof(struct stack));
    // Check stack overflow
    if (top==NULL)
    {
        newNode->data=element;
        newNode->next = NULL;
        top=newNode;
    }
    else
    {  
    
    // Assign data to new node in stack
    newNode->data = element;
    // Next element after new node should be current top element
    newNode->next = top;
    // Make sure new node is always at top
    top = newNode;
    printf("Data pushed to stack.\n");
    }
}

/**
 * Function to pop element from top of stack.
 */
int pop()
{
    int data = 0;
    struct stack * topNode; 
    // Check stack underflow
    if (top==NULL)
    {
        printf("Stack is empty Underflow.\n");
    }
    else
    {
    // Copy reference of stack top to some temp variable
    // Since we need to delete current stack top and make
    // Stack top its next element
    topNode = top;
    // Copy data from stack's top element
    data = top->data;

    // Move top to its next element
    top = top->next;

    // Delete the previous top most stack element from memory
    free(topNode);
   
   return data;
    }
}
void display()  
{  
     
    struct stack *ptr;  
    ptr=top;  
    if(ptr == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {  
        printf("Printing Stack elements \n");  
        while(ptr!=NULL)  
        {  
            printf("%d\n",ptr->data);  
            ptr = ptr->next;  
        }  
    }  
}  
void topfun()
{

    if (top==NULL)
    {
        printf("\n Stack is empty\n");
    }
    else
    {
        printf("Element at the top is\n");
        printf("%d\n",top->data);
    }
}