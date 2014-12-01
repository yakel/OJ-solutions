#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define INF 1e9
typedef pair<int, int> ii;
typedef vector<ii> vii;

int p[20];

void print_ans(int x)
{
	if (p[x] != -1)  print_ans(p[x]);
	printf(" %d", x);
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n, kase = 0;
	while (scanf("%d", &n) && n)
	{
		vector<vii > AdjList(n+1);
		for (int u = 1; u <= n; u++)
		{
			int k;
			scanf("%d", &k);
			int v, w;
			for (int i = 0; i < k; i++)
			{
				scanf("%d%d", &v, &w);
				AdjList[u].push_back(make_pair(v, w));
			}
		}
		int src, dest;
		scanf("%d%d", &src, &dest);
		memset(p, -1, sizeof p);
		vector<int> dist(n+1, INF);
		dist[src] = 0;
		priority_queue<ii, vector<ii>, greater<ii> > pq;
		pq.push(make_pair(dist[src], src));
		while (!pq.empty())
		{
			ii top = pq.top();
			pq.pop();
			int d = top.first, u = top.second;
			if (u == dest)  break;
			if (d == dist[u])
				for (int j = 0; j < AdjList[u].size(); j++)
				{
					int v = AdjList[u][j].first, w = AdjList[u][j].second;
					if (dist[u] + w < dist[v])
					{
						dist[v] = dist[u] + w;
						pq.push(make_pair(dist[v], v));
						p[v] = u;
					}
				}
		}
		printf("Case %d: Path =", ++kase);
		print_ans(dest);
		printf("; %d second delay\n", dist[dest]);
	}
	return 0;
}

