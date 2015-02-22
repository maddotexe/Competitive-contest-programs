#include <iostream>
#include <map>
using namespace std;

template <typename T, typename T1>
class my_map : public map<T, T1>
{
      public:
      map<T, T1> m;
 //     typename map<T, T1>::iterator it = this->begin() ;
      
      
            
      
      
};

int main()
{
    my_map<int, int> ob;
    my_map<int, int>::iterator it1;
    ob.insert(pair<int, int> (2, 3));
    ob.insert(pair<int, int> (3, 3));
    it1 = ob.begin();
    cout << (*it1).first;
    it1++;
    cout << (*it1).first;

    system("pause");
    return 0;
}
    
