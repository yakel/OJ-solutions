#include <cstdio>
#include <cstring>
#define N 8

bool vis[3][2*N];
int r, c, kase;
int ans[N];

void search(int cur)
{
	if (cur == N)
	{
		printf("%2d      ", ++kase);
		for (int i = 0; i < N; i++)
			printf("%d%s", ans[i]+1, (i==N-1) ? "\n" : " ");
		return;
	}
	if (cur == c)  search(cur+1);
	else
	{
		for (int i = 0; i < N; i++)
			if (!vis[0][i] && !vis[1][cur-i+N] && !vis[2][cur+i])
			{
				ans[cur] = i;
				vis[0][i] = vis[1][cur-i+N] = vis[2][cur+i] = 1;
				search(cur+1);
				vis[0][i] = vis[1][cur-i+N] = vis[2][cur+i] = 0;
			}
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
		scanf("%d%d", &r, &c);
		r--;
		c--;
		memset(vis, 0, sizeof(vis));
		vis[0][r] = 1;
		vis[1][c-r+N] = 1;
		vis[2][c+r] = 1;
		ans[c] = r;
		kase = 0;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		search(0);
		if (T)  printf("\n");
	}
	return 0;
}
