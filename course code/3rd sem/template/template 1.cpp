#include <iostream>
//#include <template>
#include <cstdio>

using namespace std;
template <typename t>

t fun ( t d, t f) {
     d = d + f;
     return d;
}
int main()
{
    float  d = 4.4;
    float g =6;
    g = fun (4.4, 6.3);
    cout << g;
    getchar();
    getchar();
    return 0;
}
    
