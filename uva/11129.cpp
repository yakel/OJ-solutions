#include <cstdio>
#define MAXN 10000+10

int a[MAXN], tmp[MAXN];

void divide(int low, int high)
{
	if (high - low < 3)   return;
	int p = 0;
	for (int i = low; i < high; i += 2)
		tmp[p++] = a[i];
	for (int i = low+1; i < high; i += 2)
		tmp[p++] = a[i];
	for (int i = 0; i < p; i++)
		a[low+i] = tmp[i];
	int mid = (low + high - 1) / 2;
	divide(low, mid+1);
	divide(mid+1, high);
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	while (scanf("%d", &n) != EOF && n)
	{
		for (int i = 0; i < n; i++)
			a[i] = i;
		divide(0, n);
		printf("%d:", n);
		for (int i = 0; i < n; i++)
			printf(" %d", a[i]);
		printf("\n");
	}
	return 0;
}
