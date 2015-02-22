#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<int> v1, int x)
{
	for (int i = 0; i < x; i++) {
		cout<< v1[i] <<"\t";
	}
	cout << endl;
}

int main()
{
	vector<int> v;
	vector<int>::iterator it;
	int i;
	int j;
	int n;
	
	cout<<"How many no's you want to enter?"<<endl;
	cin >> n;
	
	cout<<"Enter the numbers"<<endl;
	for (i = 0; i < n; i++) {
		cin >> j;
		v.push_back(j);
	}
	cout<<"Before sorting"<<endl;
	print(v , n);
	
	sort(v.begin(), v.end());
	cout<<"After sorting"<<endl;
	print(v, n);
	
	cout<<"Which no. you want to search?"<<endl;
	cin >> j;	
	
	if (binary_search(v.begin(), v.end(), j)) {
		cout<<"Number Found"<<endl;
	}
	
	else {
		cout<<"Number not found"<<endl;
	}

	it = (find(v.begin(), v.end(), j)); 
		cout<< *it <<endl;
	
	it = max_element(v.begin(), v.end());
	   	cout<<"Max element = "<< *it <<endl;

	random_shuffle(v.begin(), v.end());
	       	cout<<"Random shuffle makes it "<<endl;
		print(v, n);

	
	cout<<"How many permutations you want?"<<endl;
	cin >> j;
	
	for (i = 0; i < j; i++) {
	next_permutation(v.begin(), v.end());
	print(v, n);
	}
	
	
	
	return 0;
}
