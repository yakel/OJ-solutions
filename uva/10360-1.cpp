#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 1030

int m[MAXN][MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int d;
		scanf("%d", &d);
		int n;
		scanf("%d", &n);
		memset(m, 0, sizeof(m));
		for (int i = 0; i < n; i++)
		{
			int x, y, num;
			scanf("%d%d%d", &x, &y, &num);
			m[x][y] = num;
		}
		int lmax = 0, x = 0, y = 0;
		for (int i = 0; i <= 1024; i++)
			for (int j = 0; j <= 1024; j++)
			{
				int x_min = max(0, i-d);
				int x_max = min(1024, i+d);
				int y_min = max(0, j-d);
				int y_max = min(1024, j+d);
				int sum = 0;
				for (int p = x_min; p <= x_max; p++)
					for (int q = y_min; q <= y_max; q++)
						sum += m[p][q];
				if (sum > lmax)
				{
					lmax = sum;
					x = i;
					y = j;
				}
			}
		printf("%d %d %d\n", x, y, lmax);
	}
	return 0;
}
