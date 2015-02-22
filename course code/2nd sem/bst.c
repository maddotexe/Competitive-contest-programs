#include <stdio.h>
#include <stdlib.h>

struct node {
       int x;
       struct node *left;
       struct node *right;
};

void del(struct node ** head)
{
     int c,k=0;
     cin >> c;
     if((*head) == NULL) {
                return ;
     }
     else {
          while((*head)->x != c) {
                           if(((*head)->x > c) {
                               if(((*head)->left)->x == c) {
                                    k =1;
                                    break;
                               }
                               else {
                                    (*head)=(*head)->left;
                               }
                           else
                           {
                               if(((*head)->right)->x == c) {
                                    k =2;
                                    break;
                               }
                               else {
                                    (*head)=(*head)->right;
                               }
                           }
          }
          if(k==1)
          {
                  if((*head)->left->left==NULL && (*head)->left->right == NULL)
                                               (*head)->left = NULL;
                  }
                  else if((*head)->left->left != NULL && (*head)->left->right == NULL)
                  {
                       (*head)->left = (*head)->left->left;
                  }
                  else if ( (*head)->left->right != NULL && (*head)->left-left == NULL)
                  {
                       (*head)->left = (*head)->left->right;
                  }
                                    
     
void make_bst(struct node **head, int c)
{
                if((*head) == NULL)
                {
                           
                           (*head) = (struct node *)malloc(sizeof(struct node ));
                           (*head)->x = c;
                           (*head)->left = NULL;
                           (*head)->right = NULL;
                           return;
                }
                if((*head)->x > c)
                           make_bst(&((*head)->left), c);
                else
                    make_bst(&((*head)->right), c);
}

void inorder(struct node *root)
{
     if(root == NULL)
             return;
     inorder(root->left);
     printf("%d ", root->x);
     inorder(root->right);
}

int main()
{
    struct node *root = NULL;
    int n, i, c;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
          scanf("%d", &c);
          make_bst(&root, c);
    }
    inorder(root);
    del(&root);
    getchar();
    getchar();
    return 0;
}
          
    
