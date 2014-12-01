#include <cstdio>
#include <cstring>
#define MAXN 256+4
#define LINEN 10000+10

int cnt[MAXN], value[MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int k;
		scanf("%d", &k);
		getchar();
		memset(value, 0, sizeof(value));
		while (k--)
		{
			char ch;
			int v;
			scanf("%c%d", &ch, &v);
			getchar();
			value[ch] = v;
		}
		int m;
		scanf("%d", &m);
		getchar();
		char str[LINEN];
		memset(cnt, 0, sizeof(cnt));
		while (m--)
		{
			gets(str);
			int len = strlen(str);
			for (int i = 0; i < len; i++)
				cnt[str[i]]++;
		}
		int money = 0;
		for (int i = 0; i <= 255; i++)
			money += cnt[i]*value[i];
		int dollar = money / 100;
		int cent = money % 100;
		printf("%d.%02d$\n", dollar, cent);
	}
	return 0;
}
