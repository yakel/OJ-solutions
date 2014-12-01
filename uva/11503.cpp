#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;
#define MAXN 100000*2+100
typedef map<string, int> msi;

int p_cnt;  // the number of people
msi m;
int p[MAXN], cnt[MAXN];  // cnt[i] save the number of nodes which root is i

void add_node(string name)
{
	if (!m.count(name))
	{
		m[name] = p_cnt;
		p[p_cnt] = p_cnt;
		cnt[p_cnt] = 1;
		p_cnt++;
	}
}

int find(int x)
{
	return (x == p[x]) ? x : p[x] = find(p[x]);
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
		int n;
		scanf("%d", &n);
		getchar();
		string name1, name2;
		m.clear();
		p_cnt = 0;
		while (n--)
		{
			cin >> name1 >> name2;
			add_node(name1);
			add_node(name2);
			int pa = find(m[name1]);
			int pb = find(m[name2]);
			if (pa != pb)
			{
				p[pb] = pa;
				cnt[pa] += cnt[pb];
			}
			printf("%d\n", cnt[pa]);
		}
	}
	return 0;
}
