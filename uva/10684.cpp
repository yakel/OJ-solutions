#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	while (scanf("%d", &n) && n)
	{
		int sum = 0, lmin = 0;
		int x, ans = -10000;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			sum += x;
			ans = max(ans, sum-lmin);
			lmin = min(sum, lmin);
		}
		if (ans > 0)  printf("The maximum winning streak is %d.\n", ans);
		else  printf("Losing streak.\n");
	}	
	return 0;
}
