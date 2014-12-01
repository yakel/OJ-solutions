#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000+10
using namespace std;

char s1[MAXN], s2[MAXN];
int c[MAXN][MAXN];

void print_LCS(int i, int j)
{
	if (i == 0 || j == 0)   return;
	if (s1[i-1] == s2[j-1])
	{
		print_LCS(i-1, j-1);
		printf("%c", s1[i-1]);
	}
	else if (c[i-1][j] == c[i][j])   print_LCS(i-1, j);
	else if (c[i][j-1] == c[i][j])   print_LCS(i, j-1);
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	while (scanf("%s%s", s1, s2) != EOF)
	{
		int m = strlen(s1);
		int n = strlen(s2);
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				if (s1[i-1] == s2[j-1])   c[i][j] = c[i-1][j-1] + 1;
				else  c[i][j] = max(c[i][j-1], c[i-1][j]);
			}
		printf("%d\n", c[m][n]);
		// print the LCS
		print_LCS(m, n);
		printf("\n");
	}
	return 0;
}

