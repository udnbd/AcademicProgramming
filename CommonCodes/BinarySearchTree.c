#include<stdio.h>
#include<conio.h>
typedef struct node
{
  struct node *left;
  int data;
  struct node *right;
}node;

node *CreateBST(node *, int);
void Inorder(node *root)
{
  if( root != NULL)
  {
    Inorder(root->left);
    printf(" %d ",root->data);
    Inorder(root->right);
  }
}

void Preorder(node *root)
{
  if( root != NULL)
  {
    printf(" %d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
  }
}

void Postorder(node *root)
{
  if( root != NULL)
  {
    Postorder(root->left);
    Postorder(root->right);
    printf(" %d ",root->data);
  }
}

void main()
{
  node *root=NULL;
  int opn,data,n,i;


  root=NULL;
  printf("\nEnter total number of node in BST : ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("\nEnter the value of %d Node : ",i+1);
    scanf("%d",&data);
    root=CreateBST(root,data);
  }
  printf("\nBST created!!!\n",n);

  printf("\n BST Traversal in inorder : ");
  Inorder(root);
  printf("\n BST Traversal in preorder : ");
  Preorder(root);
  printf("\n BST Traversal in postorder : ");
  Postorder(root);
  getch();
}

node *CreateBST(node *root, int data)
{
  if(root == NULL)
  {
    root=(node *)malloc(sizeof(node));
    root->left= root->right = NULL;
    root->data=data;
    return root;
  }
  else if( data < root->data )
    root->left=CreateBST(root->left,data);
  else if( data > root->data )
    root->right=CreateBST(root->right,data);
  else
    printf(" Duplicate Node !!!");

  return(root);

}
