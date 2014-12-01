#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int cost[55][55], a[55];

int cut(int left, int right)
{
	if (cost[left][right] >= 0)  return cost[left][right];
	if (left + 1 == right)  return 0;
	int lmin = INT_MAX;
	for (int i = left+1; i < right; i++)
		lmin = min(lmin, cut(left, i)+cut(i, right)+a[right]-a[left]);
	return cost[left][right] = lmin;
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int l;
	while (scanf("%d", &l) && l)
	{
		int n;
		scanf("%d", &n);
		a[0] = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		a[n+1] = l;
		memset(cost, -1, sizeof(cost));
		int ans = cut(0, n+1);
		printf("The minimum cutting is %d.\n", ans);
	}
	return 0;
}
