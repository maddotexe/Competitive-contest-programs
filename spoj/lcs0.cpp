#include <iostream>
#include <cstdio>

using namespace std;

int max(int i, int j) {
	if (i < j) return j;
	else return i;
}

int main()
{
        string s, s1;
        int n, i, j;
        char a[50001], b[50002];
	scanf("%s%s", a, b);
	s = a;
	s1 = b;
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
                cout << v[(i-1)&1][s.size()] << endl;
        

        return 0;
}


