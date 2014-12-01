#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define MAXN 35

const int dir[5][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, 1}};
int G[MAXN][MAXN][MAXN], dist[MAXN*MAXN*MAXN];
int L, R, C;
int s, e;

int bfs()
{
	queue<int> q;
	memset(dist, -1, sizeof(dist));
	q.push(s);
	dist[s] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		int l = u / (R*C);
		int r = (u%(R*C)) / C;
		int c = (u%(R*C)) % C;
		for (int i = 0; i < 4; i++)
		{
			int rr = r + dir[i][0];
			int cc = c + dir[i][1];
			int v = l*(R*C) + rr*C + cc;
			if (rr >= 0 && rr < R && cc >= 0 && cc < C && G[l][rr][cc] && dist[v] == -1)
			{
				q.push(v);
				dist[v] = dist[u] + 1;
				if (v == e)  return dist[e];
			}
		}
		for (int i = 0; i < 2; i++)
		{
			int ll = l + dir[4][i];
			int v = ll*(R*C) + r*C + c;
			if (ll >= 0 && ll < L && G[ll][r][c] && dist[v] == -1)
			{
				q.push(v);
				dist[v] = dist[u] + 1;
				if (v == e)  return dist[e];
			}
		}
	}
	return dist[e];
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	char str[100];
	while (scanf("%d%d%d", &L, &R, &C) && (L || R || C))
	{
		getchar();
		for (int k = 0; k < L; k++)
		{
			for (int i = 0; i < R; i++)
			{
				gets(str);
				for (int j = 0; j < C; j++)
				{
					if (str[j] == '.')  G[k][i][j] = 1;
					else if (str[j] == '#')  G[k][i][j] = 0;
					else if (str[j] == 'S')
					{
						s = k*(R*C) + i*C + j;
						G[k][i][j] = 1;
					}
					else if (str[j] == 'E')
					{
						e = k*(R*C) + i*C + j;
						G[k][i][j] = 1;
					}
				}
			}
			gets(str);
		}
		int ans = bfs();
		if (ans > 0)  printf("Escaped in %d minute(s).\n", ans);
		else if (ans == -1)  printf("Trapped!\n");
	}
	return 0;
}
