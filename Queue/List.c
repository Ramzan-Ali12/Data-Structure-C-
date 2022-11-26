/*
 * C Program to Implement Queue Data Structure using Linked List
 */
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *next;
};

 struct node*front=NULL;
 struct node*rear=NULL;
 struct node*temp;
int frontelement();
void enq(int data);
void deq();
void empty();
void display();
void queuesize();
 
int count = 0;
 
void main()
{
    int no, ch, e;
    printf("\n");
    printf("=====================================\n\n");
    printf("Queue Implementation usin Linked List\n");
    printf("\n 1 - Enque");
    printf("\n 2 - Deque");
    printf("\n 3 - Front element");
    printf("\n 4 - Empty");
    printf("\n 5 - Exit");
    printf("\n 6 - Display");
    printf("\n 7 - Queue size\n");
    printf("====================================\n");
    while (1)
    {
        printf("\n Enter Your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Insert the element in the Queue :");
            scanf("%d", &no);
            enq(no);
            break;
        case 2:
            deq();
            break;
        case 3:
            e = frontelement();
            if (e != 0)
                printf("Front element : %d", e);
            else
                printf("\n No front element in Queue as queue is empty");
            break;
        case 4:
            empty();
            break;
        case 5:
            exit(0);
        case 6:
            display();
            break;
        case 7:
            queuesize();
            break;
        default:
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}
 

void queuesize()
{
    printf("\n Queue size : %d", count);
}
 
/* Enqueing the queue */
void enq(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(sizeof(struct node));
        rear->next = NULL;
        rear->data = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(sizeof(struct node));
        rear->next= temp;
        temp->data = data;
        temp->next = NULL;
        rear = temp;
    }
    count++;
}
 
/* Displaying the queue elements */
void display()
{
    temp = front;
 
    if ((temp == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
    }
    while (temp!=NULL)
    {
       printf("%d ", temp->data);
        printf("\n");
        temp = temp->next; 
    }
}
 
/* Dequeing the queue */
void deq()
{
    temp = front;
    if (temp == NULL)
    {
        printf("\n Underflow");
        
    }
    else
        if (temp->next != NULL)
        {
            temp = temp->next;
            printf("\n Element Deleted from Queue is : %d", front->data);
            free(front);
            front = temp;
        }
        else
        {
            printf("\n Delete Element from  Queue is : %d", front->data);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}
 
/* Returns the front element of queue */
int frontelement()
{
    if ((front != NULL) && (rear != NULL))
        return(front->data);
    else
        return 0;
}
 
/* Display if queue is empty or not */
void empty()
{
     if ((front == NULL) && (rear == NULL))
        printf("\n Queue empty");
    else
       printf("Queue not empty");
}