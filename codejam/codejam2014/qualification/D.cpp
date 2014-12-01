#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1010;
double Naomi[maxn], Ken[maxn];

int main()
{
    freopen("D-large.in", "r", stdin);
    freopen("D-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lf", &Naomi[i]);
        for (int i = 0; i < n; i++)
            scanf("%lf", &Ken[i]);
        sort(Naomi, Naomi+n);
        sort(Ken, Ken+n);

        int p = 0, q = 0;
        while (p < n) {
            while (q < n && Naomi[p] > Ken[q])  q++;
            if (q >= n)  break;
            else {
                p++;
                q++;
            }
        }
        int z = n - p;

        p = q = 0;
        int y = 0;
        while (p < n) {
            if (Naomi[p] < Ken[q])  p++;
            else {
                p++;
                q++;
                y++;
            }
        }
        printf("Case #%d: %d %d\n", kase, y, z);
    }
}
