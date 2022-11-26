#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node*next;
}*head;//we Declear the pointer "head" type of node.

void createlist(int n);//Declaration of createlist function.
void delete_First();//Declaration of insertfirst function.
void display();//Declaration of display function.
int main()
{
int n,data,choice;
printf("\nHow many nodes do you want to enter in linked list:\n");
scanf("%d",&n);
createlist(n);
printf("\nData in singly linked list is:\n");
display();
printf("\n");
printf("\nPress 1 to delete first node: ");
    scanf("%d", &choice);

    /* Delete first node from list */
    if(choice == 1)
        delete_First();

    printf("\nData in the list \n");
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

void delete_First()
 {
        struct node*firstnode;
       if(head==NULL)
 {
    printf("List is Already empty.");
 }
  else
    {
        firstnode=head;
        head = head->next;

        printf("\nData deleted = %d\n", firstnode->data);

        /* Clears the memory occupied by first node*/
        free(firstnode);

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
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



