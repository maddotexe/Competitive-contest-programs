#include <iostream>
#include <list>

using namespace std;

template <typename T>
class nlist : public list<T>
{
      public:
      T& operator[](int x) 
      {
            typename list<T>::iterator it = this->begin();
            cout << this->size() << endl;
            if(x < this->size())
                 advance (it, x);
            else {
                 for (int i = this->size(); i <= x; i++) {
                     this->push_back(0);
                 }
             advance(it, x);
             } 
            return *it;
      }
};

typedef int string;
int main()
{
    nlist<int> ob;
    nlist<int> :: iterator it;
    ob.push_back(2);
    ob.push_back(3);
    ob[3] = 5;
 //   cout << ob[5];
    for (it  = ob.begin(); it != ob.end(); it++) {
        cout << *it << endl;
    }
    
    system("pause");
    return 0;
}          
