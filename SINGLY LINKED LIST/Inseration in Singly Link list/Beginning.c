#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node*next;
}*head;//we Declear the pointer "head" type of node.

void createlist(int n);//Declaration of createlist function.
void insertfirst(int data);//Declaration of insertfirst function.
void display();//Declaration of display function.
int main()
{
int n,data;
printf("\nHow many nodes you want to enter in linked list:\n");
scanf("%d",&n);
createlist(n);
printf("\nData in singly linked list is:\n");
display();
printf("\n");
printf("\nEnter data to insert at beginning of the list\n");
scanf("%d",&data);
insertfirst(data);
printf("\nAfter adding the Node beginning of the  singly linked list is\n");
display();
printf("\n");
return 0;
}
//Create a singly linked list for n nodes
void createlist(int n)
{
struct node *temp;
struct node *newnode;
int data,i;
head=(struct node*)malloc(sizeof(struct node));


printf("\n enter  data  for node 1:\n");
scanf("%d",&data);

head->data=data;
head->next=NULL;
temp=head;

for(i=2;i<=n;i++)
{
 newnode=(struct node*)malloc(sizeof(struct node));

    printf("\nenter data for node %d: \n",i);
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=NULL;

  temp->next=newnode;
  temp=temp->next;
}
  printf("\nSINGLY LINKED LIST CREATED SUCCESSFULY\n");

}
//insert funtion insert Node at beginning of the list

void insertfirst(int data)
{
struct node*newnode;
newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->next=head;
    head=newnode;
  
printf("\nNode inserted at Beginning of Singly linked list SUCCESSFULLY\n");
}

//Display function trasverse the list

void display()
{
 struct node *temp=head;
if(head==NULL)
{
  printf("list is Empty");
}
else{
	while(temp!=NULL)
	{
	printf("Data= %d \n",temp->data);
	temp=temp->next;
	}
  printf("\nTraversing Completed Successfuly\n");
}
}





