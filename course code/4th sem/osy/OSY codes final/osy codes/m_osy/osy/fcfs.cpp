#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int bt;
	int b[n], w[n];

	for(int i=0; i<n; i++){
		cin >> bt;
		b[i]=bt;
	
	}
	int sum=0,wt=0;
	for(int i=0; i<n-1; i++){
		sum= sum+b[i];
		wt=wt+sum;
		cout << sum << endl;
	}
		
	cout << "total waiting time " << sum << endl;
	cout << "average waiting time " << (wt/n) << endl;

	return 0;
}
	
