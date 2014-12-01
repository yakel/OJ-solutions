#include <cstdio>

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF)
	{
		int ans = n, butt = n;
		while (butt >= k)
		{
			int t = butt / k;
			butt %= k;
			ans += t;
			butt += t;
		}
		printf("%d\n", ans);
	}
	return 0;
}
