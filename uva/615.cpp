#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAXN 100000

map<int, int> m;
vector<int> AdjList[MAXN];
bool vis[MAXN];
int indegree[MAXN], edgeN;

void newNode(int x)
{
	if (!m.count(x))
	{
		int t = m.size();
		m[x] = t;
	}
}

bool check()
{
	int vertexN = m.size();
	if (edgeN != vertexN - 1)  return false;
	int root = -1, zero_indegree = 0;
	for (int i = 0; i < vertexN; i++)
	{
		if (indegree[i] == 0)
		{
			root = i;
			zero_indegree++;
		}
		if (indegree[i] > 1)  return false;
	}
	if (zero_indegree > 1)  return false;
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(root);
	vis[root] = 1;
	int cnt = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < AdjList[u].size(); i++)
		{
			int v = AdjList[u][i];
			if (!vis[v])
			{
				q.push(v);
				vis[v] = 1;
				cnt++;
			}
		}
	}
	if (cnt == vertexN)  return true;
	return false;
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int u, v;
	int kase = 0;
	while (scanf("%d%d", &u, &v) != EOF)
	{
		if (u < 0 && v < 0)  break;
		kase++;
		m.clear();
		memset(indegree, 0, sizeof(indegree));
		for (int i = 0; i < MAXN; i++)  AdjList[i].clear();
		edgeN = 0;
		while (u || v)
		{
			newNode(u);
			newNode(v);
			AdjList[m[u]].push_back(m[v]);
			indegree[m[v]]++;
			edgeN++;
			scanf("%d%d", &u, &v);
		}
		if (check())  printf("Case %d is a tree.\n", kase);
		else  printf("Case %d is not a tree.\n", kase);
	}
	return 0;
}
