#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 100000

int h[MAXN], w[MAXN], lis[MAXN], lds[MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; kase++)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &h[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &w[i]);
		for (int i = 0; i < n; i++)
		{
			lis[i] = lds[i] = w[i];
			for (int j = 0; j < i; j++)
			{
				if (h[i] > h[j])  lis[i] = max(lis[i], lis[j]+w[i]);
				if (h[i] < h[j])  lds[i] = max(lds[i], lds[j]+w[i]);
			}
		}
		int a = 0, b = 0;
		for (int i = 0; i < n; i++)
		{
			a = max(a, lis[i]);
			b = max(b, lds[i]);
		}
		if (a >= b)  printf("Case %d. Increasing (%d). Decreasing (%d).\n", kase, a, b);
		else  printf("Case %d. Decreasing (%d). Increasing (%d).\n", kase, b, a);
	}
	return 0;
}
