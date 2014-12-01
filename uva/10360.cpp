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
			int x_min = max(0, x-d);
			int x_max = min(1024, x+d);
			int y_min = max(0, y-d);
			int y_max = min(1024, y+d);
			for (int p = x_min; p <= x_max; p++)
				for (int q = y_min; q <= y_max; q++)
					m[p][q] += num;
		}
		int lmax = 0, x = 0, y = 0;
		for (int i = 0; i <= 1024; i++)
			for (int j = 0; j <= 1024; j++)
				if (m[i][j] > lmax)
				{
					x = i;
					y = j;
					lmax = m[i][j];
				}
		printf("%d %d %d\n", x, y, lmax);
	}
	return 0;
}
