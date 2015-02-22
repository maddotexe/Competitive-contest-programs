#include <stdio.h>
#include <stdlib.h>

struct node {
       int x;
       struct node *next;
       struct node *prev;
};

int main()
{
    struct node *head;
    struct node *p;
    struct node *q;
    int n, c, i;
    scanf("%d", &n);
    scanf("%d", &c);
    head = (struct node *)malloc(sizeof(struct node ));
    head->x = c;
    head->next = NULL;
    head->next = NULL;
    q = head;
    for (i = 0; i < n - 1; i++)
    {
        scanf("%d", &c);
        p = (struct node *)malloc(sizeof(struct node ));
        p->x = c;
        p->next = NULL;
        p->prev = q;
        q->next = p;
        q = q->next;
    }
    
    scanf("%d", &c);
    p = head;
    c=c-1;
    while(c--)
    p = p->next;
   // printf("%d", p->x);
    p->prev->next = p->next;
    p->next->prev = p->prev;
    p = head;
    while(p!=NULL)
    {
                  printf("%d %d\n" ,p->x, q->x);
                  q = q->prev;
                  p = p->next;
    } 
    getchar();
    getchar();
    return 0;
}   
        
