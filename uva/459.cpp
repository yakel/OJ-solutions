#include <cstdio>
#include <cstring>
#define MAXN 30

bool G[MAXN][MAXN];
int p[MAXN];

int find(int x)
{
	return x == p[x] ? x : p[x]=find(p[x]);
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	getchar();
	char str[20];
	gets(str);
	while (T--)
	{
		memset(G, 0, sizeof(G));
		gets(str);
		int n = str[0] - 'A' + 1;
		for (int i = 0; i < n; i++)
			p[i] = i;
		int cnt = n;
		while (gets(str))
		{
			if (str[0] == 0)  break;
			int a = str[0] - 'A';
			int b = str[1] - 'A';
			int pa = find(a);
			int pb = find(b);
			if (pa != pb)
			{
				p[pb] = pa;
				cnt--;
			}
		}
		printf("%d\n", cnt);
		if (T)  printf("\n");
	}
	return 0;
}
