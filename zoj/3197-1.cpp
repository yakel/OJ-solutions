#include <cstdio>
#include <algorithm>
#include <climits>
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
		int start, end = 0;
		int ans = 0;
		int p = 0;  // p points to the interval which is being considered
		// find the maximum interval starting with the same start
		while (end < n)
		{
			start = end + 1;
			int upper = INT_MIN;
			while (p < n && interval[p].l <= start)
			{
				upper = max(upper, interval[p].r);
				p++;
			}
			ans++;
			end = upper;
		}
		printf("%d\n", ans);
	}
	return 0;
}
