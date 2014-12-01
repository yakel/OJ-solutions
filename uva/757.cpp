#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define MAXN 30

struct Lake
{
	int id, f;
	bool operator < (const Lake& l) const
	{
		if (f != l.f)   return f < l.f;
		else return id > l.id;
	}
};

int f[MAXN], d[MAXN], t[MAXN], fish[MAXN], res[MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	bool first = true;
	while (scanf("%d", &n) && n)
	{
		int h;
		scanf("%d", &h);
		for (int i = 0; i < n; i++)
			scanf("%d", &f[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &d[i]);
		t[0] = 0;
		for (int i = 1; i < n; i++)
		{
			scanf("%d", &t[i]);
			t[i] += t[i-1];
		}
		int ans = -1;
		for (int i = 0; i < n; i++)  // the last lake arrived
		{
			int time = h * 12;
			if (t[i] > time)   break;
			time -= t[i];
			priority_queue<Lake> q;
			Lake tmp;
			for (int j = 0; j <= i; j++)
				if (f[j])
					q.push( (Lake){j, f[j]} );
			memset(fish, 0, sizeof(fish));
			int sum = 0;
			while (!q.empty() && time > 0)
			{
				tmp = q.top();
				q.pop();
				sum += tmp.f;
				int id = tmp.id;
				fish[id]++;
				time--;
				tmp.f -= d[id];
				if (tmp.f > 0)   q.push(tmp);
			}
			fish[0] += time;
			if (sum > ans)  
			{
				ans = sum;
				memcpy(res, fish, sizeof(fish));
			}
		}
		if (first)  first = false;
		else  printf("\n");
		for (int i = 0; i < n; i++)
			printf("%d%s", res[i]*5, (i==n-1) ? "\n" : ", ");
		printf("Number of fish expected: %d\n", ans);
	}
	return 0;
}
			

