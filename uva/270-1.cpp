// the version is for poj 1118
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAXN 700+10
#define PRECISION 10e-9

struct Point
{
	int x, y;
};

Point point[MAXN];
double slope[MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	while (scanf("%d", &n) != EOF && n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d%d", &point[i].x, &point[i].y);
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int zero_cnt = 0, k = 0;
			for (int j = 0; j < n; j++)
				if (i != j)
				{
					if (point[i].x == point[j].x)   zero_cnt++;
					else
					{
						slope[k] = 1.0 * (point[j].y - point[i].y) / (point[j].x - point[i].x);
						k++;
					}
				}
			sort(slope, slope+k);
			int same_cnt = 1, maxl = 1;
			for (int i = 1; i <= k; i++)
			{
				if (i < k && fabs(slope[i] - slope[i-1]) < PRECISION)
				{
					same_cnt++;
				}
				else 
				{
					maxl = max(maxl, same_cnt);
					same_cnt = 1;
				}
			}
			maxl = max(maxl, zero_cnt);
			ans = max(ans, maxl+1);
		}
		printf("%d\n", ans);
	}
	return 0;
}
