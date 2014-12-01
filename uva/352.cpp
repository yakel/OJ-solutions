#include <cstdio>
#include <cstring>
#define MAXN 30

int n;
int G[MAXN][MAXN];
bool vis[MAXN][MAXN];

void dfs(int i, int j)
{
	if (i < 0 || i >= n || j < 0 || j >= n || vis[i][j] || !G[i][j])  return;
	vis[i][j] = 1;
	dfs(i-1, j-1);  dfs(i-1, j);  dfs(i-1, j+1);
	dfs(i, j-1);                  dfs(i, j+1);
	dfs(i+1, j-1);  dfs(i+1, j);  dfs(i+1, j+1);
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int kase = 0;
	char str[50];
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str);
			for (int j = 0; j < n; j++)
				G[i][j] = str[j] - '0';
		}
		memset(vis, 0, sizeof(vis));
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (!vis[i][j] && G[i][j]) 
				{
					dfs(i, j);
					cnt++;
				}
			}
		printf("Image number %d contains %d war eagles.\n", ++kase, cnt); 
	}
	return 0;
}
