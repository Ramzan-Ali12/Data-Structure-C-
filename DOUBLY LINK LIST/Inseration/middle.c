#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node*prev;
  int data;
  struct node*next;
}*head;//we Declear the pointer "head" type of node.

void createlist(int n);//Declaration of createlist function.
void insert_first(int data);
void insert_last(int data);
void insertAtN(int pos,int data);//Declaration of insert first node.
void display();//Declaration of display function.
int main()
{
int n,data,choice,pos;
/*
     * Run forever until user chooses 0
     */
    while(choice != 0)
    {
        /*
         * Menu creation to use the program
         */
        printf("============================================\n");
        printf("DOUBLY LINKED LIST PROGRAM\n");
        printf("============================================\n");
        printf("1. Create List\n");
        printf("2. Insert node - at beginning\n");
        printf("3. Insert node - at end\n");
        printf("4. Insert node - at N\n");
        printf("5. Display list\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);

        /*
         * Choose from different menu operation
         */
        switch(choice)
        {
            case 1:
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);

                createlist(n);
                break;
            case 2:
                printf("Enter data of first node : ");
                scanf("%d", &data);

                insert_first(data);
                break;
            case 3:
                printf("Enter data of last node : ");
                scanf("%d", &data);

                insert_last(data);
                break;
            case 4:
                printf("Enter the position where you want to insert new node: ");
                scanf("%d", &pos);
                printf("Enter data of %d node : ", pos);
                scanf("%d", &data);

                insertAtN(data, pos);
                break;
            case 5:
                display();
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
//Create a singly linked list for n nodes
void createlist(int n)
{
struct node*temp,*newnode;

int data,i;
head=(struct node*)malloc(sizeof(struct node));

printf("\nEnter  data  for node 1:\n");
scanf("%d",&data);
head->prev=NULL;
head->data=data;
head->next=NULL;
temp=head;
for(i=2;i<=n;i++)
{
 newnode=(struct node*)malloc(sizeof(struct node));

    printf("\nEnter data for node %d: \n",i);
    scanf("%d",&data);
    newnode->prev=NULL;
    newnode->data=data;
    newnode->next=NULL;

    temp->next=newnode;
    newnode->prev=temp;
    temp=newnode;
}
  printf("\nDoubly LINKED LIST CREATED SUCCESSFULY\n");
  printf("\n");

}
//insert middle or any position coding 
void insertAtN(int pos,int data)
{
    struct node*newnode,*temp;
    int i;
    temp=head;
newnode=(struct node*)malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->data=data;
    newnode->next=NULL;
    
    if(pos==1)
    {
      insert_first(data);
    }
    else if (temp->next==NULL)
    {
      insert_last(data);
    }
    
        else if (temp->next != NULL)
        {
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        if (temp->next!=NULL)//checks the condition  if(prev->next==NULL) then 
        temp->next->prev=newnode;
        temp->next=newnode;
        
        }
        else
        {
          printf("\nunable to insert node\n");
        }
printf("\nCONGRATS Node inserted  Successfuly at the Specified position of the list \n");
}

//Display function trasverse the list

void display()
{
 struct node *temp=head;

	while(temp!=NULL)
	{
	printf("Data= %d \n",temp->data);
	temp=temp->next;
	}
  printf("\nTraversing Completed Successfuly\n");
}
void insert_first(int data)
{
    struct node*newnode;
    
newnode=(struct node*)malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->data=data;
    newnode->next=NULL;

    head->prev=newnode;
    newnode->next=head;
    head=newnode;

printf("\nCONGRATS Node inserted  Successfuly at the Beginning of the list \n");
}
//insert last coding 
void insert_last(int data)
{
    struct node*newnode,*temp;
    temp=head;
newnode=(struct node*)malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->data=data;
    newnode->next=NULL;
    while (temp->next !=NULL)
    {
        temp=temp->next;
    }
    if (temp->next==NULL)
    {
        //this is the code to insert node at last of list
        temp->next=newnode;
        newnode->prev=temp;
    }
    else
    {
        printf("\nUnable to insert Node at last of the list\n");
    }
    

printf("\nCONGRATS Node inserted  Successfuly at the last of the list \n");
}

