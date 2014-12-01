#include <cstdio>

int judge(int p, int q)
{
    int t = q;
    t &= (t-1);
    if (t)  return -1;
    int cnt = 0;
    while (p < q) {
        p *= 2;
        cnt++;
    }
    return cnt;
}

int gcd(int p, int q)
{
    return q == 0 ? p : gcd(q, p%q);
}

int main()
{
#ifdef LOCAL
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        int p, q;
        scanf("%d/%d", &p, &q);
        int t = gcd(p, q);
        p /= t;
        q /= t;
        int ans = judge(p, q);
        printf("Case #%d: ", kase);
        if (ans < 0)  printf("impossible\n");
        else  printf("%d\n", ans);
    }

    return 0;
}
