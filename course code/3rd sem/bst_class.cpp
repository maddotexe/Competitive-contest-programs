#include <iostream>
#include <cstdlib>

using namespace std;

class node {
      public :
      int n;
      node * left;
      node *right;
      
      node()
      {
            left =NULL;
            right = NULL;
      }
};


class bst
{
      public :
      node *root;
      node *prev;
      
      bst(){
          root = NULL;
          }
      void insert (int n)
      {
           if(root == NULL) {
                       root = new node;
                       root->n = n;
                       root->right = NULL;
                       root->left = NULL;
                       return;
           }
           node *ptr = root;
           
           while(ptr != NULL)
           {
                     prev = ptr;
                     if(ptr->n <= n)
                               ptr = ptr->right;
                     else
                               ptr = ptr->left;
           }
           node *nu = new node;
           nu -> n = n;
           if(prev->n <= n)
                      prev->right = nu;
           else
                      prev->left = nu;
      }
      void inorder(node *root);
      void preorder(node *root);
      void postorder(node *root);           
};

void bst::inorder(node *root)
{
     if(root == NULL)
             return;
     bst::inorder(root->left);
     cout << root->n << " ";
     bst::inorder(root->right);
}

void bst::preorder(node *root)
{
     if(root == NULL)
             return;
     cout << root->n << " ";
     bst::preorder(root->left);
     bst::preorder(root->right);
}

void bst::postorder(node *root)
{
     if(root == NULL)
             return;
     bst::postorder(root->left);
     bst::postorder(root->right);
     cout << root->n << " ";
}
     

int main()
{
    bst ob1;
    int t,d;
    cout << "enter the no. of nos. : ";
    cin >> t;
    for(int i =0; i < t; i++)
    {
            cin >> d;
            ob1.insert(d);
    }
    cout << "inorder :";
    ob1.inorder(ob1.root);
    cout << endl;
    cout << "preorder :";
    ob1.preorder(ob1.root);
    cout << endl;
    cout << "postorder :";
    ob1.postorder(ob1.root);
    cout << endl;
   
   getchar();
   getchar();
    return 0;
}
            
      
