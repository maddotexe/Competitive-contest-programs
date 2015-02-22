#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <memory>
#include <numeric>
#include <functional>
#include <iomanip>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
 
#define pb push_back
#define mp make_pair
using namespace std;
//--------------------------
long long n, k, l, r, sall, sk, ans;

//--------------------------
int main(){ 
    cin>>n>>k>>l>>r>>sall>>sk;
    if(k > 0){
        for(int i = 0; i < sk % k; i++){
            cout<< sk/k + 1<<" ";
        }
        for(int i = 0; i < k - sk % k; i++){
            cout<< sk/k<< " ";
        }
    }
    sall -= sk;
    n -= k;
    if(n > 0){
        for(int i = 0; i < sall % n; i++){
            cout<< sall/n + 1<<" ";
        }
        for(int i = 0; i < n - sall % n; i++){
            cout<< sall/n<< " ";
        }
    }
  //  system("pause");
    return 0;
}
