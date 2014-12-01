#include <cstdio>
#include <cctype>
#include <cstring>
#define MAXN 110

int mat[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, cnt;
const int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void dfs(int x, int y)
{
	vis[x][y] = 1;
	cnt++;
	for (int i = 0; i < 4; i++)
	{
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		if (dx >= 0 && dx < n && dy >= 0 && dy < n && mat[dx][dy] == mat[x][y] && !vis[dx][dy])
			dfs(dx, dy);
	}
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int x, y;
	char str[10000];
	while (scanf("%d", &n) && n)
	{
		getchar();
		memset(mat, 0, sizeof(mat));
		for (int i = 1; i < n; i++)
		{
			gets(str);
			int len = strlen(str);
			for (int j = 0; j < len; )
			{
				while (j < len && !isdigit(str[j]))  j++;
				if (j == len)  break;
				x = str[j] - '0';
				j++;
				while (j < len && isdigit(str[j]))
				{
					x = x * 10 + str[j] - '0';
					j++;
				}
				while (j < len && !isdigit(str[j]))  j++;
				y = str[j] - '0';
				j++;
				while (j < len && isdigit(str[j]))
				{
					y = y * 10 + str[j] - '0';
					j++;
				}
				mat[x-1][y-1] = i;
			}
		}
		memset(vis, 0, sizeof(vis));
		bool ok = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (!vis[i][j])
				{
					cnt = 0;
					dfs(i, j);
					if (cnt != n)
					{
						ok = false;
						goto s;
					}
				}
s:		if (ok)  printf("good\n");
		else  printf("wrong\n");
	}
	return 0;
}
