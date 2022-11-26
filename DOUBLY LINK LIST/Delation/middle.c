//This programe Delete the Node from user defined position
#include<stdio.h>
#include<stdlib.h>
/*
* Structure of a node
*/
struct node
{
  struct node*prev;
  int data;
  struct node*next;
}*head;//we Declear the pointer "head" type of node.

void createlist(int n);//Declaration of createlist function.
void delete_middle(int pos);//Declaration of insert first node.
void display();//Declaration of display function.
int main()
{
int n,pos;
printf("\nHow many nodes you want to enter in linked list:\n");
scanf("%d",&n);
createlist(n);
printf("\nData in Doubly linked list is:\n");
display();
printf("\n");
printf("\nEnter position to Delete Node\n");
scanf("%d",&pos);
delete_middle(pos);
printf("\n");
printf("After Deleting Node from user Defined position of the list is:\n");
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
void delete_middle(int pos)
{
    struct node*temp,*temp2;
    temp=head;
    temp2=head;
    //This line of code to delete 1st Node of the list.
    if (pos==1)
    {
      temp=head;
      head=head->next;
      free(temp);
      head->prev=NULL;
    }
    //This line of code to delete Node if position is Greater then 1.
    while (pos>1)
    {
      temp=temp->next;
      pos--;
    }
    if (temp->next==NULL)
    {
    temp2=temp->prev;
    temp2->next=NULL;
    free(temp);
    }
    else
    {
    temp2=temp->prev;
    temp2->next=temp->next;
    temp->next->prev=temp2;
    free(temp);
    }
  
printf("\nCONGRATS Node Deleted  Successfuly from specified position of the list\n");
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




