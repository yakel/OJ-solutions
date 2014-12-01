#include <cstdio>
#define MAXN 1000+10

int a[MAXN][MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		int target;
		scanf("%d", &target);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &a[i][j]);
		int x = 0, y = n-1;
		bool ok = false;
		while (x < m && y >= 0)
		{
			if (a[x][y] == target)
			{
				ok = true;
				break;
			}
			else if (a[x][y] > target)  y--;
			else x++;
		}
		if (ok)  printf("Yes\n");
		else  printf("No\n");
	}
	return 0;
}
