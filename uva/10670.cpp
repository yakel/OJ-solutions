#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 100+10

struct Agency
{
	char name[20];
	int cost;
};
Agency agency[MAXN];

bool cmp (const Agency& a, const Agency& b)
{
	if (a.cost != b.cost)   return a.cost < b.cost;
	else return strcmp(a.name, b.name) < 0;
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; kase++)
	{
		int n, m, l;
		scanf("%d%d%d", &n, &m, &l);
		getchar();
		for (int i = 0; i < l; i++)
		{
			int cnt = 0;
			char ch = getchar();
			while (isupper(ch))
			{
				agency[i].name[cnt++] = ch;
				ch = getchar();
			}
			agency[i].name[cnt] = '\0';
			int a, b;
			scanf("%d,%d", &a, &b);
			getchar();
			agency[i].cost = 0;
			int remain  = n;
			while (remain > m)
			{
				int half = remain / 2;
				if (half < m)
				{
					agency[i].cost += (remain - m) * a;
					remain = m;
				}
				else
				{
					int t = a * (remain - half);  // the cost reducing from remain to half with A
					if (t < b)   agency[i].cost += t;
					else agency[i].cost += b;
					remain = half;
				}
			}
		}
		sort(agency, agency+l, cmp);
		printf("Case %d\n", kase);
		for (int i = 0; i < l; i++)
			printf("%s %d\n", agency[i].name, agency[i].cost);
	}
	return 0;
}
