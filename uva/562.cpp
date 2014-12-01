#include <cstdio>
#include <algorithm>
using namespace std;

int dp[110][25100];
int a[110];
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
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		int aver = sum / 2;
		for (int i = 0; i <= aver; i++)
			dp[0][i] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= aver; j++)
			{
				dp[i][j] = dp[i-1][j];
				if (j >= a[i])
					dp[i][j] = max(dp[i][j], dp[i-1][j-a[i]]+a[i]);
			}
		printf("%d\n", sum - dp[n][aver]*2);
	}
	return 0;
}

			
