#include <cstdio>
#include <cstring>
#define MAXN 100+10

long long a[MAXN], target;
char op[MAXN];
int n;
bool ok, vis[MAXN][32000*2+100];

bool judge(int cur, int n)
{
	return n >= -32000 && n <= 32000 && !vis[cur][n+32000];
}

void dfs(int cur, long long res)
{
	if (cur == n )
	{
		if (res == target)  ok = true;
		return;
	}
	if (!ok && judge(cur, res+a[cur]))
	{
		op[cur] = '+';
		vis[cur][res+a[cur]+32000] = true;
		dfs(cur+1, res+a[cur]);
	}
	if (!ok && judge(cur, res-a[cur]))
	{
		op[cur] = '-';
		vis[cur][res-a[cur]+32000] = true;
		dfs(cur+1, res-a[cur]);
	}
	if (!ok && judge(cur, res*a[cur]))
	{
		op[cur] = '*';
		vis[cur][res*a[cur]+32000] = true;
		dfs(cur+1, res*a[cur]);
	}
	if (!ok && res % a[cur] == 0 && judge(cur, res/a[cur]))
	{
		op[cur] = '/';
		vis[cur][res/a[cur]+32000] = true;
		dfs(cur+1, res/a[cur]);
	}
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
			scanf("%lld", &a[i]);
		scanf("%lld", &target);	
		ok = false;
		memset(vis, 0, sizeof(vis));
		vis[0][a[0]+32000] = true;
		dfs(1, a[0]);
		if (ok)
		{
			for (int i = 0; i < n-1; i++)
				printf("%lld%c", a[i], op[i+1]);
			printf("%lld=%lld\n", a[n-1], target);
		}
		else  printf("NO EXPRESSION\n");
	}
	return 0;
}
