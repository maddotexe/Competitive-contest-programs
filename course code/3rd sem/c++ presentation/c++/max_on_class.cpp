//max() on class 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class a {
    public :
        int data;
        
};

bool operator<(a a2, a a1) {
            if (a2.data < a1.data) {
                return true;
            }
            else {
                return false;
            }
}

bool mycmp(a a1, a a2)
{
    if (a2.data > a1.data) {
        return false;
    }
    else {
        return true;
    }
}

int main()
{
    vector<a> v;
    a a1;
    a a2;
    
    a1.data = 6;
    v.push_back(a1);
    
    a2.data = 2;
    v.push_back(a2);

    cout << "The values in the vector\n" << v[0].data << " " << v[1].data << endl;
    cout << "\n\nThe max value without predicate : " << max(a1, a2).data << endl;
    cout << "\nThe max value using predicate : " << max(a1, a2, mycmp).data << endl;
    
    cin >> a1.data;
    return 0;
}
