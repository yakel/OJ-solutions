#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define MAXN 1100

int G[MAXN][MAXN], dist[MAXN*MAXN];
const int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int R, C;
	while (scanf("%d%d", &R, &C) && (R || C))
	{
		int k;
		scanf("%d", &k);
		memset(G, 0, sizeof G);
		for (int i = 0; i < k; i++)
		{
			int r, n;
			scanf("%d%d", &r, &n);
			for (int j = 0; j < n; j++)
			{
				int x;
				scanf("%d", &x);
				G[r][x] = 1;
			}
		}
		int x, y;
		scanf("%d%d", &x, &y);
		int src = x*C + y;
		scanf("%d%d", &x, &y);
		int dest = x*C + y;
		queue<int> q;
		memset(dist, -1, sizeof dist);
		q.push(src);
		dist[src] = 0;
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			if (u == dest)  break;
			int x = u / C;
			int y = u % C;
			for (int i = 0; i < 4; i++)
			{
				int dx = x + dir[i][0], dy = y + dir[i][1];
				int v = dx * C + dy;
				if (dx >= 0 && dx < R && dy >= 0 && dy < C && G[dx][dy] == 0 && dist[v] == -1)
				{
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}
		printf("%d\n", dist[dest]);
	}
	return 0;
}
