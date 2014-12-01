#include <cstdio>
#include <cstdlib>
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
		for (int i = 0; i < n-1; i++)
		{
			a[i+1] += a[i];
			work += abs(a[i]);
		}
		printf("%lld\n", work);
	}
	return 0;
}
