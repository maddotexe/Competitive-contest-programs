#include<stdlib.h>
#include<iostream.h>



 typedef struct node 
{int val;
struct node * next;
struct node * prev;

       
       
}NODE;


int main()
{int i=1 ;
  
  cout<<" akash";

node * head ,* temp,* temp2;
while(i<=10)
{
temp2=(node*)malloc(sizeof(NODE));
if(i==1)
{
        head=temp2;
        temp2->prev=NULL;
        temp2->val=1;}
        else {
             temp2->val=i;
             temp->next=temp2;
             temp2->prev=temp;
             temp2->next=NULL;
             }
             
 temp=temp2; 
 i++;}
 temp=head;
 
 do{cout<<"\n value is "<<temp->val;
 
 temp2=temp;
 temp=temp->next;
 }
while(temp);
temp=temp2;
cout<<"\nreverse"; 
 
do {
                  
                  cout<<"\n value is "<<temp->val;
 temp=temp->prev;
 }
 while(temp);
 
 
 
 
 
 
    cin>> i;
    
    
    return 0;}
