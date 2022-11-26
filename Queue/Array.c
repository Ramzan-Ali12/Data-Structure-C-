// Queue using Array Implementation. 
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 100

/**
 * Global queue declaration.
 */
int queue[CAPACITY];
int front=-1;
int rear=-1;
//Function Declarations
void  Inseration(int data);
void Delation();
void display();

int main()
{
    int ch, data,g; 
    /* Run indefinitely until user manually terminates */
    while (1)
    {
        /* Queue menu */
        printf("--------------------------------------\n");
        printf("QUEUE Using ARRAY IMPLEMENTATION PROGRAM\n");
        printf("--------------------------------------\n");
        printf("1. INSERATION\n");
        printf("2. DELATION\n");
        printf("3. DISPLAY\n");
        printf("0. Exit\n");
        printf("--------------------------------------\n");
        printf("\n");
        printf("--------------------------------------\n");

        printf("Select an option: ");
        scanf("%d", &ch);

        /* Menu control switch */
        switch (ch)
        {
            case 1:
                printf("\nEnter data to enqueue: ");
                scanf("%d", &data);
                 
                Inseration(data);           
                break;

            case 2:
           Delation();
                break;
            case 3:
               display();
               break;
            case 0:
                printf("Exiting from app.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice, please input number between (0-2).");
                break;
        }

        printf("\n\n");
    }
}

void Inseration(int data)
{
    //In Queue Inseration is always Done on rear.
    
     if (rear == CAPACITY - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        /*If queue is initially empty */
        front = 0;
        rear = rear + 1;
        queue[rear] = data;
    }
    printf("Element Added to the Queue\n");

}
void  Delation()
{
    //Delation is  always Done on front.
   if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
    }
    else
    {
       
        printf("Element deleted from Queue is Data=>: %d\n", queue[front]);
        front = front + 1;
    }
    
}
void display()  
{  
    int i;  
    if(front == -1)  
    {  
        printf("\nEmpty Queue\n");  
    }  
    else   
     {   printf("\nprinting values .....\n");  
        for(i=front;i<=rear;i++)  
        {
            printf("\n%d\n",queue[i]);  
        }
    }  
}  