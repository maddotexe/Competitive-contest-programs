#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
int n;
pair<int, int> tree[3000005];
int ar[100005];

void initialise(int val, int b, int e)
{
    if(b > e) return;
    else if(b == e) {
        tree[val].first = ar[b];
        tree[val].second = ar[b];
        return;
    }
    initialise(val*2+1, b, (b+e)/2);
    initialise(val*2+2, (b+e)/2+1, e);
    tree[val].first = max(tree[val*2+1].first, tree[val*2+2].first);
    tree[val].second = min(tree[val*2+1].second, tree[val*2+2].second);
}

void update(int val, int b, int e, int index, int no)
{
    if(b > e || b > index || index > e) return;
    if(b == e) {
        tree[val].first += no;
        tree[val].second += no;
        return;
    }
    update(val*2+1, b, (b+e)/2, index, no);
    update(val*2+2, ((b+e)/2)+1, e, index, no);
    tree[val].first = max(tree[val*2+1].first, tree[val*2+2].first);
    tree[val].second = min(tree[val*2+1].second, tree[val*2+2].second);
}

int val;

void minquery(int pos, int b, int e, int l, int r)
{
        if(b > e || b > r || e < l) return;
        if(b >= l && e <= r) {
           // cout << b << " " << e << endl;
            if(!val)
            val = tree[pos].second;
            else val = min(val, tree[pos].second);
            return;
        }
        minquery(pos*2+1, b, (b+e)/2, l, r);
        minquery(pos*2+2, (b+e)/2+1, e, l, r);
}

void maxquery(int pos, int b, int e, int l, int r)
{
        if(b > e || b > r || e < l) return;
        if(b >= l && e <= r) {
          //  cout << b << " " << e << endl;
            val = max(val, tree[pos].first);
            return;
        }
        maxquery(pos*2+1, b, (b+e)/2, l, r);
        maxquery(pos*2+2, (b+e)/2+1, e, l, r);
}

int main()
{
    int t, q, i, j, c = 1;

	cin >> t;
	while (t--) {
        	scanf("%d%d", &n, &q);
        	for(int i = 0; i < n; i++) {
        	    scanf("%d", &ar[i]);
        	}
        	initialise(0, 0, n-1);		
		printf("Scenario #%d:\n", c++);
	        for(int i = 0; i < q; i++) {
       	        	int l, r;
       	       	  	scanf("%d%d", &l, &r);
       	        	val = 0;
      	        	minquery(0, 0, n-1, l - 1, r - 1);
       		        printf("%d\n", val);
        	}
        }

}
