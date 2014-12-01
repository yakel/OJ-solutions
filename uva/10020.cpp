#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
#define MAXN 100000+10

struct Line 
{
	int l, r;
};

Line line[MAXN];
int selected[MAXN];

bool cmp(const Line a, const Line b)
{
	if (a.l != b.l)   return a.l < b.l;
	return a.r < b.r;
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	int N;
	scanf("%d", &N);
	while (N--)
	{
		int m;
		scanf("%d", &m);
		int n = 0;  // the number of lines
		while (1)
		{
			scanf("%d%d", &line[n].l, &line[n].r);
			if (line[n].l == 0 && line[n].r == 0)   break;
			n++;
		}
		sort(line, line+n, cmp);
		int p = 0;
		int start, end = 0;
		int ans = 0;
		bool ok = true;
		while (end < m)
		{
			start = end;
			int q = p;
			int upper = INT_MIN;  // the upper bound of interval whose lower bound <= "start" and upper bound is upperest
			int t;
			while (p < n && line[p].l <= start)
			{
				if (line[p].r > upper)
				{
					upper = line[p].r;
					t = p;
				}
				p++;
			}
			if (p == q || upper <= start)  // if p=q, thers isn't line whose left end is less than start, thus can cover
			{
				ok = false;
				break;
			}
			end = upper;
			selected[ans] = t;
			ans++;
		}
		if (ok)
		{
			printf("%d\n", ans);
			for (int i = 0; i < ans; i++)
				printf("%d %d\n", line[selected[i]].l, line[selected[i]].r);
		}
		else printf("0\n");
		if (N)   printf("\n");
	}
	return 0;
}
