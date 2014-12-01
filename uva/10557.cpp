#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1e9

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	while (scanf("%d", &n) && n != -1)
	{
		vector<vector<int> > AdjList(n+1);
		vector<int> weight(1, 0);
		for (int i = 1; i <= n; i++)
		{
			int w, k;
			scanf("%d%d", &w, &k);
			weight.push_back(w);
			for (int j = 0; j < k; j++)
			{
				int x;
				scanf("%d", &x);
				AdjList[i].push_back(x);
			}
		}
		vector<int> dist(n+1, INF);
		dist[1] = 100;
		for (int i = 0; i < n-1; i++)
			for (int u = 1; u < AdjList.size(); u++)
				for (int j = 0; j < AdjList[u].size(); j++)
				{
					int v = AdjList[u][j];
					if (dist[u] + weight[v] > 0)
						dist[v] = min(dist[v], dist[u]+weight[v]);
				}
		if (dist[n] != INF)  printf("winnable\n");
		else  printf("hopeless\n");
	}
	return 0;
}
