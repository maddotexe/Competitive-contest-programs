#include <stdio.h>
#include <stdlib.h>

struct node {
       int x;
       node *next;
};


int main()
{
    int i;
    int x;
    int n;
    struct node *p, *q, *root;
    
    printf("enter the no of nos. : ");
    scanf("%d", &n);
    scanf("%d", &x);
    
    
    root = (struct node *)malloc(sizeof(struct node));
    root-> x = x;
    root->next = NULL;
    
    q = root;
    
    for (i = 0; i < n - 1; i++) {
        scanf("%d", &x);
        p = (struct node *)malloc(sizeof(struct node));
        p->x = x;
        p->next = NULL;
        q->next = p;
        q = q->next;
    }
    
    q = root;
    while (q != NULL) {
          printf("%d ", q->x);
          q = q->next;
    }
    
    getchar();
    getchar();
    
    return 0;
}
    
        
