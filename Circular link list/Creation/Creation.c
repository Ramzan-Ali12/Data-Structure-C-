//This programe demostrate the circular singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node*next;
}*head;//we Declear the pointer "head" type of node.

void createlist(int n);//Declaration of createlist function.
void display();//Declaration of display function.
int main()
{
int n,data;
printf("\nHow many nodes you want to enter in circular linked list:\n");
scanf("%d",&n);
createlist(n);
printf("\nData in circular singly linked list is:\n");
display();
printf("\n");
printf("\n");
return 0;
}
//Create a singly linked list for n nodes
void createlist(int n)
{
struct node *prevnode;
struct node *newnode;
int data,i;
head=(struct node*)malloc(sizeof(struct node));

printf("\n enter  data  for node 1:\n");
scanf("%d",&data);

head->data=data;
head->next=head;

prevnode=head;
for(i=2;i<=n;i++)
{
 newnode=(struct node*)malloc(sizeof(struct node));

    printf("\nEnter data for node %d: \n",i);
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=NULL;
    
    prevnode->next=newnode;
    prevnode=newnode;
    
    prevnode->next=head;
    
}
  printf("\n Circular SINGLY LINKED LIST CREATED SUCCESSFULY\n");

}


void display()
{
 struct node*temp;
 int n=1;
if(head==NULL)
{
  printf("list is Empty");
}
else{
    temp=head;
    printf("\nData in the list\n");
    do
    {
    printf("Data %d = %d\n", n, temp->data);
    temp=temp->next;
    n++;
    }
	while(temp!=head);
}
  printf("\nTraversing Completed Successfuly\n");
}
