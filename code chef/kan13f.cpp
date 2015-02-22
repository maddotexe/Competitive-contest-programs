#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, k, t, cs = 1;
	cin >> t;
	long long int sum, x;
	
	while (t--) {
		cin >> n >> k;
		sum = 0;
		priority_queue <long long int, vector<long long int>, greater<long long int> > pq;
		
		for (int i = 0; i < n; i++) {
			cin >> x;
			pq.push(x);
		}
		 long long  mod = (k - 2) - (n - 2) % (k - 1);
		 for (long long  i = 0; i < mod; i++) {
		 	pq.push(0LL);
		 }
		while (pq.size() != 1) {
			long long tmp = 0;
			
			for (int i = 0; i < k; i++) {
				tmp += pq.top();
				pq.pop();
			}
			pq.push(tmp);
			sum += tmp;
		}
		cout << "Case " << cs++ << ": " << sum << endl;
	}
	
}
