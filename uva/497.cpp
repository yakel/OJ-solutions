#include <cstdio>
#include <cstring>
#define MAXN 100000

int a[MAXN], lis[MAXN], pre[MAXN];

void print_lis(int p)
{
	if (pre[p] != -1)  print_lis(pre[p]);
	printf("%d\n", a[p]);
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	getchar();
	char str[100];
	gets(str);
	while (T--)
	{
		int n = 0;
		while (gets(str) && str[0])
		{
			sscanf(str, "%d", &a[n]);
			n++;
		}
		memset(pre, -1, sizeof(pre));
		for (int i = 0; i < n; i++)
		{
			lis[i] = 1;
			for (int j = 0; j < i; j++)
				if (a[i] > a[j] && lis[j]+1 > lis[i])
				{
					lis[i] = lis[j] + 1;
					pre[i] = j;
				}
		}
		int p = 0;
		for (int i = 1; i < n; i++)
			if (lis[i] > lis[p])  p = i; 
		printf("Max hits: %d\n", lis[p]);
		print_lis(p);
		if (T)  printf("\n");
	}
	return 0;
}
