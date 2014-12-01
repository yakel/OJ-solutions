#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAXN 10000+10

struct Point
{
	double x, y;
};
Point point[MAXN], tmp[MAXN];

bool cmp1(const Point& a, const Point& b)
{
	if (a.x != b.x)  return a.x < b.x;
	return a.y < b.y;
}

bool cmp2(const Point& a, const Point& b)
{
	if (a.y != b.y)  return a.y < b.y;
	return a.x < b.x;
}

double dis(const Point& a, const Point& b)
{
	double t1 = (a.x - b.x) * (a.x - b.x);
	double t2 = (a.y - b.y) * (a.y - b.y);
	return sqrt(t1+t2);
}

double conquer(int left, int right)
{
	if (left == right)  return 10010;
	if (right - left == 1)  return dis(point[left], point[right]);
	int mid = (left + right) / 2;
	double left_min = conquer(left, mid);
	double right_min = conquer(mid+1, right);
	double d = min(left_min, right_min);
	int cnt = 0;
	for (int i = left; i <= right; i++)
		if (fabs(point[i].x-point[mid].x) < d)
			tmp[cnt++] = point[i];
	sort(tmp, tmp+cnt, cmp2);
	for (int i = 0; i < cnt; i++)
		for (int j = i+1; j < i+7 && j < cnt; j++)
		{
			double t = dis(tmp[i], tmp[j]);
			if (t < d)  d = t;
		}
	return d;
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	while (scanf("%d", &n) != EOF && n)
	{
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &point[i].x, &point[i].y);
		sort(point, point+n, cmp1);
		double ans = conquer(0, n-1);
		if (ans > 10000)  printf("INFINITY\n");
		else  printf("%.4lf\n", ans);
	}
	return 0;
}
