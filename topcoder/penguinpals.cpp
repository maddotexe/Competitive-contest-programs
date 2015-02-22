#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PenguinPals {
	public:
	
	int findMaximumMatching(string colors) {
		int i = 0;
		int c = 0;
		vector <int> v;
		int j = colors.size() - 1;
		for (i = 0; i < colors.size(); i++) {
			v.push_back(0);
		}
		i = 0;
		while (i < j) {
			while (colors[i] == colors[i + 1] && (v[i] == 0 && v[i + 1] == 0)) {
				
				c++;
				v[i]  = v[i + 1] = 1;
				i += 2;
				
				//cout << "i = " << i << "j = " << j << "c = " << c << endl;
			}
			while (colors[j] == colors[j - 1] && ( v[j] == 0 && v[j - 1] == 0)) {
				
				c++;
				v[j] = v[j - 1] = 1;
				j -= 2;
				//cout << "i = " << i << "j = " << j << "c = " << c << endl;
			}
		
		
			while (colors[i] != colors[j] && i < j ) {
				j--;
				//cout << "i = " << i << " j = " << j << " c = " << c << endl;
			}
				if (colors[i] == colors[j] && (v[i] == 0 && v[j] == 0) && i < j) {
				v[i] = v[j] = 1;
				i++;
				j--;
				c++;
				//cout << "i = " << i << " j = " << j << " c = " << c << endl;
				
			}
			
		}
		//cout << "i = " << i << "j = " << j << "c = " << c << endl;
		return c;
	}
};

int main()
{
    string s;
    int a;
    cin >> s;
    
    PenguinPals ob;
    a = ob.findMaximumMatching(s);
    
    
    cout << a;
    
    cin >> a;
}
