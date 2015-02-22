#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool mycmp(int a1, int a2)
{
    if (a2 > a1) {
        return false;
    }
    else {
        return true;
    }
}

int main()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    
    cout << "The values in the vector\n";
    for (int i = 0; i < 2; i++) {
        cout << v[i] << " ";
    }
    
    cout << "\n\nThe max without predicate : " << max(v[0], v[1]);
    cout << "\nThe max using predicate : " << max(v[0], v[1], mycmp);
    
    cin >>v[0];
    return 0;
}
