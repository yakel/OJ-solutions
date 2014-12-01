#include <cstdio>
#include <vector>
#include <cstring>
#include <cctype>
using namespace std;
#define MAXN 210
#define INF 1e8

int G[MAXN][MAXN], dist[MAXN];
bool vis[MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n, k;
	int time[10];
	while (scanf("%d%d", &n, &k) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &time[i]);
		getchar();
		for (int i = 0; i < 200; i++)
			for (int j = 0; j < 200; j++)
				G[i][j] = INF;
		for (int i = 0; i < 100; i++)
			G[i*2][i*2+1] = G[i*2+1][i*2] = 60;
		for (int i = 0; i < n; i++)
		{
			char str[10000];
			gets(str);
			vector<int> v;
			int len = strlen(str);
			for (int j = 0; j < len; j++)
			{
				if (isdigit(str[j]))
				{
					int t = str[j] - '0';
					j++;
					while (j < len && isdigit(str[j]))
					{
						t = t * 10 + str[j] - '0';
						j++;
					}
					v.push_back(t);
				}
			}
			for (int j = 0; j < v.size(); j++)
				for (int p = j+1; p < v.size(); p++)
				{
					int x = v[j], y = v[p];
					G[2*x+1][2*y] = G[2*y+1][2*x] = min(G[2*x+1][2*y], (y-x)*time[i]);
				}
		}
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < 200; i++)
			dist[i] = INF;
		dist[1] = 0;
		if (k)  k *= 2;
		else  k = 1;
		for (int i = 0; i < 200; i++)
		{
			int u, lmin = INF;
			for (int j = 0; j < 200; j++)
				if (!vis[j] && dist[j] <= lmin)
				{
					lmin = dist[j];
					u = j;
				}
			vis[u] = 1;
			if (u == k)  break;
			for (int j = 0; j < 200; j++)
				dist[j] = min(dist[j], dist[u]+G[u][j]);
		}
		if (dist[k] != INF)  printf("%d\n", dist[k]);
		else  printf("IMPOSSIBLE\n");
	}
	return 0;
}
