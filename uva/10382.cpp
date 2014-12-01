#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAXN 10000+10

struct Interval
{
	int pos, r;
	double s, e;
	bool operator < (const Interval& in) const
	{
		return s < in.s;
	}
};
Interval interval[MAXN];

double cover(double c, double a)
{
	return sqrt(c*c - a*a);
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n, l, w;
	while (scanf("%d%d%d", &n, &l, &w) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &interval[i].pos, &interval[i].r);
			double t = cover(interval[i].r, w/2.0);
			interval[i].s = interval[i].pos - t;
			interval[i].e = interval[i].pos + t;
		}
		sort(interval, interval+n);
		double  start = 0;
		int p = 0, ans = 0; 
		bool ok = true;
		while (start < l)
		{
			int q = p;
			double lmax = -1;
			while (p < n && interval[p].s <= start)
			{
				if (interval[p].e > lmax)   lmax = interval[p].e;
				p++;
			}
			if (p == q || lmax <= start)
			{
				ok = false;
				break;
			}
			ans++;
			start = lmax;
		}
		if (ok)   printf("%d\n", ans);
		else   printf("-1\n");
	}
	return 0;
}
