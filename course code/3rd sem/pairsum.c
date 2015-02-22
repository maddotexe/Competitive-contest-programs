#include <stdio.h>

int main()
{
    unsigned long long int n, m, u, v, i, s, j;
    scanf("%lld", &n);
    unsigned long long int a[n], sum[n];
    
    for (i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum[i] = 0;
        if (i == 0) {
            sum[i] = a[i];
        } else {
            sum[i] = sum[i-1] + a[i];
        }
    }
    scanf("%lld", &m);
    for (i = 0; i < m; i++) {
        scanf("%lld%lld", &u, &v);
        s = 0;
        for (j = u; j <= v; j++) {
            s += sum[j] * a[j];
            printf ("%d ", s);
        }
        if (u != 0) {
               s -= (sum[v] - sum[u - 1]) * sum[u - 1];
        }
        printf("%lld\n", s);
    }

    return 0;
}
