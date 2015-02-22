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
    int v[10];
    
    for (int i = 0; i < 10; i++) {
        v[i] = i;
    }
    cout << "The values in the array\n";
    for (int i = 0; i < 10; i++) {
        cout << v[i] << " ";
    }
    
    cout << "\n\nThe max element without prediacte : " << *max_element(v, v+10);
    cout << "\nThe max element using predicate : " << *max_element(v, v + 10, mycmp) << endl;
    
    cin >>v[0];
    return 0;
}
