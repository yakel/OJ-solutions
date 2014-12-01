#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 110
#define INF 1e9
#define N 100
typedef pair<int, int> ii;
typedef vector<ii> vii;

int G[MAXN][MAXN];
int time[10];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &time[i]);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				G[i][j] = INF;
		for (int i = 0; i < n; i++)
		{
			vector<int> v;
			do
			{
				int x;
				scanf("%d", &x);
				v.push_back(x);
			} while (getchar() != '\n');
			for (int p = 0; p < v.size(); p++)
				for (int q = p+1; q < v.size(); q++)
				{
					int x = v[p], y = v[q];
					G[x][y] = G[y][x] = min(G[x][y], (y-x)*time[i]);
				}
		}
		vector<int> dist(N, INF);
		dist[0] = 0;
		priority_queue<vii, vector<ii>, greater<ii> > pq;
		pq.push(ii(0, 0));
		while (!pq.empty())
		{
			ii top = pq.top();
			pq.pop();
			int d = top.first, u = top.second;
			if (u == k)  break;
			if (d == dist[u])
				for (int v = 0; v < N; v++)
				{
					if (u == 0)
					{
						if (dist[u] + G[u][v] < dist[v])
						{
							dist[v] = dist[u] + G[u][v];
							pq.push(ii(dist[v], v));
						}
					}
					else
					{
						if (dist[u] + G[u][v] + 60 < dist[v])
						{
							dist[v] = dist[u] + G[u][v] + 60;
							pq.push(ii(dist[v], v));
						}
					}
				}
		}
		if (dist[k] != INF) printf("%d\n", dist[k]);
		else  printf("IMPOSSIBLE\n");
	}
	return 0;
}
