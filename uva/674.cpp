#include <cstdio>
#include <cstring>
#define MAXN 7490

int dp[MAXN];
const int coin[5] = {1, 5, 10, 25, 50};

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int k = 0; k < 5; k++)
		for (int i = 1; i < MAXN; i++)
			if (i >= coin[k])
				dp[i] += dp[i-coin[k]];
	int n;
	while (scanf("%d", &n) != EOF)
		printf("%d\n", dp[n]);
	return 0;
}
