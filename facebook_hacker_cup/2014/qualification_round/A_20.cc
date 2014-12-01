#include <cstdio>
#include <cstring>
#include <cmath>

const int maxn = 25;
const double esp = 1e-6;
int matrix[maxn][maxn];
bool vis[maxn][maxn];
int n, black_cnt;

void dfs(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n || !matrix[x][y] || vis[x][y])  return;
    vis[x][y] = 1;
    dfs(x-1, y);
    dfs(x, y-1);
    dfs(x, y+1);
    dfs(x+1, y);
}

void build_map()
{
   char str[maxn];
   black_cnt = 0;
   for (int i = 0; i < n; ++i) {
       scanf("%s", str);
       for (int j = 0; j < n; ++j) {
           if (str[j] == '#') {
               matrix[i][j] = 1;
               black_cnt++;
           }
           else if (str[j] == '.') matrix[i][j] = 0;
       }
   }
}

int block_counter()
{
    int block_cnt = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (matrix[i][j] && !vis[i][j]) {
                block_cnt++;
                dfs(i, j);
            }
    return block_cnt;
}

bool is_square(int x, int y, int d)
{
    for (int i = x; i < x+d; ++i)
        for (int j = y; j < y+d; ++j)
            if (matrix[i][j] == 0)  return false;
    return true;
}

bool is_sqrted(int x)
{
    double res = sqrt(x);
    int t = (int)(res+0.5);
    return fabs(res-t) < esp;
}

bool judge()
{
    if (block_counter() > 1)  return false;
    if (!is_sqrted(black_cnt))  return false;
    int d = (int)(sqrt(black_cnt)+0.5);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (matrix[i][j]) {
                if (is_square(i, j, d))  return true;
                else  return false;
            }
}

int main()
{
#ifdef LOCAL
    freopen("square_detector.txt", "r", stdin);
    freopen("A.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        scanf("%d", &n);
        build_map();
        if (judge())  printf("Case #%d: YES\n", kase);
        else  printf("Case #%d: NO\n", kase);
    }
    return 0;
}
