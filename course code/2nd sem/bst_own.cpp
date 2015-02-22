#include <stdio.h>
#include <stdlib.h>

struct node {
       int info;
       struct node *left;
       struct node *right;
};

struct node *bst(struct node *head, int a) {
       if(head == NULL) {
               head = (struct node *)malloc(sizeof(struct node));
               head->info = a;
               head->left = NULL;
               head->right = NULL;
               return head;
       }
       if(head->info > a) {
                          head->left = bst(head->left, a);
       }
       else {
                          head->right = bst(head->right, a);
       }
       return head;
}

void inorder_print(struct node *root) {
     if(root == NULL) {
             return;
     }
     inorder_print(root->left);
     printf("%d ", root->info);
     inorder_print(root->right);
}

int main()
{
         int n;
         int a;
         int i;
         
         struct node *root = NULL;
         printf("enter the no. of nos. u want to enter ; ");
         scanf("%d", &n);
         
         for (i = 0; i < n; i++) {
             scanf("%d", &a);
             root = bst(root, a);
         }
         
         inorder_print(root);
         
         getchar();
         getchar();
         
         return 0;
}
