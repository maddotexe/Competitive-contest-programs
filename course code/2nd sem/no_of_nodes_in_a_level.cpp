#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

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

int main()
{
    queue <struct node *> q;
    struct node *root = NULL, *p;
    int n, i, c,d,k,si=0,size=1;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
          scanf("%d", &c);
          make_bst(&root, c);
    }
    scanf("%d", &k);
    d=0;
    p = root;
    q.push(p);
    while (d<k)
    {
          si=0;
          for ( i=0; i <size; i++)
          {
          p = q.front();
          if(p->left != NULL)
          {
                        si++;
                        q.push(p->left);
                        cout << "\n push " << p->left->x;
                        
          }
          if(p->right != NULL)
          {
                      si++;
                      q.push(p->right);
                      cout << "\n push " << p->right->x;
          }
          cout<< "\n\npop " << q.front()->x;
          q.pop();
          }
          size = si;
          
          d++;
    }
    while(!q.empty())
    {
                     p = q.front();
                     cout << p->x;
                     
                     q.pop();
    }
    getchar();
    getchar();

    return 0;
    }
          
    
    
