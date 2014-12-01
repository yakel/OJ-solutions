#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
#define MAXN 1000100

int p[MAXN];

int find(int x)
{
	return p[x] == x ? x : p[x] = find(p[x]);
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	bool first = true;
	while (scanf("%d", &n) != EOF)
	{
		int u, v, w;
		int old_cost = 0;
		for (int i = 0; i < n-1; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			old_cost += w;
		}
		int k;
		scanf("%d", &k);
		vector< pair<int, ii> > EdgeList;
		for (int i = 0; i < k; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			EdgeList.push_back(make_pair(w, make_pair(u, v)));
		}
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			EdgeList.push_back(make_pair(w, make_pair(u, v)));
		}
		sort(EdgeList.begin(), EdgeList.end());
		for (int i = 1; i <= n; i++)
			p[i] = i;
		int new_cost = 0;
		for (int i = 0; i < EdgeList.size(); i++)
		{
			w = EdgeList[i].first;
			u = EdgeList[i].second.first;
			v = EdgeList[i].second.second;
			int pu = find(u);
			int pv = find(v);
			if (pu != pv)
			{
				new_cost += w;
				p[pv] = pu;
			}
		}
		if (first)  first = false;
		else  printf("\n");
		printf("%d\n%d\n", old_cost, new_cost);
	}
	return 0;
}
