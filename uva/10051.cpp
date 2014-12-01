#include <cstdio>
#include <cstring>
#define MAXN 500+10

int cube[MAXN][7];
int G[MAXN][MAXN];

bool is_put(int bottom, int top, int k)
{
	// judge if top cube can put on bottom cube when k is the top face of bottom cube
	for (int i = 0; i < 6; i++)
		if (cube[top][i] == cube[bottom][k])   return false;
	return true;
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	while (scanf("%d", &n) != EOF && n)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 6; j++)
				scanf("%d", &cube[i][j]);
		memset(G, 0, sizeof(G));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j < i; j++)
				for (int k = 1; k <= 6; k++)
					if (is_put(i, j, k))
						G[i][j] = k;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				printf("%d ", G[i][j]);
			printf("\n");
		}
	}
	return 0;
}
