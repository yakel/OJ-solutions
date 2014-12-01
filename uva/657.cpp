#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 60

char pic[MAXN][MAXN];
int vis[MAXN][MAXN], color[MAXN][MAXN];
int ans[3000];
int n, m;

void dice_dye(int x, int y, int c)
{
	if (x < 0 || x >= n || y < 0 || y >= m || color[x][y] || pic[x][y] == '.')  return;
	color[x][y] = c;
	dice_dye(x-1, y, c);
	dice_dye(x, y-1, c);
	dice_dye(x, y+1, c);
	dice_dye(x+1, y, c);
}

void dfs(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || pic[x][y] != 'X')  return;
	vis[x][y] = 1;
	dfs(x-1, y);
	dfs(x, y-1);
	dfs(x, y+1);
	dfs(x+1, y);
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int kase = 0;
	while (scanf("%d%d", &m, &n) && (n || m))
	{
		for (int i = 0; i < n; i++)
			scanf("%s", pic[i]);
		memset(color, 0, sizeof(color));
		int dice_num = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (pic[i][j] != '.' && !color[i][j])
				{
					++dice_num;
					dice_dye(i, j, dice_num);
				}
		memset(ans, 0, sizeof(ans));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (pic[i][j] == 'X' && !vis[i][j])
				{
					dfs(i, j);
					ans[color[i][j]-1]++;
				}
		sort(ans, ans+dice_num);
		printf("Throw %d\n", ++kase);
		for (int i = 0; i < dice_num; i++)
			printf("%d%s", ans[i], (i == dice_num-1) ? "\n" : " ");
		printf("\n");
	}
	return 0;
}
