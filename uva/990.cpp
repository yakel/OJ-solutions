#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int d[35], v[35], dp[35][10000];
vector<int> ans;

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int time, w;
	bool first = true;
	while (scanf("%d%d", &time, &w) != EOF)
	{
		int k = time / (3*w);
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &d[i], &v[i]);
		for (int i = 0; i <= k; i++)
			dp[n+1][i] = 0;
		for (int i = n; i > 0; i--)
			for (int j = 0; j <= k; j++)
			{
				dp[i][j] = dp[i+1][j];
				if (j >= d[i] && dp[i+1][j-d[i]]+v[i] > dp[i][j])
					dp[i][j] = dp[i+1][j-d[i]]+v[i];
			}
		if (first)  first = false;
		else  printf("\n");
		printf("%d\n", dp[1][k]);
		ans.clear();
		for (int i = 1, j = k; i <= n; i++)
			if (j >= d[i] && dp[i][j] == dp[i+1][j-d[i]]+v[i])
			{
				ans.push_back(i);
				j -= d[i];
			}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++)
		{
			int idx = ans[i];
			printf("%d %d\n", d[idx], v[idx]);
		}
	}
	return 0;
}
