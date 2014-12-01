#include <cstdio>

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int a[7];
	while (scanf("%d%d%d%d%d%d", &a[1], &a[2], &a[3], &a[4], &a[5], &a[6]) != EOF)
	{
		if (!a[1] && !a[2] && !a[3] && !a[4] && !a[5] && !a[6])   break;
		int ans = 0;
		if (a[6] > 0)
		{
			ans += a[6];
		}
		if (a[5] > 0)
		{
			ans += a[5];
			a[1] -= a[5] * 11;
		}
		if (a[4] > 0)
		{
			ans += a[4];
			a[2] -= a[4] * 5;
			if (a[2] < 0)
			{
				a[1] -= -4 * a[2];
				a[2] = 0;
			}
		}
		if (a[3] > 0)
		{
			ans += (a[3]+3) / 4;
			int t = a[3] % 4;
			switch(t)
			{
				case 1:
					a[2] -= 5;
					a[1] -= 7;
					break;
				case 2:
					a[2] -= 3;
					a[1] -= 6;
					break;
				case 3:
					a[2] -= 1;
					a[1] -= 5;
					break;
			}
		}
		if (a[2] > 0)
		{
			ans += (a[2]+8) / 9;
			int t = a[2] % 9 * 4;
			a[1] -= 36 - t;
		}
		if (a[1] > 0)   ans += (a[1]+35) / 36;
		printf("%d\n", ans);
	}
	return 0;
}
