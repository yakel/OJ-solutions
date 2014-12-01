#include <cstdio>

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	long long d[35];
	d[0] = 1;
	for (int i = 1; i <= 32; i++)
		d[i] = d[i-1] * 2;
	long long N, L, U;
	while (scanf("%lld%lld%lld", &N, &L, &U) != EOF)
	{
		int a[32] = {0};
		for (int i = 0; N > 0; i++)
		{
			a[i] = N % 2;
			N /= 2;
		}
		long long lmax, lmin, ans = 0;
		for (int i = 31; i >= 0; i--)
		{
			if (a[i] == 0)
			{
				lmin = ans + d[i];
				lmax = ans + d[i+1] - 1;
				if (lmin <= U && lmax >= L)
					ans += d[i];
			}
			else
			{
				lmin = ans;
				lmax = ans + d[i] -1;
				if (lmax < L || lmin > U)
					ans += d[i];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

