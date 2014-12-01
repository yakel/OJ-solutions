#include <cstdio>
#define MAXN 100000+10

int a[MAXN], tmp[MAXN];
int cnt;

void merge_sort(int l, int r)
{
	if (r-l == 1)  return;
	int mid = l + (r-l)/2;
	merge_sort(l, mid);
	merge_sort(mid, r);
	int p = l, q = mid, k = l;
	while (p < mid || q < r)
	{
		if (q >= r || (p < mid && a[p] < a[q]))
			tmp[k++] = a[p++];
		else
		{
			tmp[k++] = a[q++];
			cnt += mid - p;
		}
	}
	for (int i = l; i < r; i++)
		a[i] = tmp[i];
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	while (scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		cnt = 0;
		merge_sort(0, n);
		if (cnt % 2)  printf("Marcelo\n");
		else  printf("Carlos\n");
	}
	return 0;
}
