#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 310

int dp[MAXN][MAXN];
int x[50], y[50];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, target;
		scanf("%d%d", &n, &target);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &x[i], &y[i]);
		for (int i = 0;  i <= target; i++)
			for (int j = 0; j <= target; j++)
				dp[i][j] = INT_MAX;
		dp[0][0] = 0;
		for (int i = 0; i <= target; i++)
			for (int j = 0; j <= target; j++)
				for (int k = 0; k < n; k++)
					if (i-x[k] >= 0 && j-y[k]>= 0 && dp[i-x[k]][j-y[k]] != INT_MAX)
						dp[i][j] = min(dp[i][j], dp[i-x[k]][j-y[k]]+1);
		int ans = INT_MAX;
		int t = target * target;
		for (int i = 0; i <= target; i++)
			for (int j = 0; j <= target; j++)
				if (i*i + j*j == t && dp[i][j] != INT_MAX)
					ans = min(ans, dp[i][j]);
		if (ans != INT_MAX)  printf("%d\n", ans);
		else  printf("not possible\n");
	}
	return 0;
}
