#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Garment
{
	int size;
	int model[25];
} garment[25];
bool dp[25][210];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int m, c;
		scanf("%d%d", &m, &c);
		for (int i = 1; i <= c; i++)
		{
			scanf("%d", &garment[i].size);
			for (int j = 0; j < garment[i].size; j++)
				scanf("%d", &garment[i].model[j]);
			sort(garment[i].model, garment[i].model+garment[i].size);
		}
		int lowest = 0;
		for (int i = 1; i <= c; i++)
			lowest += garment[i].model[0];
		if (lowest > m)
		{
			printf("no solution\n");
			continue;
		}
		memset(dp, 0, sizeof(dp));
		dp[0][m] = 1;
		for (int i = 1; i <= c; i++)
		{
			for (int j = 0; j <= m; j++)
				if (dp[i-1][j])
				{
					for (int p = 0; p < garment[i].size; p++)
						if (j - garment[i].model[p] >= 0)
							dp[i][j-garment[i].model[p]] = 1;
				}
		}
		int p = 0;
		while (!dp[c][p])  p++;
		printf("%d\n", m-p);
	}
	return 0;
}
