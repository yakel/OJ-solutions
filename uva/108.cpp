#include <cstdio>
#define MAXN 105

int a[MAXN][MAXN], sum[MAXN][MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &a[i][j]);
		for (int i = 0; i <= n; i++) 
			sum[i][0] = sum[0][i] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + a[i][j];
		int max = a[1][1];
		for (int i = 1; i <= n; i++)
			for (int p = i; p <= n; p++)
				for (int j = 1; j <= n; j++)
					for (int q = j; q <= n; q++)
					{
						int t = sum[p][q] - sum[p][j-1] - sum[i-1][q] + sum[i-1][j-1];
						if (t > max)   max = t;
					}
		printf("%d\n", max);
	}
	return 0;
}
