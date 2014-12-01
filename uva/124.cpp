#include <cstdio>
#include <cstring>
#include <cctype>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
#define N 26

map<char, int> id;
map<int, char> var;
vector<int> AdjList[N], ans;
int n, indegree[26];

void newNode(char c)
{
	if (!id.count(c))
	{
		int t = id.size();
		id[c] = t;
		var[t] = c;
	}
}

void dfs(int cur)
{
	if (cur == n)
	{
		for (int i = 0; i < n; i++)  printf("%c", var[ans[i]]);
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++)
		if (indegree[i] == 0)
		{
			indegree[i] = -1;
			ans.push_back(i);
			vector<int> vt;
			for (int j = 0; j < AdjList[i].size(); j++)
			{
				int v = AdjList[i][j];
				vt.push_back(v);
				indegree[v]--;
			}
			dfs(cur+1);
			for (int j = 0; j < vt.size(); j++)
				indegree[vt[j]]++;
			ans.pop_back();
			indegree[i] = 0;
		}
}
			
int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	char str[1000];
	bool first = true;
	while (gets(str))
	{
		int len = strlen(str);
		id.clear();
		var.clear();
		vector<char> varList;
		for (int i = 0; i < len; i++)
			if (islower(str[i]))
				varList.push_back(str[i]);
		sort(varList.begin(), varList.end());
		for (int i = 0; i < varList.size(); i++)  newNode(varList[i]);
		n = id.size();
		gets(str);
		len = strlen(str);
		vector<int> rel;
		for (int i = 0; i < len; i++)
			if (islower(str[i]))
				rel.push_back(id[str[i]]);
		for (int i = 0; i < N; i++)  indegree[i] = 0;
		for (int i = 0; i < N; i++)  AdjList[i].clear();
		for (int i = 0; i+1 < rel.size(); i += 2)
		{
			AdjList[rel[i]].push_back(rel[i+1]);
			indegree[rel[i+1]]++;
		}
		if (first)  first = false;
		else  printf("\n");
		dfs(0);	
	}
	return 0;
}
