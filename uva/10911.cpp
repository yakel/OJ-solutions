#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cfloat>
using namespace std;

struct Point
{
	int x, y;
} point[20];
double dp[1<<16+10];

double dis(int a, int b)
{
	int x_diff = point[a].x - point[b].x;
	int y_diff = point[a].y - point[b].y;
	return sqrt(x_diff * x_diff + y_diff * y_diff);
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n, kase = 0;
	char name[30];
	while (scanf("%d", &n) && n)
	{
		n *= 2;
		for (int i = 0; i < n; i++)
			scanf("%s%d%d", name, &point[i].x, &point[i].y);
		dp[0] = 0;
		for (int s = 1; s < (1<<n); s++)
		{
			dp[s] = DBL_MAX;
			int p = 0;
			for ( ; p < n; p++)
				if (s & (1<<p))  break;
			for (int i = p+1; i < n; i++)
				if (s & (1<<i))
					dp[s] = min(dp[s], dis(p, i)+dp[s^(1<<p)^(1<<i)]);
		}
		printf("Case %d: %.2lf\n", ++kase, dp[(1<<n)-1]);
	}
	return 0;
}
