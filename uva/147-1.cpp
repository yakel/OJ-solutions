#include <cstdio>
#include <cstring>
#define MAXN 6000+10

const int coin[11] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
long long dp[MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	double money;
	int n;
	while (scanf("%lf", &money) != EOF && money)
	{
		n = (int)(money*100 + 0.5) / 5;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int k = 0; k < 11; k++)
			for (int i = 1; i <= n; i++) 
				if (i >= coin[k])
					dp[i] += dp[i-coin[k]];
		printf("%6.2lf%17lld\n", money, dp[n]);
	}
	return 0;
}

