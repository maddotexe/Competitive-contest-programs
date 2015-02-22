#include <stdio.h>
#include <stdlib.h>

struct node {
       int x;
       struct node *left;
       struct node *right;
};


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

void inorder(struct node *root, int *t, int *r)
{
     if(root == NULL)
             return;
     inorder(root->left, t,r);
     *(t + (*r)) = root->x;
     (*r)++;
     printf("%d ", root->x);
     inorder(root->right,t,r);
}
int height (struct node *root)
{
    if(root == NULL)
            return 0;
    return(1 + ((height(root->left) > height(root->right)) ? height(root->left) : height(root->right)));
}
int total_nodes(struct node *root)
{
    if(root == NULL)
            return 0;
    return ( 1 + total_nodes(root->left) + total_nodes(root->right));
}
int main()
{
    struct node *root = NULL;
    int n,m, i, c,b[100],*p, *q, h,y=0;
    scanf("%d", &n);
    p = &(b[0]);
    q = &y;
    for(i = 0; i < n; i++)
    {
          scanf("%d", &c);
          make_bst(&root, c);
    }
   
    inorder(root,&b[0], &y);
    printf ("\n");
    for ( i = 0; i < y; i++)
    {
        printf("%d ", *(p+i));
    }
    h = height(root);
    printf("\n%d", h-1);
    h = total_nodes(root);
    printf("\n%d", h);
    getchar();
    getchar();
    return 0;
}
