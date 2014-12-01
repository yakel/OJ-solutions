#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 1000+10

double w[MAXN];
int ans[MAXN];

bool cmp(const int a, const int b)
{
	return w[a] > w[b];
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int N;
	scanf("%d", &N);
	while (N--)
	{
		int n;
		scanf("%d", &n);
		int time, fine;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &time, &fine);
			w[i] = 1.0 * fine / time;
		}
		for (int i = 1; i <= n; i++)   ans[i] = i;
		sort(ans+1, ans+n+1, cmp);
		for (int i = 1; i <= n; i++)
			printf("%d%s", ans[i], (i==n)?"\n":" ");
		if (N)   printf("\n");
	}
	return 0;
}
