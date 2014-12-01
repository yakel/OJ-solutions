#include <cstdio>
#include <algorithm>
#define MAXN 20000+10
using namespace std;

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int h[MAXN], k[MAXN];	//h[] are dragon's heads and k[] are knights
	int n, m;	// n is the number of heads, m is the number of knights
	while (scanf("%d%d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n; i++)   scanf("%d", &h[i]);
		for (int i = 0; i < m; i++)   scanf("%d", &k[i]);
		sort(h, h+n);
		sort(k, k+m);
		int cur = 0, cost = 0;
		for (int i = 0; i < m; i++)		// for each knight
			if (k[i] >= h[cur])
			{
				cost += k[i];
				if (++cur >= n)   break;
			}
		if (cur < n)   printf("Loowater is doomed!\n");
		else printf("%d\n", cost);
	}
	return 0;
}
