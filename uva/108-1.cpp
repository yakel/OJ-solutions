#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
#define MAXN 105

int a[MAXN][MAXN], sum[MAXN][MAXN];

int column_sum(int i, int p, int j)
{
	return sum[p][j] - sum[p][j-1] - sum[i-1][j] + sum[i-1][j-1];
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i <= n; i++) 
			sum[i][0] = sum[0][i] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &a[i][j]);
				sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + a[i][j];
			}
		int gMax = a[1][1];
		for (int i = 1; i <= n; i++)
			for (int p = i; p <= n; p++)
			{
				int sum = 0, minSum = 0, lMax = INT_MIN;
				for (int j = 1; j < n; j++)
				{
					sum += column_sum(i, p, j);
					lMax = max(lMax, sum - minSum);
					minSum = min(minSum, sum);
				}
				if (lMax > gMax)  gMax = lMax;
			}	
		printf("%d\n", gMax);
	}
	return 0;
}
