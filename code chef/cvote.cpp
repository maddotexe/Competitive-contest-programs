#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main()
{
    int n, n1, i, p;
    string s, s1;
    map<string, string> m;
    map<string, int> m1, m2;
    map<string, int>::iterator it;
    
    scanf("%d%d", &n, &n1);
    
    for (i = 0; i < n; i++) {
        cin >> s >> s1;
        
        m.insert(pair<string, string> (s, s1));
        m1.insert(pair<string, int> (s, 0));
        m2.insert(pair<string, int> (s1, 0));
        
    }
    
    for (i = 0; i < n1; i++) {
        cin >> s;
        m1[s]++;
        m2[m[s]]++;
    }
    
    it = m2.begin();
    s = it->first;
    p = it->second;
    for (i = 0; i < m2.size(); i++, it++) {
        if (p < it->second) {
              p = it->second;
              s = it->first;
        }
    }
    
    cout << s << endl;
    
    it = m1.begin();
    s = it->first;
    p = it->second;
    for (i = 0; i < m1.size(); i++, it++) {
        if (p < it->second) {
              p = it->second;
              s = it->first;
        }
    }
    
    cout << s << endl;
    return 0;
    
}
