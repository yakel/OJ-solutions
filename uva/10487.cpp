#include <cstdio>
#include <cstdlib>
#define MAXN 1000+10
#define MAXM 500000

int a[MAXN], b[MAXM];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	int kase = 0;
	while (scanf("%d", &n) != EOF && n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int k = 0;
		for (int i = 0; i < n-1; i++)
			for (int j = i+1; j < n; j++)
				b[k++] = a[i] + a[j];
		printf("Case %d:\n", ++kase);
		int m;
		scanf("%d", &m);
		while (m--)
		{
			int x;
			scanf("%d", &x);
			int q = 0, min = abs(x - b[0]);
			for (int i = 1; i < k; i++)
				if (abs(b[i] - x) < min)
				{
					min = abs(b[i] - x);
					q = i;
				}
			printf("Closest sum to %d is %d.\n", x, b[q]);
		}
	}
	return 0;
}
