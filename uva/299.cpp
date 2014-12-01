#include <cstdio>

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	int a[60];
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int swap = 0;
		for (int i = n; i > 0; i--)
			for (int j = 0; j+1 < i; j++)
				if (a[j] > a[j+1])
				{
					int t = a[j];
					a[j] = a[j+1];
					a[j+1] = t;
					swap++;
				}
		printf("Optimal train swapping takes %d swaps.\n", swap);
	}
	return 0;
}
