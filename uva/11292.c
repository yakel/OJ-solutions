#include <stdio.h>
#include <stdlib.h>
#define MAXN 20000+10

int cmp(const void *_a, const void *_b)
{
	int *a = (int*)_a;
	int *b = (int*)_b;
	return *a - *b;
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int h[MAXN], k[MAXN];	/* h[] are dragon's heads and k[] are knights */
	int n, m, i;	/* n is the number of heads, m is the number of knights */
	int cur, cost;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0) break;
		for (i = 0; i < n; i++)   scanf("%d", &h[i]);
		for (i = 0; i < m; i++)   scanf("%d", &k[i]);
		qsort(h, n, sizeof(int), cmp);
		qsort(k, m, sizeof(int), cmp);
		cur = 0;
		cost = 0;
		for (i = 0; i < m; i++)		/* for each knight */
			if (k[i] >= h[cur])
			{
				cost += k[i];
				if (++cur >= n)   break;
			}
		if (cur < n)   printf("Loowater is doomed!\n");
		else printf("%d\n", cost);
	}
	return 0;
}
