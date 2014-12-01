#include <cstdio>
#define MAXN 1000000+100

int a[MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF)
	{
		for (int i = 0; i < n; i++)  scanf("%d", &a[i]);
		int i = 0, j = n-1;
		bool ok = false;
		while (1)
		{
			if (i >= j)  break;
			if (a[i] + a[j] == k)  
			{
				ok = true;
				break;
			}
			else if (a[i] + a[j] < k)  i++;
			else  j--;
		}
		if (ok)  printf("%d %d\n", a[i], a[j]);
		else  printf("-1 -1\n");
	}
	return 0;
}

