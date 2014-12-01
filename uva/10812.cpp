#include <cstdio>

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	int s, d, a, b;
	while (n--)
	{
		scanf("%d%d", &s, &d);
		if (s < d || (s+d)%2)
		{
			printf("impossible\n");
			continue;
		}
		a = (s+d) / 2;
		b = s - a;
		printf("%d %d\n", a, b);
	}
	return 0;
}
		
