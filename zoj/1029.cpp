// unfinished
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 200+10

struct Interval
{
	int l, r;
	bool operator < (const Interval& x) const
	{
		if (r != x.r)   return r < x.r;
		else return l < x.l;
	}
};
Interval interval[MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int x, y;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			interval[i].l = (min(x, y)+1) / 2;
			interval[i].r = (max(x, y)+1) / 2;
		}
		sort(interval, interval+n);
		int p = 0, start = 0;
		while (start < 200)
		{
			while (p < n && interval[p].l < start)   p++;
			start = interval[p].r;
			p++;
		}
