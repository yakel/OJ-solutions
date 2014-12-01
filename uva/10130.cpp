#include <cstdio>
#include <algorithm>
using namespace std;

int p[1010], w[1010];
int dp[1010][35];

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
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &p[i], &w[i]);
		int k, sum = 0;
		scanf("%d", &k);
		while (k--)
		{
			int x;
			scanf("%d", &x);
			for (int i = 0; i <= 30; i++)
				dp[0][i] = 0;
			for (int i = 1; i <= n; i++)
				for (int j = 0; j <= x; j++)
				{
					dp[i][j] = dp[i-1][j];
					if (j >= w[i])
						dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+p[i]);
				}
			sum += dp[n][x];
		}
		printf("%d\n", sum);
	}
	return 0;
}
