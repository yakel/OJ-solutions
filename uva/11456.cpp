#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 2010

int a[MAXN], lis[MAXN], lds[MAXN];

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
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int i  = n-1; i >= 0; i--)
		{
			lis[i] = lds[i] = 1;
			for (int j = i+1; j < n; j++)
			{
				if (a[i] < a[j])  lis[i] = max(lis[i], lis[j]+1);
				if (a[i] > a[j])  lds[i] = max(lds[i], lds[j]+1);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = max(ans, lis[i]+lds[i]-1);
		printf("%d\n", ans);
	}
	return 0;
}
