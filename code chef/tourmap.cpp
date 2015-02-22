#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

int main()
{
    map<string, pair<string, string> > m;
    vector<string> v(5001), v1(5001) , v2;
    int t;
    int n;
    int sum;
    int k;
    string s;
    int j;
    
    pair <string, string> p;
    scanf("%d", &t);
    
    while (t--) {
          cin >> n;
          if (n == 1) 
             cout << "0$\n";
          else {
          sum = 0;
          for (int i = 0; i < n - 1; i++) {
              k = 0;
              j = 0;
              cin >> s;
              v.push_back(s);
              cin >> p.first;
              cin >> p.second;
              v1.push_back(p.first);
              m.insert(pair<string, pair<string, string> >(s, p));
              while (p.second[j] != '$') {
                    k = k * 10 + (p.second[j] - 48);
                    j++;
              }
              sum += k;
              
          }
          sort(v.begin(), v.end());
          sort(v1.begin(), v1.end());
          
          set_difference(v.begin(), v.end(), v1.begin(), v1.end(), inserter(v2, v2.end()));
          
          j = n - 1;
          s = v2[0];
          while (j--) { 
                cout << s << " " << m[s].first << " " << m[s].second << endl;
                s = m[s].first;
          }
          cout << sum << "$" << endl;
          
          v.clear();
          v1.clear();
          v2.clear();
          m.clear();
          }
    }
    return 0;
}
          
