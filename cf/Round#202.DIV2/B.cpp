#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
#define MAXN 10

struct Digit
{
	int cost;
	double w;
	bool operator < (const &Digit d) const
	{
		return w < d.w;
	}
} digits[MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int v;
	while (scanf("%d", &v) != EOF)
	{
		int min_cost = INT_MAX;
		for (int i = 1; i <= 9; i++)
		{
			scanf("%d", &digits[i].cost);
			digits[i].w = digits[i].cost * 1.0 / i;
			min_cost = min(min_cost, digits[i].cost);
		}
		int k = v / min_cost; // k is the digit of the biggest number
		sort(digits+1, digits+10);
		int cnt[10] = {0};
		for (in
