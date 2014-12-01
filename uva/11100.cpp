#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 10000+10

int a[MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	bool first = true;
	while (scanf("%d", &n) != EOF && n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a+n);
		int k = 1, cnt = 1;
		for (int i = 1; i <= n; i++)
		{
			if (i == n || a[i] != a[i-1])
			{
				if (cnt > k)  k = cnt;
				cnt = 1;
			}
			else  cnt++;
		}
		if (first)  first = false;
		else  printf("\n");
		printf("%d\n", k);
		for (int i = 0; i < k; i++)
		{
			for (int j = i; j < n; j += k)
				printf("%s%d", (i==j) ? "" : " ", a[j]);
			printf("\n");
		}
	}
	return 0;
}

