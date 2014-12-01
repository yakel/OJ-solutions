#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 1100
typedef pair<int, int> ii;

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
		vector<pair<int, ii> > EdgeList;
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			EdgeList.push_back(make_pair(w, make_pair(u, v)));
		}
		sort(EdgeList.begin(), EdgeList.end());
		for (int i = 0; i < n; i++)
			p[i] = i;
		vector<int> ans;
		for (int i = 0; i < EdgeList.size(); i++)
		{
			w = EdgeList[i].first;
			u = EdgeList[i].second.first;
			v = EdgeList[i].second.second;
			int pu = find(u);
			int pv = find(v);
			if (pu != pv)  p[pv] = pu;
			else  ans.push_back(w);
		}
		if (ans.empty())  printf("forest\n");
		else
		{
			for (int i = 0; i < ans.size(); i++)
				printf("%s%d", i == 0 ? "" : " ", ans[i]);
			printf("\n");
		}
	}
	return 0;
}
