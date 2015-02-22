#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	string s[10];
	char s1[15], s2[300];
	while ((scanf("%s%s", s1, s2) == 2)) {
		for (int i = 0; i < 10; i++) s[i] = "";
		int len = strlen(s2);
		int len1 = strlen(s1);
		int j = 2;
		int k = 0;
		for (int i = 0; i < len; ) {
			if (j == 2) {
				//cout << s2[i] << " " << s2[i +1] << " " << s1[k] <<endl;
				s[s1[k] - 48] += s2[i];
				if (i + 1 == len) break;
				s[s1[k++] - 48] += s2[i+1];
				i += 2;
				j = 1;
			}
			if (i >= len) break;
			if (k == len1) {
				k = 0;
			}
			if (j == 1) {
				//cout << s2[i] << " " << s1[k] <<endl;
				s[s1[k++] - 48] += s2[i++];
				j = 2;
			}
			if (k == len1) {
				k = 0;
			}
			
		}
		
		for (int i = 0; i <=len1; i++) {
			cout << s[i];
		}
		cout << endl;
	}
	
	return 0;
}
