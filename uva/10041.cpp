#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define MAXN 500+10

int a[MAXN];

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
		sort(a, a+n);
		int median = (n-1) / 2;
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += abs(a[i] - a[median]);
		printf("%d\n", sum);
	}
	return 0;
}
