#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

struct node {
       struct node *next;
       string s;
};

int main()
{
    int t = 0, n, i ,j, sum;
    struct node *a[100];
    struct node *head = NULL;
    struct node *p = NULL;
    string s;
    
    while(t < 100) {
            a[t] = NULL;
            t++;
    }
    cin >> n;
    
    while(n--) {
               sum = 0;
               cin >> s;
               
               head = (struct node *)malloc(sizeof(struct node));
               head->next = NULL;
               head-> s = s;
              
               for( i = 0; s[i] != '\0'; i++)
               {
                    sum += s[i];
               }
               sum = sum %100;
               p = a[sum];
               if( a[sum] == NULL)
               {
                   a[sum] = head;
               }
               else {
                    while(p->next != NULL)
                    {
                                 p = p->next;
                    }
                    p->next = head;
               }
    }   
    cin >> s;
    sum = 0;
    for( i = 0; i != s.size(); i++)
    {
         sum += s[i];
    }
    sum = sum %100;
    p = a[sum];
    while (p!= NULL)
    {
          if(p->s == s)
          {
                  cout << "found";
                  break;
          }
          p = p->next;
    }
    getchar();
    getchar();
    return 0;
}
