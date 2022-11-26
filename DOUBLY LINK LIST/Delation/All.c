#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node*prev;
  int data;
  struct node*next;
}*head;//we Declear the pointer "head" type of node.

void createlist(int n);//Declaration of createlist function.
void delete_all();//Declaration of insert first node.
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
printf("\nPress 1 to delete all nodes from the list:\n");
scanf("%d",&choice);
if (choice==1)
{
     delete_all(); 
    printf("\nCongrats you have Deleted Entire Nodes from Doubly link list:");
}
else
{
    printf("\n");
    printf("\nYour Nodes Data Not Deleted Successfuly\n");
    printf(" Nodes Data in Doubly linked list is:\n");
    display();
    
    printf("\n");
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
//insert first coding 
void delete_all()
{
    struct node*temp,*temp2;
    temp=head;
    while (head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);

    }
printf("\nCONGRATS  All NODES Deleted  Successfuly from Doubly linkded list is:\n");
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