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
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		int r1, c1, r2, c2;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				mat[i][j] = 1;
		while (k--)
		{
			scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
			for (int i = r1; i <= r2; i++)
				for (int j = c1; j <= c2; j++)
					mat[i][j] = -20000;
		}
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				sum[i][j] = mat[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]; 
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int p = i; p <= n; p++)
					for (int q = j; q <= n; q++)
					{
						int t = sum[p][q] - sum[p][j-1] - sum[i-1][q] + sum[i-1][j-1];
						ans = max(ans, t);
					}
		printf("%d\n", ans);
	}
	return 0;
}
