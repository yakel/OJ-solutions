#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 1000+10

struct Interval
{
	int l, r;
	bool operator < (const Interval& x) const
	{
		if (r != x.r)   return r < x.r;
		else return l > x.l;
	}
};
Interval interval[MAXN];
bool payed[20000+100];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int k, n;
		scanf("%d%d", &k, &n);
		for (int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			interval[i].l = min(x, y);
			interval[i].r = max(x, y);
		}
		sort(interval, interval+n);
		memset(payed, 0, sizeof(payed));
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int len = interval[i].r - interval[i].l + 1;
			if (len < k)
			{
				for (int j = interval[i].l; j <= interval[i].r; j++)
					if (payed[10000+j] == false)
					{
						payed[10000+j] = true;
						ans++;
					}
			}
			else
			{
				int cnt = 0;
				for (int j = interval[i].l; j <= interval[i].r; j++)
					if (payed[10000+j])   cnt++;
				if (cnt < k)
				{
					int remain = k - cnt;
					int p = interval[i].r;
					while (p >= interval[i].l && remain > 0)
					{
						if (payed[10000+p] == false)
						{
							payed[10000+p] = true;
							ans++;
							remain --;
						}
						p--;
					}
				}
			}
		}
		printf("%d\n", ans);
		for (int i = 0; i < 20005; i++)
			if (payed[i])   printf("%d\n", i-10000);
		if (T)   printf("\n");
	}
	return 0;
}
