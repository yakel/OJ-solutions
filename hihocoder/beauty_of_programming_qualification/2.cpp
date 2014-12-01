#include <cstdio>

const int MOD = 1000000000 + 7;

int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        long long n;
        scanf("%lld", &n);
        int sum = 0;
        for (long long i = 1; i <= n; i++)
            for (long long j = 1; j <= n; j++)
                for (long long k = 1; k <= n; k++)
                    if ( (i != j && i != k && j != k) ||
                            (i == j && j ==k) ) {
                        long long t1 = (n+1-i) % MOD;
                        long long t2 = (n+1-j) % MOD;
                        long long t3 = (n+1-k) % MOD;
                        int t = int( ( (t1*t2) % MOD * t3 ) % MOD );
                        sum = ( sum + t ) % MOD;
                    }
        printf("Case %d: %d\n", kase, sum);
    }

    return 0;
}
