 #include <iostream>
 using namespace std;
 
 template <typename T>
 class node {
       public :
       T x;
       node *next;
 };
 
 template <typename T>
 class nlist {
       public :
              node<T> *root;
              node<T> *head;
              nlist() {
                      root = NULL;
              }
              
              void push_front(int x) {
                   if (root == NULL) {
			          root = new node<T>;
			          root->x = x;
			          root->next = NULL;
				  head = root;
		    } else {
                                  node<T> *tmp = new node<T>;
                                  tmp->x = x;
				  tmp->next = NULL;
                                  head->next = tmp;
				  head = head -> next;				 
                    }
              }
              node<T> *begin()
              {
		      
                      return root;
              }
                           
              node<T> *end() {
                      return NULL;
              }
              
              class iterator {

                    public :
                           
                           node<T> *ptr;
                           void operator =(node<T> *pt) {
                                ptr = pt;
                           }
                           T operator *() {
                                      return ptr->x;
                           }
                           void operator ++() {
                                 ptr = ptr->next;
                           }
                           bool operator != (node<T> * t) {
                                return (t != ptr?true : false);
                           }
              };
 };
 
 
 int main()
 {
     nlist<string> l;
     nlist<string>:: iterator it;
     int i;
 
     for(i = 0;i < 5; i++) {
           l.push_front(i+65);
     }
         
     for(it = l.begin(); it != l.end(); ++it) {
            cout << *it << " ";
     }

     return 0;
 }
                           
                           
