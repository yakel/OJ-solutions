#include <cstdio>
#define MAXN 100000+10

int a[MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	while (scanf("%d", &n) != EOF && n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		long long work = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > 0)
			{
				for (int j = i+1; j < n; j++)
					if (a[j] < 0)
					{
						int t = a[i];
						a[i] = a[j] = a[i] + a[j];
						if (a[j] > 0)   a[j] = 0;
						if (a[i] < 0)   a[i] = 0;
						work += (t - a[i]) * (j - i);
						if (a[i] == 0)   break;
					}
			}
			else if (a[i] < 0)
			{
				for (int j = i+1; j < n; j++)
					if (a[j] > 0)
					{
						int t = a[i];
						a[i] = a[j] = a[i] + a[j];
						if (a[j] < 0)   a[j] = 0;
						if (a[i] > 0)   a[i] = 0;
						work += (a[i] - t) * (j - i);
						if (a[i] == 0)   break;
					}
			}
		}
		printf("%lld\n", work);
	}
	return 0;
}
