#include <iostream>

using namespace std;

int main()
{
	string s, s1;
	cin >> s >> s1;
	string s2 = "", s3 = "";
	int i = 0;
	if (s.size() == 1) {
		
		if (s1.size() % 2 == 0) {
			for (int i = 0; i < s1.size(); i+=2) {
				s2 += s1[i];
				s3 += s1[i+1];
			}
			cout << s2 << "|" << s3 <<endl;
		} else {
			cout << "Impossible\n";
		}
		
		return 0;
	}
	while (s[i] != '|') {
		s2 += (char)s[i++];
	}
	i++;
	while (i < s.size()) {
		s3 += (char) s[i++];
	}
	//cout << s2.size() << endl << s3.size() << endl;
	int d = s2.size() - s3.size();
	if (d < 0) d = -d;
	
	int e = s1.size() - d;
	//cout << e << endl;
	i = 0;
	if ((e >= 0) && e % 2 == 0) {
		if (s2.size() < s3.size()) {
			for (i = 0; i < d; i++) {
				s2 += s1[i];
			} 
		} else if (s2.size() > s3.size()) {
			for (i = 0; i < d; i++) {
				s3 += s1[i];
			} 
		}
		if (e > 0) {
			for (i; i < s1.size(); i+= 2) {
				s2 += s1[i];
				s3 += s1[i+1];
			}
		}
		cout << s2 << "|" << s3 <<endl;
	}
	else cout << "Impossible\n";
}
