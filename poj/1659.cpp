#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 12

struct Vertex
{
	int d, id;
	bool operator < (const Vertex& v) const
	{
		return d > v.d;
	}
};
Vertex vertex[MAXN];
int G[MAXN][MAXN], n;

bool Havel_Hakimi()
{
	for (int i = 0; i < n-1; i++)
	{
		sort(vertex+i, vertex+n);
		if (i + vertex[i].d >= n)  return false;
		int x = vertex[i].id;
		for (int j = i+1; j <= i+vertex[i].d; j++)
		{
			vertex[j].d--;
			int y = vertex[j].id;
			G[x][y] = G[y][x] = 1;
			if (vertex[j].d < 0)  return false;
		}
	}
	if (vertex[n-1].d)  return false;
	return true;
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &vertex[i].d);
			vertex[i].id = i;
		}
		memset(G, 0, sizeof(G));
		if (Havel_Hakimi())  
		{
			printf("YES\n");
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					printf("%d%s", G[i][j], (j == n-1) ? "\n" : " ");
		}
		else  printf("NO\n");
		if (T)  printf("\n");
	}
	return 0;
}
