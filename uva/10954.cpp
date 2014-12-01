#include <cstdio>
#include <queue>
using namespace std;

struct Node
{
	int x;
	bool operator < (const Node& a) const {
		return x > a.x;
	}
};

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	while (scanf("%d", &n) != EOF && n)
	{
		Node t;
		priority_queue<Node> q;
		for (int i= 0; i < n; i++)
		{
			scanf("%d", &t.x);
			q.push(t);
		}
		int ans = 0;
		while (!q.empty())
		{
			Node t1 = q.top();
			q.pop();
			Node t2 = q.top();
			q.pop();
			ans += t1.x + t2.x;
			t.x = t1.x + t2.x;
			if (!q.empty())   q.push(t);
		}
		printf("%d\n", ans);
	}
	return 0;
}
