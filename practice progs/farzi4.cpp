#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	int n,m,i,j,ans=0;
	string s[5000];
	vector<int> v[5000];
	cin>>n>>m;
	for (j=0;j<n;j++)
	{
		cin>>s[j];
		for (i=0;i<m;i++)
			if (s[j][i]=='0') v[i].push_back(0);
			else if (!i) v[i].push_back(1);
			else v[i].push_back(v[i-1][j]+1);
	}
	for (i=0;i<m;i++)
	{
		sort(v[i].begin(),v[i].end());
		for (j=0;j<n;j++) cout << v[i][j]<< " " ;;
		cout << endl;
	}
	cout<<ans<<endl;
	return 0;
}