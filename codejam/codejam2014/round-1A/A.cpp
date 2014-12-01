#include <cstdio>

const int maxn = 160;
unsigned int outlet[maxn], device[maxn];
int n, l;

int bit_sum(unsigned int * a, int n, int k)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (a[i] & (1<<k))
            sum++;
    return sum%2;
}

int check()
{
    unsigned int flag = 0;
    for (int i = 0; i < l; i++) {
        int x = bit_sum(outlet, n, i);
        int y = bit_sum(device, n, i);
        if (n % 2 == 0 && x == y)
            flag += (1<<i);
        else if (n % 2 && x != y)
            flag += (1<<i);
    }
    if (n % 2 == 0 && flag == 0)  return -1;
    return 0;
}

int main()
{
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        scanf("%d%d", &n, &l);
        for (int i = 0; i < n; i++)
            scanf("%u", &outlet[i]);
        for (int i = 0; i < n; i++)
            scanf("%u", &device[i]);
        printf("Case #%d: ", kase);
        if (check() == -1)  printf("NOT POSSIBLE\n");
        else  printf("%d\n", check());
    }

    return 0;
}
