#include <cstdio>
#include <vector>
using namespace std;
#define INF 1e9
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		vector<vii> AdjList(n);
		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			AdjList[u].push_back(make_pair(v, w));
		}
		vector<int> dist(n, INF);
		dist[0] = 0;
		for (int i = 0; i < n-1; i++)
			for (int u = 0; u < AdjList.size(); u++)
				for (int j = 0; j < AdjList[u].size(); j++)
				{
					int v = AdjList[u][j].first, w = AdjList[u][j].second;
					dist[v] = min(dist[v], dist[u]+w);
				}
		bool negative_cycle = false;
		for (int u = 0; u < AdjList.size(); u++)
			for (int j = 0; j < AdjList[u].size(); j++)
			{
				int v = AdjList[u][j].first, w = AdjList[u][j].second;
				if (dist[v] > dist[u] + w)
				{
					negative_cycle = true;
					goto s;
				}
			}
s:		if (negative_cycle)  printf("possible\n");
		else  printf("not possible\n");
	}
	return 0;
}
