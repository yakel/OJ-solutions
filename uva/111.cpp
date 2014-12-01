#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 25

int correct[MAXN], query[MAXN];
int dp[MAXN][MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	int x;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		correct[x] = i;
	}
	while (scanf("%d", &x) != EOF)
	{
		query[x] = 1;
		for (int i = 2; i <= n; i++)
		{
			scanf("%d", &x);
			query[x] = i;
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (correct[i] == query[j])  dp[i][j] = dp[i-1][j-1] + 1;
				else  dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		printf("%d\n", dp[n][n]);
	}
	return 0;
}
