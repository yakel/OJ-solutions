#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#define MAXN 1000+10

int a[MAXN];
bool even[MAXN];

int main()
{
#ifdef LOCAL
	//freopen("in", "r", stdin);
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; kase++)
	{
		int n;
		scanf("%d", &n);
		memset(even, 0, sizeof(even));
		vector<int> evens, odds;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			if (a[i] % 2 == 0)
			{
				even[i] = 1;
				evens.push_back(a[i]);
			}
			else  odds.push_back(a[i]);
		}
		sort(odds.begin(), odds.end());
		sort(evens.begin(), evens.end(), greater<int>());
		int p = 0, q = 0;
		vector<int> ans;
		for (int i = 0; i < n; i++)
		{
			if (!even[i])  ans.push_back(odds[p++]);
			else  ans.push_back(evens[q++]);
		}
		printf("Case #%d:", kase);
		for (int i = 0; i < n; i++)
			printf(" %d", ans[i]);
		printf("\n");
	}
	return 0;
}
