#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node*prev;
  int data;
  struct node*next;
}*head;//we Declear the pointer "head" type of node.

void createlist(int n);//Declaration of createlist function.
void insert_first(int data);//Declaration of insert first node.
void insert_last(int data);
void insert_any(int data,int pos);
void delete_first();
void delete_last();
void display();//Declaration of display function.
int main()
{
int n,data,pos,choice;
printf("\nHow many nodes you want to enter in Circular Doubly linked list:\n");
scanf("%d",&n);
createlist(n);
printf("\nData in  Circular Doubly linked list is:\n");
display();
printf("\n");
printf("\nEnter Data to insert Node at Beginning of the list\n");
scanf("%d",&data);
insert_first(data);
printf("After Adding Node at Beginning of the list is\n");
display();
printf("\n");
printf("\nEnter Data to insert Node at Last of the list\n");
scanf("%d",&data);
insert_last(data);
printf("After Adding Node at Last of the list is\n");
display();
printf("\n");
printf("\nEnter any position you want to insert the Node\n");
scanf("%d",&choice);
printf("\nEnter Data to insert Node at any Position of the list\n");
scanf("%d",&data);
insert_any(data,choice);
printf("\nAfter adding the Node in Circular Linked list is\n");
display();
printf("\nPress 1 to Delete First Node\n");
scanf("%d",&pos);
if (pos==1)
{
    delete_first();
}
printf("\nAfter Delating the first Node from the Circular  Doubly linked list is\n");
display();

printf("\npress 2 to Delete Last Node\n");
scanf("%d",&pos);
if(pos==2)
{
delete_last();
}
printf("\nAfter Delating the Last Node from the Circular  Doubly linked list is\n");
display();
printf("\n");
return 0;
}
//Create a Circular Doubly linked list for n nodes
void createlist(int n)
{
struct node*temp,*newnode;

int data,i;
head=(struct node*)malloc(sizeof(struct node));

printf("\nEnter  data  for node 1:\n");
scanf("%d",&data);
head->prev=head;
head->data=data;
head->next=head;
temp=head;
for(i=2;i<=n;i++)
{
 newnode=(struct node*)malloc(sizeof(struct node));

    printf("\nEnter data for node %d: \n",i);
    scanf("%d",&data);
    newnode->prev=NULL;
    newnode->data=data;
    newnode->next=NULL;

    temp->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=head;
    temp=newnode;
}
  printf("\n Circular Doubly LINKED LIST CREATED SUCCESSFULY\n");
  printf("\n");

}
//insert first coding 
void insert_first(int data)
{
    struct node*newnode,*temp;
    temp=head;
newnode=(struct node*)malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->data=data;
    newnode->next=NULL;

    
    while (temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
printf("\nCONGRATS Node inserted  Successfuly at the Beginning of the list \n");
}

void insert_last(int data)
{
struct node*newnode,*temp;
    temp=head;
newnode=(struct node*)malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->data=data;
    newnode->next=NULL;

    
    while (temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    head->prev=newnode;
    newnode->next=head;
printf("\nCONGRATS Node inserted  Successfuly at the Last of the list \n");
}
void insert_any(int data,int choice)
{
 struct node*newnode,*temp;
    temp=head;
    if (choice==1)
    {
        insert_first(data);
    }
    else
    {
        temp=head;
        while ( choice > 1)
        {
            temp=temp->next;
            choice--;
        }
    
    newnode=(struct node*)malloc(sizeof(struct node));
    //newnode->prev=NULL;
    newnode->data=data;
    //newnode->next=NULL;
   
   newnode->prev=temp;
   newnode->next=temp->next;
   temp->next->prev=newnode;
   temp->next=newnode;
   printf("\nCONGRATS Node inserted  Successfuly  of the list \n");
    }
}
void delete_first()
{
struct node*temp;
   temp=head;
   if (head->next==head)
   {
       head->next=NULL;
       free(head);
   }
   while (temp->next!=head)
   {
       temp=temp->next;
   }
   temp->next=head->next;
   head->next->prev=temp;
   free(head);
   head=temp->next;

   printf("\nNode Delated Successfuly in the Beginning of the list\n");
}

void delete_last()
{
struct node*temp;
   temp=head;
   if (head->next==head)
   {
       head->next=NULL;
       free(head);
   }
   else
   {
     temp=head; 
   while (temp->next!=head)
   {
       temp=temp->next;
   }
   temp->prev->next=head;
   head->prev=temp->prev;
   free(temp);
   
   printf("\nNode Delated Successfuly in the Beginning of the list\n");
   }
}

//Display function trasverse the list

void display()
{
    struct node *temp;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DATA IN THE LIST:\n");

        do {
            printf("Data %d = %d\n", n, temp->data);

            temp = temp->next;
            n++;
        }
        while(temp!= head);
    }
}


