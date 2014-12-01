#include <cstdio>
#include <cstring>

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	char str[110];
	while (T--)
	{
		scanf("%s", str);
		int cnt[30] = {0};
		for (int i = 0; str[i] != '\0'; i++)
			cnt[str[i]-'a']++;
		int t = 0;
		for (int i = 0; i < 26; i++)
			if (cnt[i] % 2)  t++;
		if (t > 1)
		{
			printf("Impossible\n");
			continue;
		}
		int ans = 0;
		for (int s = 0, e = strlen(str)-1; s < e; s++, e--)
		{
			if (str[s] != str[e])
			{
				int p = s;
				while (str[p] != str[e])  p++;
				int q = e;
				while (str[q] != str[s])  q--;
				if (p - s < e - q)
				{
					ans += p-s;
					for (int i = p; i > s; i--)
						str[i] = str[i-1];
				}
				else
				{
					ans += e-q;
					for (int i = q; i < e; i++)
						str[i] = str[i+1];
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
