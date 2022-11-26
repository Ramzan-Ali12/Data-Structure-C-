#include <stdlib.h>
#include<stdio.h>    
struct Node {  
    int data;  
   struct Node *left;  
   struct Node *right;  
};  
struct Node* create(int data)  
{  
   // int new Node;
 struct node*temp;

}  
struct Node* insertion(struct Node* root, int item) /*Insert a node*/  
{  
    if (root == NULL)  
    return create(item); /*return new node if tree is empty*/  
    if (item < root->data)  
        root->left = insertion(root->left, item);  
    else  
        root->right = insertion(root->right, item);  
    return root;  
}  
struct Node *search(struct Node *root,int data)  
{  
   if (root==NULL)
   return (NULL);
   if (data<root->data)
   return (search(root->left,data));
   else if (data>root->data)
   return(search(root->right,data));
   return(root);
   
}  
struct Node * Delete(struct Node *root,int data)
{
struct Node *temp;
if (root==NULL)

    printf("No such elemets exists");
else if (data<root->data)
{
    root->left=Delete(root->left,root->data);
}
else if (data>root->data)
{
    root->right=Delete(root->right,root->data);
}
else
{
    // Delete Node If Root have NO childern
 if (root->left==NULL && root->right==NULL)
 {
    free(root);
    return(NULL);
 }
  //Delete Node if Root have one childern
 else if (root->left==NULL || root->right==NULL)
 {
     struct Node *temp;
     if (root->left==NULL)

         temp=root->right;
     else
     temp=root->left;
    free(root);
    return(temp);
 }
 else
 {
 //Delete Node if Root have TWO are more childern
 struct Node *temp; 
 temp=FindMax(root->left);
             root->data = temp->data;
root->left=Delete(root->left,temp->data);

 }

}
}
struct Node * FindMax(struct Node*root)
{
 if(root == NULL)
     return NULL;
else if(root->left != NULL) // node with minimum value will have no right child
    return FindMax(root->left); // left most element will be minimum

    return root;

}
//Traversal of Preorder
void preorder(struct node *root)
{
    if(root!=NULL) // checking if the root is not null
    {
        printf(" %d ", root->data); // printing data at root
        preorder(root->left); // visiting left child
        preorder(root->right);// visiting right child
    }
}
//Traversal of inorder
void inorder(struct node *root)
{
    if(root!=NULL) // checking if the root is not null
    {
        inorder(root->left); // visiting left child
        printf(" %d ", root->data); // printing data at root
        inorder(root->right);// visiting right child
    }
}
//Traveral of postorder
void postorder(struct node *root)
{
    if(root!=NULL) // checking if the root is not null
    {
        postrder(root->left); // visiting left child
        postorder(root->right);// visiting right child
        printf(" %d ", root->data); // printing data at root

    }
}
int main()
{
    /*
                   20
                 /    \
                /      \
               5       30
             /   \     /\
            /     \   /  \
           1      15 25  40
                /          \
               /            \
              9             45
            /   \          /
           /     \        /
          7      12      42
    */
    struct node *root;
    root = new_node(20);
    insert(root,5);
    insert(root,1);
    insert(root,15);
    insert(root,9);
    insert(root,7);
    insert(root,12);
    insert(root,30);
    insert(root,25);
    insert(root,40);
    insert(root, 45);
    insert(root, 42);

    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");


    root = delete(root, 1);
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25   40
                /           \
               /             \
              9              45
            /   \           /
           /     \         /
          7      12       42
    */

    root = delete(root, 40);
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25  45
                 /       / 
                /       /   
               9       42    
             /   \          
            /     \        
           7      12      
    */

    root = delete(root, 45);
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25  42
                 /          
                /            
               9            
             /   \          
            /     \        
           7      12      
    */
    root = delete(root, 9);
    inorder(root);
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25  42
                 /          
                /            
               12            
             /             
            /             
           7            
    */
    printf("\n");

    return 0;
}