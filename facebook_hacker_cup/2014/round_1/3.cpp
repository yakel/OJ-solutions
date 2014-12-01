#include <cstdio>
#include <cstring>

const int maxn = 500+10;
const int dir[4][2] = { -1, 0, 0, -1, 0, 1, 1, 0 };
int n, m, num, lmax;
char matrix[maxn][maxn];
bool vis[maxn][maxn];

void read_data()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", matrix[i]);
}

bool inside(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m)  return true;
    return false;
}

bool can_place(int x, int y)
{
    if (!inside(x, y))  return false;
    if (matrix[x][y] == '#' || vis[x][y])  return false;
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int dx = x + dir[i][0], dy = y + dir[i][1];
        if (inside(dx, dy) && matrix[dx][dy] == '*')
            cnt ++;
    }
    if (cnt > 1)  return false;
    return true;
}

void dfs(int x, int y)
{
    if (can_place(x, y)) {
        matrix[x][y] = '*';
        vis[x][y] = 1;
        num++;
        if (num > lmax)  lmax = num;
        dfs(x-1, y);
        dfs(x, y-1);
        dfs(x, y+1);
        dfs(x+1, y);
        num--;
        vis[x][y] = 0;
        matrix[x][y] = '.';
    }
}

int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("3.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        read_data();
        num = lmax = 0;
        memset(vis, 0, sizeof(vis));
        dfs(0, 0);
        printf("Case #%d: %d\n", kase, lmax);
    }
    return 0;
}
