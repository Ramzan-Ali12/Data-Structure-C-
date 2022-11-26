    //implementation of circular Queue using Array
    #include <stdio.h>  
      
    # define max 6  
    int queue[max];  // array declaration  
    int front=-1;  
    int rear=-1;  
    // function to insert an element in a circular queue  
    void enqueue(int element)  
    {  
        if (front==(rear+1)%max)
        {
            printf("Queue is overflow..\n");
        }
      else  if(front==-1 && rear==-1)   // condition to check queue is empty  
        {  
            front=0;  
            rear=0;  
            queue[rear]=element;
        }

        else  
        {  
            rear=(rear+1)%max;       // rear is incremented  
            queue[rear]=element;     // assigning a value to the queue at the rear position.  
        }  
    }  
      
    // function to delete the element from the queue  
    void dequeue()  
    {  
        if((front==-1) && (rear==-1))  // condition to check queue is empty  
        {  
            printf("\nQueue is underflow..");  
        }  
     else if(front==rear)  
    {  
       printf("\nThe dequed element is:%d", queue[front]);    
       front=-1;  
       rear=-1;   
    }   
    else  
    {  
       printf("\nThe dequeued element is %d", queue[front]);  
       front=(front+1)%max;  
    }  
    }  
    // function to display the elements of a queue  
    void display()  
    {  
        int i=front;  
        if(front==-1 && rear==-1)  
        {  
            printf("\n Queue is empty..");  
        }  
        else  
        {  
            printf("\nElements in a Queue are:\n");  
            while(i<=rear)  
            {  
                printf("%d", queue[i]); 
                printf("\n"); 
                i=(i+1)%max;  
            }  
        }  
    }  
    int main()  
    {  
        int choice,x;   // variables declaration  
          
        while(1)   // while loop  
        {  
        printf("\n=============================\n");
        printf("\nCircular Queue using Array\n");
        printf("\nPress 1: Insert an element");  
        printf("\nPress 2: Delete an element");  
        printf("\nPress 3: Display the element\n");  
        printf("\n=============================\n");

        printf("\nEnter your choice\n");  
        scanf("%d", &choice);  
          
        switch(choice)  
        {   
            case 1: 
            printf("Enter the element which is to be inserted\n");  
            scanf("%d", &x);  
            enqueue(x);  
            break;  
            case 2:  
            dequeue();  
            break;  
            case 3:  
            display();  
            break;
            default:
            printf("Invalid choice, please input number between (1-3).");
            break;
      
        }
    }  
        return 0;  
    }  