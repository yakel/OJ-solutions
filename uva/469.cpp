#include <cstdio>
#include <cctype>
#include <cstring>
#define MAXN 110

int G[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m, ans;

void dfs(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || !G[x][y])  return;
	vis[x][y] = 1;
	ans++;
	dfs(x-1, y-1);  dfs(x-1, y);  dfs(x-1, y+1);
	dfs(x, y-1);                  dfs(x, y+1);
	dfs(x+1, y-1);  dfs(x+1, y);  dfs(x+1, y+1);
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	getchar();
	char str[150];
	gets(str);
	while (T--)
	{
		n = 0;
		while (gets(str))
		{
			if (isdigit(str[0]))  break;
			m = strlen(str);
			for (int i = 0; i < m; i++)
			{
				if (str[i] == 'L')  G[n][i] =  0;
				else if (str[i] == 'W')  G[n][i] = 1;
			}
			n++;
		}
		int x, y;
		do
		{
			sscanf(str, "%d%d", &x, &y);
			x--;
			y--;
			ans = 0;
			memset(vis, 0, sizeof(vis));
			dfs(x, y);
			printf("%d\n", ans);
		} while (gets(str) && str[0]);
		if (T)  printf("\n");
	}
	return 0;
}
