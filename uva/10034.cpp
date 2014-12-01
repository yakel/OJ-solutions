#include <cstdio>
#include <algorithm>
#include <cmath>
#define square(x) (x)*(x)
#define MAXN 10000
#define POINTN 100+10
using namespace std;

double w[MAXN], point[POINTN][2];	// the weight of edge
int u[MAXN], v[MAXN], r[MAXN], p[MAXN]; 
// u[i] and v[i] save the end points of the ith edge seperately, r[i] save the ith edge of non-decreasing ordered edges

double distance(double x1, double y1, double x2, double y2)
{
	double t = square(x2-x1) + square(y2-y1);
	return sqrt(t);
}

int cmp(const int i, const int j)
{
	return w[i] < w[j];
}

int find(int x)
{
	return p[x] == x ? x : p[x] = find(p[x]);
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int N;
	scanf("%d", &N);
	bool first = true;
	while (N--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &point[i][0], &point[i][1]);
		int k = 0;	// the size of edge
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
			{
				w[k] = distance(point[i][0], point[i][1], point[j][0], point[j][1]);
				u[k] = i;
				v[k] = j;
				k++;
			}
		double ans = 0;
		for (int i = 0; i < n; i++)   p[i] = i;
		for (int i = 0; i < k; i++)   r[i] = i;
		sort(r, r+k, cmp);	// sort the edge
		for (int i = 0; i < k; i++)
		{
			int e = r[i];
			int x = find(u[e]);
			int y = find(v[e]);
			if (x != y)
			{
				ans += w[e];
				p[x] = y;
			}
		}
		if (first)   first = false;
		else printf("\n");
		printf("%.2lf\n", ans);
	}
	return 0;
}
