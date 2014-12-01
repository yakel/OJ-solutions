#include <cstdio>
#define MAXN 1000000

int p[MAXN];

int find(int x)
{
	return (x == p[x]) ? x : p[x] = find(p[x]);
}

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
		getchar();
		for (int i = 1; i <= n; i++)
			p[i] = i;
		char str[10000];
		int success = 0, fail = 0;
		while (gets(str))
		{
			if (str[0] == 0)  break;
			int a, b;
			sscanf(str+1, "%d%d", &a, &b);
			int pa = find(a);
			int pb = find(b);
			if (str[0] == 'c')
			{
				if (pa != pb)  p[pb] = pa;
			}
			else if (str[0] == 'q')
			{
				if (pa != pb)  fail++;
				else  success++;
			}
		}
		printf("%d,%d\n", success, fail);
		if (T)  printf("\n");
	}
	return 0;
}
