#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 160;
unsigned int outlet[maxn], device[maxn], changed[maxn];
int n, l;

int main()
{
#ifdef LOCAL
    freopen("A-small-practice.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        scanf("%d%d", &n, &l);
        for (int i = 0; i < n; i++)
            scanf("%u", &outlet[i]);
        for (int i = 0; i < n; i++)
            scanf("%u", &device[i]);
        sort(device, device+n);

        int ans = maxn;
        for (int i = 0; i < (1<<l); i++) {
            for (int j = 0; j < n; j++)
                changed[j] = outlet[j];
            for (int j = 0; j < l; j++)
                if (i & (1<<j))
                    for (int k = 0; k < n; k++) {
                        if (changed[k] & (1<<j))
                            changed[k] -= (1<<j);
                        else  changed[k] += (1<<j);
                    }

            sort(changed, changed+n);
            bool same = true;
            for (int j = 0; j < n; j++)
                if (changed[j] != device[j]) {
                    same = false;
                    break;
                }
            if (same) {

                int cnt = 0;
                for (int j = 0; j < l; j++)
                    if (i & (1<<j))
                        cnt++;
                if (cnt < ans)  ans = cnt;
            }
        }

        printf("Case #%d: ", kase);
        if (ans == maxn)  printf("NOT POSSIBLE\n");
        else  printf("%d\n", ans);
    }

    return 0;
}
