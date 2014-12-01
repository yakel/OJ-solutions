#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int f, r;
	int front[12], rear[12];
	double ratio[110];
	while (scanf("%d", &f) && f)
	{
		scanf("%d", &r);
		for (int i = 0; i < f; i++)
			scanf("%d", &front[i]);
		for (int i = 0; i < r; i++)
			scanf("%d", &rear[i]);
		int k = 0;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < f; j++)
				ratio[k++] = rear[i] * 1.0 / front[j];
		sort(ratio, ratio+k);
		double lmax = 0;
		for (int i = 1; i < k; i++)
		{
			double t = ratio[i] / ratio[i-1];
			if (t > lmax)  lmax = t;
		}
		printf("%.2lf\n", lmax);
	}
	return 0;
}
