#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <iomanip>

using namespace std;

struct node {
    long long int dis;
    int x;
    int y;
};
node p[50005];
node s[50005];

bool x_cmp(node p, node q) {
    return p.x < q.x;
}

bool y_cmp(node p, node q) {
    return p.y < q.y;
}

long long int sqr(int x) {
    return x * x;
}
node merge(node p[], int mid, int left, int right, node res)
{
	int m = 0;
	cout << res.dis << " ppp" << endl;
	long long int d = sqrt(res.dis) + 1;
	for (int i = mid; i >= mid && p[mid].x - p[i].x <= d; i--) 
		s[m++] = p[i];
	for (int i = mid + 1; i <= right && p[i].x - p[mid].x <= d; i++) 
		s[m++] = p[i];
	
	sort (s, s + m, y_cmp);
	
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			long long int d1 = sqr(s[j].y - s[i].y);
			if (d1 > res.dis) break;
			d1 += sqr(s[j].x - s[i].x);
			if (d1 < res.dis) {
				res.x = min(s[i].dis, s[j].dis);
				res.y = max(s[i].dis, s[j].dis);
				res.dis = d1;
			}
		}
	}
	return res;
}
node divide (node p[], int left, int right) {
	if (left >= right) {
		node res;
		res.dis = INT_MAX;
		return res;
	}
	
	int mid = (left + right) / 2;
	
	int k = mid;
	
	while (k >= left && p[k].x == p[mid].x) k--;
	
	node res1 = divide(p, left, k);
	
	k = mid + 1;
	
	while(k <= right && p[k].x == p[mid].x) k++;
	
	node res2 = divide(p, k, right);
	
	node res = (res1.dis < res2.dis)? res1 : res2;
	cout << res.dis << endl;
	res = merge(p, mid, left, right, res);
	
	return res;
}

int main()
{
    int n;
    int x;
    int y;
    cout << setiosflags(ios::fixed) << setprecision(6);
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        p[i].dis = i;
        cin >> p[i].x >> p[i].y;
    }
    
    sort (p, p + n, x_cmp);
    
    node res = divide(p, 0 ,n - 1);
    
    cout << res.x << " " << res.y << " " << sqrt((double)res.dis) << endl;
    
    
    return 0;
}
