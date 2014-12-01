#include <cstdio>
#include <set>
using namespace std;

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	multiset<int> urn;
	while (scanf("%d", &n) && n)
	{
		urn.clear();
		int ans = 0;
		while (n--)
		{
			int k;
			scanf("%d", &k);
			int x;
			for (int i = 0; i < k; i++)
			{
				scanf("%d", &x);
				urn.insert(x);
			}
			ans += (*(--urn.end()) - *urn.begin());
			urn.erase(urn.begin());
			urn.erase(--urn.end());
		}
		printf("%d\n", ans);
	}
	return 0;
}
