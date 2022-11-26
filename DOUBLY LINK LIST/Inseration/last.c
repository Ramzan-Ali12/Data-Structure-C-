#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node*prev;
  int data;
  struct node*next;
}*head;//we Declear the pointer "head" type of node.

void createlist(int n);//Declaration of createlist function.
void insert_last(int data);//Declaration of insert first node.
void display();//Declaration of display function.
int main()
{
int n,data;
printf("\nHow many nodes you want to enter in linked list:\n");
scanf("%d",&n);
createlist(n);
printf("\nData in Doubly linked list is:\n");
display();
printf("\n");
printf("\nEnter Data to insert Node at last of the list\n");
scanf("%d",&data);
insert_last(data);
printf("\n");

printf("After Adding the Node at last of Doubly linked list is\n");

display();
printf("\n");
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





