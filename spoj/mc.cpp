#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


int main()
{
        string s, s1;
        int n, i, j;
        cin >> s >> s1;

        while (s != "#") {
                int v[2][s.size() + 1];
                for (i = 0 ;i <= s1.size(); i++) {
                        for (j = 0; j <= s.size(); j++) {
                                if (i == 0 || j == 0) {
                                        v[i&1][j] = 0;
                                } 
                		else {
                                        v[i&1][j] = max(v[!(i&1)][j], v[i&1][j - 1]);
                                	if (s[j-1] == s1[i-1]) {
                                        	v[i&1][j] = max(v[i&1][j], v[!(i&1)][j - 1] +1);
                                	}
                                }
                        }
                }
                cout << (s.size() - v[(i-1)&1][s.size()]) * 15 + (s1.size() - v[(i-1)&1][s.size()]) * 30 << endl;
                
                cin >> s >> s1;
        }

        return 0;
}

