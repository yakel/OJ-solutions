#include <cstdio>

int main()
{
	int T;
	int x, y, n;
	while (scanf("%d", &T) && T)
	{
		while (T--)
		{
			scanf("%d%d%d", &x, &y, &n);
			int ans = x;
			for (int i = 0; i < y-1; i++)
				ans = (ans*x) % n;
			printf("%d\n", ans);
		}
	}
	return 0;
}
