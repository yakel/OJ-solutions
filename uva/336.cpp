#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
#define NODEN 35

map<int, int> vertex;

void new_vertex(int x)
{
	if (!vertex.count(x))
	{
		int t = vertex.size() + 1;
		vertex[x] = t;
	}
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n, kase = 0;
	while (scanf("%d", &n) && n)
	{
		int x, y;
		vertex.clear();
		vector<int> G[NODEN];
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			new_vertex(x);
			new_vertex(y);
			G[vertex[x]].push_back(vertex[y]);
			G[vertex[y]].push_back(vertex[x]);
		}
		int s, ttl, cnt;
		int dist[NODEN];
		while (scanf("%d%d", &s, &ttl) && (s || ttl))
		{
			int st = vertex[s];
			queue<int> q;
			memset(dist, -1, sizeof(dist));
			dist[st] = 0;
			q.push(st);
			cnt = 1;
			while (!q.empty())
			{
				int u = q.front();
				q.pop();
				for (int i = 0; i < G[u].size(); i++)
				{
					int v = G[u][i];
					if (dist[v] != -1)  continue;
					dist[v] = dist[u] + 1;
					if (dist[v] > ttl)  goto s;
					q.push(v);
					cnt++;
				}
			}
s:			int ans = vertex.size() - cnt;
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++kase, ans, s, ttl);
		}
	}
	return 0;
}
				
