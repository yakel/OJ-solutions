#include <cstdio>

const int maxn = 30;
const int INF = 100000000;
int a[maxn];
int n, k, lmin;

void promote()
{
    for (int i = 0; i < n; i++)
        if (a[i] % k)
            a[i] = (a[i]+k-1) / k * k;
}

int gcd(int a, int b)
{
    if (a < b)  return gcd(b, a);
    return b==0 ? a : gcd(b, a%b);
}

void dfs(int deep)
{
    if (deep > 3)  return;
    bool valid = true;
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (gcd(a[i], a[j]) != k) {
                valid = false;
                a[i] += k;
                dfs(deep+1);
                a[i] -= k;

                a[j] += k;
                dfs(deep+1);
                a[j] -= k;
            }
    if (valid) {
        int sum = 0;
        for (int i = 0; i < n; i++)  sum += a[i];
        if (sum < lmin)  lmin = sum;
    }
}

int main()
{
#ifdef LOCAL
    freopen("preventing_alzheimers.txt", "r", stdin);
    freopen("4.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        scanf("%d%d", &n, &k);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        promote();
        lmin = INF;
        dfs(0);
        printf("Case #%d: %d\n", kase, lmin - sum);
    }
    return 0;
}
