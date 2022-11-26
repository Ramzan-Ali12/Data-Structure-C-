#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node*prev;
  int data;
  struct node*next;
}*head;//we Declear the pointer "head" type of node.

void createlist(int n);//Declaration of createlist function.
void delete_first();//Declaration of insert first node.
void display();//Declaration of display function.
int main()
{
int n,data,choice;
printf("\nHow many nodes you want to enter in linked list:\n");
scanf("%d",&n);
createlist(n);
printf("\nData in Doubly linked list is:\n");
display();
printf("\n");
printf("\nPress 1 to delete first node of the list\n");
scanf("%d",&choice);
if (choice==1)
{
  delete_first(); 
}
printf("\n");

printf("After Deleting Node at Beginning of the list is\n");

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
//insert first coding 
void delete_first()
{
    struct node*firstnode;
    firstnode=head;
    head=head->next;
    free(firstnode);
    head->prev=NULL;

printf("\nCONGRATS Node Deleted  Successfuly at the Beginning of the list\n");
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




