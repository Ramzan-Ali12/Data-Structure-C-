#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node*next;
}*head;//we Declear the pointer "head" type of node.
void display();//Declaration of display function.
void createlist(int n);//Declaration of createlist function.
void insert_middle(int data,int pos);//Declaration of insertlast functiom
int main()
{
int n,data,pos;
printf("\nHow many nodes you want to enter in linked list:\n");
scanf("%d",&n);
createlist(n);
printf("\nData in singly linked list is:\n");
display();
printf("\n");
printf("\nEnter position to istert Node\n");
scanf("%d",&pos);

printf("\nEnter data to insert at Middle of the list\n");
scanf("%d",&data);
insert_middle(data,pos);
printf("\nAfter inseting the Node Middle of the  sigly linked list is \n");
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

            if(temp == NULL)
                break;
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

//function defination of Traverse List
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