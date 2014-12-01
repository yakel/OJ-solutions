#include <cstdio>
#include <climits>
#define MAXN 110

int p[MAXN], m[MAXN][MAXN];
int s[MAXN][MAXN];	// s records the index of archiving the optimal cost (k)

void print_order(int i, int j)
{	printf("%d %d\n", i, j);
	if (j-i == 1)
	{
		printf("%d", i);
		return;
	}
	print_order(i, s[i][j]);
	print_order(s[i][j]+1, j);
}

int main()
{
#ifdef LOCAL
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif
	int N;
	while (scanf("%d", &N) != EOF)
	{
		int n = N - 1;	// n is the number of matrixes
		for (int i = 0; i <= n; i++)   scanf("%d", &p[i]);
		for (int i = 1; i <= n; i++)   m[i][i] = 0;	
		for (int l = 2; l <= n; l++)
		{
			for (int i = 1; i <= n-l+1; i++)
			{
				int j = i+l-1;
				m[i][j] = INT_MAX;
				for ( int k = i; k <= j-1; k++)
				{
					int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
					if (q < m[i][j])
					{
						m[i][j] = q;
						s[i][j] = k;
						printf("%d %d %d\n", i, j, k);
					}
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				printf("%d", s[i][j]);
			printf("\n");
		}
		printf("%d\n", m[1][n]);
		// print the order of the optimal cost
		//print_order(1, n);
		//printf("\n");
	}
	return 0;
}
