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
void search(int data);//Declaration of insert first node.
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
printf("\nEnter  Data to search Node\n");
scanf("%d",&data);
search(data);
printf("\n");
printf("After Searching the Node from the list is:\n");
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
//Search  Node coding
void search(int data)
{
    struct node*temp;
    temp=head;
    if (temp==NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
       temp=head;
       while (temp!=NULL)
       {
           if (temp->data==data)
           {
               printf("\n Data is search successfuly\n");
            
               temp=temp->next;
           }
       } 
       printf("\nUnable to search Data from the list\n");
    }
    
  
printf("\nCONGRATS Node is Search Successfuly in the list\n");
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