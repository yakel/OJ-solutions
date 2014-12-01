#include <cstdio>

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int cnt = 0;
		while (n)
		{
			cnt++;
			n &= (n-1);
		}
		printf("%d\n", cnt);
	}
	return 0;
}
