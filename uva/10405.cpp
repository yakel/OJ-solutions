#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000+10
using namespace std;

char s1[MAXN], s2[MAXN];
int c[MAXN][MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	while (gets(s1) && gets(s2))
	{
		int m = strlen(s1);
		int n = strlen(s2);
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				if (s1[i-1] == s2[j-1])   c[i][j] = c[i-1][j-1] + 1;
				else c[i][j] = max(c[i][j-1], c[i-1][j]);
			}
		printf("%d\n", c[m][n]);
	}
	return 0;
}
