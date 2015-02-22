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
    
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    cout << "The numbers in the vector\n";
    for (int i = 0; i < 10; i++) {
        cout << v[i] << " ";
    }
    cout << "\n\n\nThe max_element without using predicate : " << *max_element(v.begin(), v.end()) << "\n";
    cout << "\nThe max_element using predicate : " << *max_element(v.begin(), v.end(), mycmp);
    
    cin >>v[0];
    return 0;
}
