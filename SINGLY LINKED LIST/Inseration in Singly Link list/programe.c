//Complete programe to create list and inseration first and last
#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node*next;
}*head;
void createlist(int n);
void insertfirst(int data);
void insert_middle(int data,int pos);
void insertlast(int data);
void display();
int main()
{
int n,data,pos;

printf("\nHow many nodes you want to enter in linked list:\n");
scanf("%d",&n);
createlist(n);
printf("\n Data in singly linked list:\n");
display();
printf("\n Enter  data to insert at beginning of the list:\n");
scanf("%d",&data);
insertfirst(data);
printf("\nData  adding  after first in the list is:\n");
display();
printf("\n");
printf("\n*****************************\n");

printf("\nEnter data to insert at Middle of the list\n");
scanf("%d",&data);
printf("\nEnter position to istert Node\n");
scanf("%d",&pos);
insert_middle(data,pos);
printf("\nAfter inseting the Node Middle of the  sigly linked list is \n");
display();
printf("\n*****************************\n");
printf("\nEnter data to insert at the end of the list is\n");
scanf("%d",&data);
printf("\nAfter adding the data at last in the list is\n");
insertlast(data);
display();
printf("\n");
printf("\n*****************************\n");
 return 0;
}
void createlist(int n)
{
struct node *temp;
struct node *newnode;
int data,i;
head=(struct node*)malloc(sizeof(struct node));
if(head==NULL)
        printf("list is empty");
else
{
	printf("\n enter  data  for node 1:\n");
	scanf("%d",&data);
 head->data=data;
head->next=NULL;
temp=head;
}
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
printf("SINGLY LINKED LIST CREATED SUCCESSFULY\n");
}

void insertfirst(int data)
{
struct node*newnode;
newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=data;
   newnode->next=NULL;
   newnode->next=head;
    head=newnode;
  
printf("\nData inserted successfuly\n");
}

void display()
{
struct node *temp=head;

	while(temp!=NULL)
	{
	printf("Data= %d \n",temp->data);
	temp=temp->next;
	}
}
void insertlast(int data)
{
struct node*temp;
struct node*newnode;

temp=head;
while(temp->next!=NULL)
{
	temp=temp->next;
}

newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=NULL;

temp->next=newnode;
}

//function defination of insert node last in the list
void insert_middle(int data,int pos)
{
    int i;
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

        newNode->data = data; // Link data part
        newNode->next = NULL;

        temp = head;

        /* 
         * Traverse to the n-1 position 
         */
        for(i=2; i<=pos-1; i++)
        {
            temp = temp->next;
        }

        if(temp->next != NULL)
        {
            /* Link address part of new node */
            newNode->next = temp->next; 

            /* Link address part of n-1 node */
            temp->next = newNode;

            printf("NODE INSERTED SUCCESSFULLY\n");
        }
        else
        {
            printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
        }
}




