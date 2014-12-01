#include <cstdio>

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
		int x, sum = 0, nicest = 0, len = 0;
		int p = 0, s, e;
		for (int i = 0; i < n-1; i++)
		{
			scanf("%d", &x);
			sum += x;
			if (sum < 0)
			{
				sum = 0;
				p = i + 1;
			}
			else if (sum > nicest || (sum == nicest && i-p+1  > len))
			{
				s = p;
				e = i;
				len = i - p + 1;
				nicest = sum;
			}
		}
		if (nicest > 0)   printf("The nicest part of route %d is between stops %d and %d\n", kase, s+1, e+2);
		else   printf("Route %d has no nice parts\n", kase);
	}
	return 0;
}
