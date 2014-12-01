#include <cstdio>
#include <cmath>
#define EPSILON 1e-9

int p, q, r, s, t, u;

double f(double x)
{
	return p*exp(-1.0*x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	while (scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) != EOF)
	{
		if (f(0) < 0 || f(1) > 0)
		{
			printf("No solution\n");
			continue;
		}
		double x = 0, y = 1;
		while (y - x > EPSILON)
		{
			double m = (x+y)/2;
			if (f(m) < 0)   y = m;
			else x = m;
		}
		printf("%.4lf\n", x);
	}
	return 0;
}
