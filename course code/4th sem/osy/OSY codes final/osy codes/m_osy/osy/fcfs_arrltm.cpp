#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int bt,at;
	int pn[n], a[n], b[n], w[n];

	for(int i=0; i<n; i++){
		cin >> at >> bt ;
		a[i]=at;
		b[i]=bt;
	
	}
	int sum=0,wt=0;
	double t=0;
	cout << "waiting time for p[0] 0" <<  endl;
	for(int i=0; i<n-1; i++){
		sum= sum+b[i]; //cout << "sum "<< sum <<endl;
		wt=(sum-a[i+1]); //cout << "wt " << wt << endl;
		t=t+wt; //cout << "t " << t << endl;
		cout << "waiting time for p[" << i+1 << "] " << wt << endl;
	}
		
	cout << "total waiting time " << t << endl;
	double av_wt = double(t)/n;
	cout << "average waiting time " << av_wt << endl;

	return 0;
}
	
