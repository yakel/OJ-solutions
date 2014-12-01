#include <cstdio>
#include <cstring>
#define MAXN 30001

const int coin[5] = {1, 5, 10, 25, 50};
long long dp[MAXN];

int main()
{
#ifdef LOCALi
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
	{
		if (dp[n] == 1)  printf("There is only 1 way to produce %d cents change.\n", n);
		else  printf("There are %lld ways to produce %d cents change.\n", dp[n], n);
	}
	return 0;
}
