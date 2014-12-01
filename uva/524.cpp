#include <cstdio>
#include <cstring>

int A[20], vis[20];
int n;

int is_prime(int n)
{
	for(int i = 2; i*i <= n; i++)
		if(n % i == 0)   return 0;
	return 1;
}

void dfs(int cur)
{
	if(cur == n && is_prime(A[0]+A[n-1]))
	{
		for(int i = 0; i < n; i++)
		{
			printf("%d", A[i]);
			printf("%s", i == n-1 ? "\n" : " ");
		}
		return;
	}
	for(int i = 2; i <= n; i++)
		if(vis[i] == 0 && is_prime(i+A[cur-1]))
		{
			A[cur] = i;
			vis[i] = 1;
			dfs(cur+1);
			vis[i] = 0;
		}
}
	
int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int kase = 0;
	while(scanf("%d", &n) != EOF)
	{
		memset(vis, 0, sizeof(vis));
		A[0] = 1;
		vis[1] = 1;
		if (kase)   printf("\n");
		printf("Case %d:\n", ++kase);
		dfs(1);
	}
	return 0;
}

