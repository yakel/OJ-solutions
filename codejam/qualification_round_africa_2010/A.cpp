#include <cstdio>
#define MAXN 2010

int p[MAXN];

int main()
{
#ifdef LOCAL
	freopen("A-large-practice.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; kase++)
	{
		int c, n;
		scanf("%d%d", &c, &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &p[i]);
		int i, j;
		for (i = 1; i <= n; i++)
			for (j = i+1; j <= n; j++)
				if (p[i] + p[j] == c)  goto s;
s:		printf("Case #%d: %d %d\n", kase, i, j);
	}
	return 0;
}
