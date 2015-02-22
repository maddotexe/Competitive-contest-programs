#include <iostream>
#include <cstdlib>

using namespace std;

struct tree {
        int data;
        struct tree *left;
        struct tree *right;
};

void insert(struct tree *, int);
size_t size(struct tree *);
void tra_inorder(struct tree *);
struct tree *search(struct tree *, int );
void delete_node(struct tree **, int);
int findheight(struct tree *);
void no_of_nodes(struct tree *);

int main()
{
        struct tree *root;
        root = (struct tree *)malloc(sizeof(struct tree));
        int q;
        cin >> q;
        root->data = q;
        root->left = NULL;
        root->right = NULL;

        while (1) {
                cin >> q;
                if (q == -1) {
                        break;
                } 
                insert(root,q);
        }
        size_t t;

        t = size(root);
        cout << endl << " the size of the tree  " <<  t << endl << endl;
        cin >> q;
        struct tree *sr;
        sr = search(root,q);
        if (sr == NULL) {
                cout << " not present " << endl;
        }
        else
        cout << sr -> data << "\n";
        tra_inorder(root);
        int e;
        cout << endl << " the node you want to delete enter it " << endl;
        cin >> e;
        delete_node(&root,e);
        tra_inorder(root);
        int h;
        h = findheight(root);
        cout << endl << " the heigt of the tree is " << endl << h << endl;
        cout << endl;
        no_of_nodes(root);

        return 0;
}

void insert(struct tree *p, int w)
{
    if (w >= p->data) {
            if (p->right == NULL) {
                    p->right = (struct tree *)malloc(sizeof(struct tree));
                    p->right->data = w;
                    p->right->left = NULL;
                    p->right->right = NULL;
            } else {
                    insert(p->right,w);
            }
    } else {
            if (p->left == NULL) {
                    p->left = (struct tree *)malloc(sizeof(struct tree));
                    p->left->data = w;
                    p->left->left = NULL;
                    p->left->right = NULL;
            } else {
                    insert(p->left,w);
            }
    }
}

size_t size(struct tree *p)
{
       if (p == NULL) {
               return 0;
       } else {
               return(1 + size(p->left) + size(p->right));
       }
}

struct tree *search(struct tree *p, int w)
{
        if (p != NULL) {
                if (p->data == w) {
                        cout << " present " << endl;
                        return(p);
                } else if (w > p->data) {
                        search(p->right,w);
                } else if (w < p->data) {
                        search(p->left,w);
                }  
        }
        if (p == NULL) {
                return(NULL);
        }
}

void tra_inorder(struct tree *p)
{
        if (p != NULL) {
                tra_inorder(p->left);
                cout << p->data << "   ";
                tra_inorder(p->right);
         }
}

void delete_node(struct tree **p, int w)
{       if (*p == NULL) {
                cout << " query not *present in our database so no node can be deleted " << endl;
        } else {
                if ((*p)->data == w && (*p)->left == NULL && (*p)->right == NULL) {
                        *p = NULL;
                        cout << "working" << endl;
                } else if ((*p)->data == w && (*p)->left != NULL && (*p)->right == NULL) {
                        cout << " working" << endl;
                        *p = (*p)->left;
                } else if ((*p)->data == w && (*p)->left == NULL && (*p)->right != NULL) {
                        *p = (*p)->right;
                } else if ((*p)->data == w && (*p)->left != NULL && (*p)->right != NULL) {
                        struct tree *u;
                        u = (*p)->left;
                        while (u->right != NULL) {
                                u = u->right;
                        }
                
                        (*p)->data  = u->data;
                        
                        delete_node(&((*p)->left),u->data);
                } else if (w > (*p)->data) {
                        
                        delete_node((&(*p)->right),w);
                } else if (w < (*p)->data) {
                        
                        delete_node((&(*p)->left),w);
                }
        }
}

int findheight(struct tree *p)
{
        int h1 = 0;
        int h2 = 0;
        if (p == NULL) {
                return 0;
        }
        h1 = h1 + findheight(p -> left);
        h2 = h2 + findheight(p -> right);

        if (h1 > h2) {
                return (h1 + 1);
        } else {
                return (h2 + 1);
        }

 }

void no_of_nodes(struct tree *p)
{
        if (p != NULL) {
        static int c1 = 0;
        static int c2 = 0;
        static int c3 = 0;
        if (p -> left == NULL && p ->right == NULL) {
                c1++;
                if (p != NULL) {
                        no_of_nodes(p->left);
                        no_of_nodes(p->right);
                        cout << "no child " << endl << c1 << endl;
                }
               // cout << " the no. of no child nodes is " << endl << c1 << endl;
        } else if ((p -> left != NULL && p ->right == NULL) || (p -> left == NULL && p ->right != NULL)) {
                c2++;
                if (p != NULL) {
                        no_of_nodes(p->left);
                        no_of_nodes(p->right);
                        cout << "single child " << endl << c2 << endl;
                }
               // cout << " the no. of single child nodes " << endl << c2 << endl;
        } else {
                c3++;
                if (p != NULL) {
                        no_of_nodes(p->left);
                        no_of_nodes(p->right);
                        cout << "double child " << endl << c3 << endl;
                }
              //  cout << " the no. of double child nodes is " << endl << c3 << endl;
        }
        }
}
