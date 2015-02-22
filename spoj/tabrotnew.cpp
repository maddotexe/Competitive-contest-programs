#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

vector<string> func90(vector<string> v) {
	vector<string> v1;
	string s;
	for (int i = 0; i < v[0].size(); i++) {
		s = "";
		for (int j = v.size() - 1; j >= 0; j--) {
	 		s += v[j][i];
		}
		v1.push_back(s);
	}
	
	return v1;
}

vector<string> func45(vector<string> v) {
	int r = v.size();
	int c = v[0].size();
	string s;
	vector<string> v1;
	for (int i = 0; i < r + c - 1; ++i) {
	    s = "";
 	    int z1 = i < c ? 0 : i - c + 1;
	    int z2 = i < r ? 0 : i - r + 1;
	    for (int j = i - z2; j >= z1; --j) {
   		s += v[j][i - j];
	    }
	    
	    v1.push_back(s);
        }
        return v1;
}
int main()
{
	int r, c;
	vector <string> v, v1;
	string s;
	char ch;
	int k;
	int i, j, f, h, t ,g;
	
	scanf("%d%d", &r, &c);
	
	for (i = 0; i < r; i++) {
		s = "";
		for (j = 0; j < c; j++) {
			cin >> ch;
			s += ch;
			
		}
		v.push_back(s);
	}
	
	scanf("%d", &k);
	

	k = k / 45;
	f = 0;
	while (k > 0) {
		if (k >= 2) {
			v = func90(v);
			k -=2;
			if (k == 0) {
				f = 1;
			}
			continue;
		}
		if (k == 1) {
			r = v.size();
			c = v[0].size();
			v = func45(v);
			k--;
		}
	}
	if (f == 1) {
	   for (i = 0; i < v.size(); i++) {
	       cout << v[i];
	       cout << endl;
           }
           return 0;
        }
        int d = 1;
        for (i = 0; i < r; i++) {
            for (j = 0; j < r - d; j++) {
	    	cout << " ";
	    }
	    for (t = 0; t < v[i].size(); t++) {
	    	cout << v[i][t] << " ";
	    }
	    cout << endl;
	    d++;
        }
        d = c - 1;
        for (i = 0; i < c; i++) {
        	for (j = 0; j < c - d; j++) {
        		cout << " ";
        	}
        	for (t = 0; t < v[i + r].size(); t++) {
        		cout << v[i + r][t] << " ";
        	}
        	cout << endl;
        	d--;
        }
	return 0;
}
