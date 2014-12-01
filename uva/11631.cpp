#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
#define MAXN 200100

int p[MAXN];

int find(int x)
{
	return p[x] == x ? x : p[x]=find(p[x]);
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n, m;
	while (scanf("%d%d", &n, &m) && (n || m))
	{
		int u, v, w;
		int total_cost = 0;
		vector<pair<int, ii> > EdgeList;
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			total_cost += w;
			EdgeList.push_back(make_pair(w, make_pair(u, v)));
		}
		sort(EdgeList.begin(), EdgeList.end());
		for (int i = 0; i < n; i++)
			p[i]= i;
		int cost = 0;
		for (int i = 0; i < EdgeList.size(); i++)
		{
			w = EdgeList[i].first;
			u = EdgeList[i].second.first;
			v = EdgeList[i].second.second;
			int pu = find(u);
			int pv = find(v);
			if (pu != pv)
			{
				cost += w;
				p[pv] = pu;
			}
		}
		printf("%d\n", total_cost-cost);
	}
	return 0;
}
