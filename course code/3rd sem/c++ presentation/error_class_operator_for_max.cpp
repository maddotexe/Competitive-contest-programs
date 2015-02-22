#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class a {
    public :
        int data;
        
        bool operator<(a a1) {
            if (data < (a1).data) {
                return true;
            }
            else {
                return false;
            }
        }
};

int main()
{
    vector<a> v;
    a a1;
    a a2;
    
    a1.data = 6;
    v.push_back(a1);
    
    a2.data = 2;
    v.push_back(a2);
//    a1.data = max(a1, a2).data;
    cout << v[0].data << " " << v[1].data << endl;
    cout << "max : " << max(a1, a2).data << endl;
    
    cin >> a1.data;
    return 0;
}
