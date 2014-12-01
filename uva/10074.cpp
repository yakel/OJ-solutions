#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 110

int mat[MAXN][MAXN], sum[MAXN][MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int m, n, x;
	while (scanf("%d%d", &m, &n) && (m || n))
	{
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				{
					scanf("%d", &x);
					if (x == 0)  x = 1;
					else if (x == 1)  x = -20000;
					mat[i][j] = x;
				}
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				sum[i][j] = mat[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]; 
		int ans = 0;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				for (int p = i; p <= m; p++)
					for (int q = j; q <= n; q++)
					{
						int t = sum[p][q] - sum[p][j-1] - sum[i-1][q] + sum[i-1][j-1];
						ans = max(ans, t);
					}
		printf("%d\n", ans);
	}
	return 0;
}
