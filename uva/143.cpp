#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define EPS 1e-9

double area2(double x0, double y0, double x1, double y1, double x2, double y2)
{
	return fabs(x0*y1 + x2*y0 + x1*y2 - x2*y1 - x0*y2 - x1*y0);
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	double x1, x2, x3, y1, y2, y3;
	while (scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3) != EOF)
	{
		if ((x1 || x2 || x3 || y1 || y2 || y3) == 0)  break;
		int x_min = ceil(min(x1, min(x2, x3)));
		x_min = max(1, x_min);
		int x_max = max(x1, max(x2, x3));
		x_max = min(99, x_max);
		int y_min = ceil(min(y1, min(y2, y3)));
		y_min = max(1, y_min);
		int y_max = max(y1, max(y2, y3));
		y_max = min(99, y_max);
		double S = area2(x1, y1, x2, y2, x3, y3);
		int ans = 0;
		for (int x = x_min; x <= x_max; x++)
			for (int y = y_min; y <= y_max; y++)
			{
				double S1 = area2(x1, y1, x2, y2, x, y);
				double S2 = area2(x2, y2, x3, y3, x, y);
				double S3 = area2(x3, y3, x1, y1, x, y);
				if (fabs(S-S1-S2-S3) < EPS)  ans++;
			}
		printf("%4d\n", ans);
	}
	return 0;
}

