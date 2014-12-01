#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 1000+10

struct Interval
{
	int l, r, num;
	bool operator < (const Interval& x) const
	{
		return r < x.r;
	}
};
Interval interval[MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	while (scanf("%d", &n) != EOF && n)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &interval[i].l, &interval[i].r);
			interval[i].num = i + 1;
		}
		sort(interval, interval+n);
		int start = interval[0].r;
		printf("%d", interval[0].num);
		for (int i = 0; i < n; i++)
			if (interval[i].l > start)
			{
				start = interval[i].r;
				printf(" %d", interval[i].num);
			}
		printf("\n");
	}
	return 0;
}
