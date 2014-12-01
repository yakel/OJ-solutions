#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 10;
int a[maxn];

int C(int n, int k)
{
    k = min(k, n-k);
    if (k == 0)  return 1;
    if (k == 1)  return n;
    return C(n-1, k) + C(n-1, k-1);
}

int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        int N, K;
        scanf("%d%d", &N, &K);
        for (int i = 0; i < N; ++i)
            scanf("%d", &a[i]);
        sort(a, a+N);
        int sum = 0;
        for (int i = K; i <= N; ++i)
            sum += a[i-1] * C(i-1, K-1);
        printf("Case #%d: %d\n", kase, sum);
    }
    return 0;
}
