#include <cstdio>
#include <algorithm>
#define MAXN 500000+10
using namespace std;

struct Route
{
	int s, e;
};

Route go[MAXN], back[MAXN];

bool cmp(const Route &a, const Route &b)
{
	if (a.s != b.s)   return a.s < b.s;
	return a.e < b.e;
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	while (scanf("%d", &n) != EOF && n)
	{
		int g_cnt = 0, b_cnt = 0;
		for (int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if (x < y)
			{
				go[g_cnt].s = x;
				go[g_cnt].e = y;
				g_cnt++;
			}
			else
			{
				back[b_cnt].s = y;
				back[b_cnt].e = x;
				b_cnt++;
			}
		}
		if (g_cnt != b_cnt)
		{
			printf("NO\n");
			continue;
		}
		sort(go, go+g_cnt, cmp);
		sort(back, back+b_cnt, cmp);
		bool yes = true;
		for (int i = 0; i < g_cnt; i++)
			if (go[i].s != back[i].s || go[i].e != back[i].e)
			{
				yes = false;
				break;
			}
		if (yes)   printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
