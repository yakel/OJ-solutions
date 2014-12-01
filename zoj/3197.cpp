#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 5000+10

struct Interval
{
	int l, r;
};

Interval interval[MAXN];

bool cmp(const Interval a, const Interval b)
{
	if (a.l != b.l)   return a.l < b.l;
	return a.r < b.r;
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int N;
	scanf("%d", &N);
	while (N--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &interval[i].l, &interval[i].r);
		sort(interval, interval+n, cmp);
		int start = interval[0].l, end = interval[0].r;
		int ans = 1;  // at least need one interval
		int p = 1;  // p points to the interval which is being considered
		// find the maximum interval starting with the same start
		while (p < n && interval[p].l == start)
		{
			end = max(interval[p].r, end);
			p++;
		}
		while (end < n)
		{
			start = end + 1;
			int t = interval[p].r;
			p++;
			while (p < n && interval[p].l <= start)
			{
				t = max(interval[p].r, t);
				p++;
			}
			if (t > end)
			{
				ans++;
				end = t;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
