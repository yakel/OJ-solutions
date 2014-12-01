#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAXN 1000000+10

int ant[MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int N;
	scanf("%d", &N);
	while (N--)
	{
		int l, n;
		scanf("%d%d", &l, &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &ant[i]);
		sort(ant, ant+n);
		int latest = max (l-ant[0], ant[n-1]);
		double mid = 1.0 * l / 2;
		double lmin = fabs(ant[0]-mid);;  // lmin save the nearest distance from the half of the pole
		int p = 0;
		for (int i = 1; i < n; i++)
			if (fabs(ant[i]-mid) < lmin)
			{
				lmin = fabs(ant[i]-mid);
				p = i;
			}
		int earliest = min(ant[p], l-ant[p]);
		printf("%d %d\n", earliest, latest);
	}
	return 0;
}
