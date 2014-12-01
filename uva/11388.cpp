#include <cstdio>
typedef unsigned long long ull;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		ull g, l;
		scanf("%llu%llu", &g, &l);
		ull t = g * l, a, b;
		bool ok = false;
		for (a = g; a*a <= t; a += g)
			if (t % a == 0)
			{
				b = t / a;
				if (b % g == 0)
				{
					ok = true;
					break;
				}
			}
		if (ok)  printf("%llu %llu\n", a, b);
		else  printf("-1\n");
	}
	return 0;
}
