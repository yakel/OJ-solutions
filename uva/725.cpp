#include <cstdio>
#include <cstring>

bool vis[10];
char str[15];

bool check(int a, int b)
{
	sprintf(str, "%05d%05d", a, b);
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < 10; i++)
	{
		if (vis[str[i]-'0'])  return false;
		vis[str[i]-'0'] = true;
	}
	return true;
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	bool first = true;
	while (scanf("%d", &n) && n)
	{
		bool exist = false;
		if (first)  first = false;
		else  printf("\n");
		for (int i = 1234; i <= 98765; i++)
		{
			int ans;
			if (i % n == 0)
			{
				ans = i / n;
				if (ans < 1234)  continue;
				if (check(i, ans))
				{
					exist = true;
					printf("%05d / %05d = %d\n", i, ans, n);
				}
			}
		}
		if (!exist)  printf("There are no solutions for %d.\n", n);
	}
	return 0;
}
