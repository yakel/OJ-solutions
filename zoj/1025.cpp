#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 5000+10

struct Wooden
{
	int l, w;
	bool operator < (const Wooden& x) const
	{
		if (l != x.l)   return l < x.l;
		else return w < x.w;
	}
};
Wooden wooden[MAXN];
bool processed[MAXN];

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
		for (int i = 0; i < n; i++)
			scanf("%d%d", &wooden[i].l, &wooden[i].w);
		sort(wooden, wooden+n);
		int time = 0;
		memset(processed, 0, sizeof(processed));
		int remain = n;
		while (remain > 0)
		{
			time++;
			int prel = -1, prew = -1;
			for (int i = 0; i < n; i++)
				if (!processed[i] && wooden[i].l >= prel && wooden[i].w >= prew)
				{
					processed[i] = true;
					remain--;
					prel = wooden[i].l;
					prew = wooden[i].w;
				}
		}
		printf("%d\n", time);
	}
	return 0;
}
