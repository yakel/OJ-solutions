#include <cstdio>
#include <cstring>
#define MAXN 210

bool G[MAXN][MAXN];
int n, color[MAXN];

bool bipartite(int u)
{
	for (int i = 0; i < n; i++)
		if (G[u][i])
		{
			int v = i;
			if (color[u] == color[v])  return false;
			if (!color[v])
			{
				color[v] = 3 - color[u];
				if (!bipartite(v))  return false;
			}
		}
	return true;
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	while (scanf("%d", &n) && n)
	{
		int k;
		scanf("%d", &k);
		int x, y;
		memset(G, 0, sizeof G);
		for (int i = 0; i < k; i++)
		{
			scanf("%d%d", &x, &y);
			G[x][y] = G[y][x] = 1;
		}
		memset(color, 0, sizeof color);
		color[0] = 1;
		if (bipartite(0))  printf("BICOLORABLE.\n");
		else  printf("NOT BICOLORABLE.\n");
	}
	return 0;
}
