//To implement binary search tree using Linked List

#include<stdio.h>
#include<stdlib.h>
///////////////////////////////////////////////////////////////////////////////////
struct Node{
int data;
struct Node* left;
struct Node* right;
};

struct Node* InsertTree(struct Node*,int);
void InorderTraversal(struct Node*);
void PreorderTraversal(struct Node*);
void PostorderTraversal(struct Node*);
struct Node* search(struct Node* ,int);
int left(struct Node*,int);
int right(struct Node*,int);
int FindMin(struct Node*);
int FindMax(struct Node*);
struct Node* deletenode(struct Node*,int);
struct Node* inordersuccessor(struct Node*);
////////////////////////////////////////////////////////////////////////////////////

int main()
{  struct Node* pos=NULL;
   int num;
   int result;
   printf("Implementation of binary tree using linked list");
   struct Node* root=(struct Node*)malloc(sizeof(struct Node));
   root->left=NULL;
   root->right=NULL;
   root->data=1;
   root=InsertTree(root,5);
   root=InsertTree(root,21);
   root=InsertTree(root,7);
   root=InsertTree(root,8);
   root=InsertTree(root,2);
   root=InsertTree(root,3);
   root=InsertTree(root,99);
   printf("\nMenu::\n1.PreorderTraversal\n2.PostorderTraversal\n3.InorderTraversal\n4.search\n5.FindMin\n6.FindMax\n7.Deletenode\n8..Left Node\n9.Right Node");
   int choice=1;
   do{
     int ch;
     printf("\nEnter your choice number::\n");
     scanf("%d",&ch);
     switch(ch)
     {
       case 1:printf("\n\nPreorder TRaversal\n");
              PreorderTraversal(root);
              break;
       case 2:printf("\n\nPostorder TRaversal\n");
              PostorderTraversal(root);
              break;
       case 3:printf("\n\nInorder TRaversal\n");
              InorderTraversal(root);
              break;
       case 4:printf("\nEnter the value to be searched");
              scanf("%d",&num);
              pos=search(root,num);
              if(pos!=NULL)
              printf("Element found");
              else
              printf("ELemnt not found");
              break;
       case 5:result=FindMin(root);
              printf("The minimum element is %d",result);
              break;
       case 6:result=FindMax(root);
              printf("The maximum element is %d",result);
              break;
       case 7:printf("Enter the element to be deleted");
              scanf("%d",&num);
              deletenode(root,num);
              break;
       case 8:printf("Enter the node whose left child you want:");
              scanf("%d",&num);
              result=left(root,num);
              printf("The left  element is %d",result);
              break;
       case 9:printf("Enter the node whose right child you want:");
              scanf("%d",&num);
              result=right(root,num);
              printf("The right element is %d",result);
              break;
       default:printf("\nPls choose a valid option");
               break;
             
     }
  
   
  }while(choice!=0);
   

}
//////////////////////////////////////////////////////////////////////////
//Creates a new node
struct Node* newnode(int value)
{
   struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
   temp->left=NULL;
   temp->right=NULL;
   temp->data=value;
   return temp;
}
//////////////////////////////////////////////////////////////////////////
//Inserts a node in the tree
struct Node* InsertTree(struct Node* root,int value)
{
  if(root==NULL)
	{
	  return(newnode(value));}
    if(root->data>value)
	  root->left=InsertTree(root->left,value);
    else if(root->data<value)
	  root->right=InsertTree(root->right,value);
    else
      printf("Error!!Duplicate ELemnets are not allowed in BST");

    return root;
}
//////////////////////////////////////////////////////////////////////////
//Inorder tree Traversal(Left-Root-Right)
void InorderTraversal(struct Node* root)
{
 if(root!=NULL)
  {
    InorderTraversal(root->left);
    printf("  %d",root->data);
    InorderTraversal(root->right);}

}
//////////////////////////////////////////////////////////////////////////
//Preorder tree Traversal(Root-Left-Right)
void PreorderTraversal(struct Node* root)
{
  if(root!=NULL)
	{
    printf("  %d",root->data);
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
  }
  
}
//////////////////////////////////////////////////////////////////////////
//Postorder tree Traversal(Left-Right-Root)
void PostorderTraversal(struct Node* root)
{
    if(root!=NULL){
      PostorderTraversal(root->left);
      PostorderTraversal(root->right);
      printf("  %d",root->data);
      }

}
//////////////////////////////////////////////////////////////////////////
//Function to search an element in the BST
struct Node* search(struct Node* temp,int value)
{
while(temp!=NULL)
{
 if(temp->data==value)
   return temp ;

if(value>temp->data)
    return (search(temp->right,value));
else if(value<temp->data)
    return (search(temp->left,value));
}
return NULL;
}
//////////////////////////////////////////////////////////////////////////
//Returns the value stored in the left child of the node passed.
int left(struct Node* root,int key)
	{
	  struct Node* pos=search(root,key);
    
    if(pos!=NULL)
      	 {
      	   if(pos->left!=NULL)
      	          return pos->left->data;
           else 
                  printf("THe left child is empty");
	        }
     else
     	 printf("The Element is not found"); 
	}
//////////////////////////////////////////////////////////////////////////
//Returns the value stored in the right child of the node passed.
int right(struct Node* root,int key)
	{
   	struct Node* pos=search(root,key);
        
	  if(pos!=NULL)
      	 {
	        if(pos->right!=NULL)
	            return pos->right->data;
	          
          else 
              printf("THe right child is empty");
	        }
 else
     	printf("The Element is not found"); 
	}
//////////////////////////////////////////////////////////////////////////
//Prints the leftmost leafnode
int FindMin(struct Node* root)
{
  if(root->left==NULL)
	return root->data;
  return FindMin(root->left);
}
//////////////////////////////////////////////////////////////////////////
////Prints the rightmost leafnode
int FindMax(struct Node* root)
{if(root->right==NULL)
	return root->data;
  return FindMax(root->right);
}
//////////////////////////////////////////////////////////////////////////
//Deletes an element from the Binary Search Tree
struct Node* deletenode(struct Node* root,int key)
{ if(root==NULL)return root;
 else if(key<root->data)
	root->left=deletenode(root->left,key);
 else if(key>root->data)
	root->right=deletenode(root->right,key);
 else
    {
	if(root->right==NULL)
		 {struct Node* temp=root->left;
		 free(root);
		 return temp;}
	else if(root->left==NULL)
		 {struct Node* temp=root->right;
		 free(root);
		 return temp;}
     

struct Node* temp=inordersuccessor(root->right);
root->data=temp->data;
root->right = deletenode(root->right, temp->data);
}
return root;
}
//////////////////////////////////////////////////////////////////////////
//Returns the inorder sucessor of a given node
struct Node* inordersuccessor(struct Node* temp)
{if(temp==NULL)
	return NULL;
 while(temp!=NULL)
	temp=temp->left;
return temp;
}
