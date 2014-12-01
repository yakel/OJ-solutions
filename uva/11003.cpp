#include <cstdio>
#define MAXN 1010

int weight[MAXN], load[MAXN];
int remain[MAXN]

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	while (scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d%d", weight[i], load[i]);
