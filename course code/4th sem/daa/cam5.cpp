#include <cstdio>

using namespace std;

int dp[100009];

int root(int x)
{
    if (dp[x] == -1) {
        return x;
    }
    return root(dp[x]);
}

int main()
{
	int n, t, e, a, b;

	scanf("%d", &t);
	while (t--) {
        scanf("%d%d", &n, &e);
        for (int i = 0; i < n; i++) {
            dp[i] = -1;
        }
        while (e--) {
            scanf("%d%d", &a, &b);
            b = root(b);
            a = root(a);
            if (b != a) {
                dp[b] = a;
            }
        }
        e = 0;
        for (int i = 0; i < n; i++) {
            e += (dp[i] == -1);
        }
        printf("%d\n", e);
	}

	return 0;
}


