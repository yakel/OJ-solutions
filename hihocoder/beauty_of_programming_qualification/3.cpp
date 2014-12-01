#include <cstdin>
#include <algorithm>
using namespace std;

const int maxn = 110;
int mat[maxn][maxn];
int index[maxn];

int main()
{
#ifdef LOCAL
    freopen("in", "w", stdin);
#endif
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        int m, n;
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &mat[i][j]);

        for (int i = 0; i < n; i++)
            index[i] = i;
        int ans = 0;
        do {

        }
    }
}
