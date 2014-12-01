#include <cstdio>
#include <cstring>

const int maxn = 100+10;
int G[maxn][maxn], c[maxn];
int topo[maxn];
int n, t;

bool dfs(int u)
{
	c[u] = -1;
	for(int v = 0; v < n; v++)
		if(G[u][v])
		{
			if(c[v] < 0)   return fasle;
			else if(!c[v] && !dfs(v))   return false;
		}
	c[u] = 1;
	topo[--t] = u;
	return true;
}

bool toposort()
{
	t = n;
	memset(c, 0, sizeof(c));
	for(int u = 0; u < n; u++)
		if(!c[u])
			if(!dfs(u))   return false;
	return true;
}


