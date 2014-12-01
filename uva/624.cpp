#include <cstdio>
#include <vector>
using namespace std;

vector<int> t, ans;
int a[25];
int tape, n;
int sum, lmax;

void dfs(int cur)
{
	if (cur == n)
	{
		if (sum > lmax) 
		{
			lmax = sum;
			ans.clear();
			for (int i = 0; i < t.size(); i++)
				ans.push_back(t[i]);
		}
		return;
	}
	dfs(cur+1);
	if (sum + a[cur] <= tape)
	{
		sum += a[cur];
		t.push_back(a[cur]);
		dfs(cur+1);
		t.pop_back();
		sum -= a[cur];
	}
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	while (scanf("%d", &tape) != EOF)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sum = 0;
		lmax = -1;
		dfs(0);
		for (int i = 0; i < ans.size(); i++)
			printf("%d ", ans[i]);
		printf("sum:%d\n", lmax);
	}
	return 0;
}
