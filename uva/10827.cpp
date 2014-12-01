#include <cstdio>
#include <cstring>
#define MAXN 160

int a[MAXN][MAXN], sum[MAXN][MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				scanf("%d", &a[i][j]);
			for (int j = n+1; j <= 2*n; j++)
				a[i][j] = a[i][j-n];
		}
		for (int i = n+1; i <= 2*n; i++)
			for (int j = 1; j <= 2*n; j++)
				a[i][j] = a[i-n][j];
		for (int i = 1; i <= 2*n; i++)
			for (int j = 1; j <= 2*n; j++)
				sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + a[i][j];
		int max = a[1][1];
		for (int i = 1; i <= n; i++)
			for (int p = 0; p < n; p++)
				for (int j = 1; j <= n; j++)
					for (int q = 0; q < n; q++)
					{
						int t = sum[i+p][j+q] - sum[i+p][j-1] - sum[i-1][j+q] + sum[i-1][j-1];
						if (t > max)   max = t;
					}
		printf("%d\n", max);
	}
	return 0;
}

						
