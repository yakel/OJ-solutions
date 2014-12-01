#include <cstdio>
#include <cstring>

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int cnt[10];
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		if (n < 10)
		{
			printf("%d\n", n);
			continue;
		}
		memset(cnt, 0, sizeof(cnt));
		bool ok;
		while (n > 9)
		{
			ok = false;
			for (int i = 9; i >= 2; i--)
				if (n % i == 0)
				{
					ok = true;
					cnt[i]++;
					n /= i;
				}
			if (!ok)   break;
		}
		if (!ok)
		{
			printf("-1\n");
			continue;
		}
		cnt[n]++;
		for (int i = 2; i <= 9; i++)
			for (int j = 0; j < cnt[i]; j++)
				printf("%d", i);
		printf("\n");
	}
	return 0;
}

