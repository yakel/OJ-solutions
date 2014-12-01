#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define INF 1e9
#define TRvii(c, it) \
	for (vii::iterator it = (c).begin(); it != (c).end(); it++)

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; kase++)
	{
		int n, m, s, t;
		scanf("%d%d%d%d", &n, &m, &s, &t);
		vector<vii> AdjList(n);
		for (int i = 0; i < m; i++)
		{
			int u, v, weight;
			scanf("%d%d%d", &u, &v, &weight);
			AdjList[u].push_back(ii(v, weight));
			AdjList[v].push_back(ii(u, weight));
		}
		vector<int> dist(n, INF);
		dist[s] = 0;
		priority_queue<ii, vector<ii>, greater<ii> > pq;
		pq.push(ii(0, s));
		while (!pq.empty())
		{
			ii top = pq.top();
			pq.pop();
			int d = top.first, u = top.second;
			if (u == t)  break;
			if (d == dist[u])
				TRvii(AdjList[u], it)
				{
					int v = it->first, weight = it->second;
					if (dist[u] + weight < dist[v])
					{
						dist[v] = dist[u] + weight;
						pq.push(ii(dist[v], v));
					}
				}
		}
		if (dist[t] != INF)  printf("Case #%d: %d\n", kase, dist[t]);
		else  printf("Case #%d: unreachable\n", kase);
	}
	return 0;
}
