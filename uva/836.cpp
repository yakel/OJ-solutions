#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int mat[30][30], sum[30][30];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	getchar();
	char str[30];
	gets(str);
	while (T--)
	{
		gets(str);
		int n = strlen(str);
		for (int i = 1; i <= n; i++)
			mat[1][i] = str[i-1] - '0';
		int p = 2;
		while (gets(str) && str[0])
		{
			for (int j = 1; j <= n; j++)
				mat[p][j] = str[j-1] - '0';
			p++;
		}
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (mat[i][j] == 0)  mat[i][j] = -1000;
				sum[i][j] = mat[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]; 
			}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int p = i; p <= n; p++)
					for (int q = j; q <= n; q++)
					{
						int t = sum[p][q] - sum[p][j-1] - sum[i-1][q] + sum[i-1][j-1];
						ans = max(ans, t);
					}
		printf("%d\n", ans);
		if (T)  printf("\n");
	}
	return 0;
}
