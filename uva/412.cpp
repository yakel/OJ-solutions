#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	int a[60];
	while (scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int cnt = 0;
		for (int i = 0; i < n-1; i++)
			for (int j = i+1; j < n; j++)
			{
				int lmax = max(a[i], a[j]);
				int lmin = min(a[i], a[j]);
				if (gcd(lmax, lmin) == 1)
					cnt++;
			}
		if (cnt == 0)
		{
			printf("No estimate for this data set.\n");
			continue;
		}
		int total = n*(n-1)/2;
		printf("%.6lf\n", sqrt(6.0*total/cnt));
	}
	return 0;
}
