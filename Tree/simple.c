#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};
 
/* newNode() allocates a new node
with the given data and NULL left
and right pointers. */
struct node* newNode(int x)
{
    int data;
    // Allocate memory for new node
struct node* temp = (struct node*)malloc(sizeof(struct node));
 
    /* printf("\nEnter Root Node : ");  
    scanf("%d", &data); */

    // Assign data to this node
    temp->data = x;
    
    // Initialize left and
    // right children as NULL
    temp->left = NULL;
    temp->right = NULL;
    /* printf("\nEnter the left child of %d\n", data);  
    temp->left =newNode();
    printf("\nEnter the right child of %d", data);  
    temp->right = newNode(); */
    return(temp);
}
//Traversal For pre order
void preorder(struct node *root)
 {
   if (root ==NULL)
   
     return ;
   printf("%d",root->data);
   preorder(root->left);
   preorder(root->right);
   return ;
   
 }
   //Traversal for Post Order
   void postorder(struct node*root)
 {
   if (root == NULL)
   
   return ;
   postorder(root->left);
   postorder(root->right);
   printf("%d",root->data);
return ;
   
 }
    //Traversal for In Order
   void inorder(struct node*root)
 {
   if (root == NULL)
   
   return ;
   inorder(root->left);
   printf("%d",root->data);
   inorder(root->right);
return ;
   
   
 }
int main()
{
       struct node *root;  
       root = newNode(1);
       root->left = newNode(2);
       root->right = newNode(3);  
       root->left->left = newNode(4);
       printf("Pre Order Traversal\n");
       preorder(root);
       printf("\n");
       printf("Inorder Traversal\n");
       inorder(root);
       printf("\n");
       printf("Post Order Traversal\n");
       postorder(root);
       printf("\n");
     /*create root*/
    //struct node* root = newNode(1);
    /* following is the tree after above statement
         1
        / \
      NULL NULL
    */

    //root->left = newNode(2);
    //root->right = newNode(3);
    /* 2 and 3 become left and right children of 1
            1
         /    \
        2      3
      /  \    /  \
   NULL NULL NULL NULL
    */
 
    //root->left->left = newNode(4);
    /* 4 becomes left child of 2
           1
         /    \
        2      3
      /  \    /  \
     4 NULL NULL NULL
    / \
 NULL NULL
    */
 
    return 0;
}