#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 1000000+100

int dp[MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	memset(dp, -1, sizeof(dp));
	while (scanf("%d", &n) && n >= 3)
	{
		if (dp[n] == -1)
		{
			int ans = 0;
			for (int i = 1; i <= n; i++)
				for (int j = i+1; j <= n; j++)
				{
					int t = min(n+1, i+j);
					if (t > j + 1)
						ans += t - (j+1);
				}
			dp[n] = ans;
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}
