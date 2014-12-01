#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define BOXN 35
#define DIMENSION 12

int k, n;	// k is the number of boxes, n is the dimensionality
int box[BOXN][DIMENSION], d[BOXN];	// d[i] save the number of nodes in the longest path starting with node i	
int G[BOXN][BOXN];

bool is_nested(int *box1, int *box2)
{
	// if box1 can be nested in box2, return true; otherwise false
	for (int i = 0; i < n; i++)
		if (box1[i] >= box2[i])   return false;
	return true;
}

int dp(int i)	// compute d[i]
{
	if (d[i] > 0)   return d[i];
	d[i] = 1;
	for (int j = 1; j <= k; j++)
		if (G[i][j])
			d[i] = max(d[i], dp(j)+1);
	return d[i];
}

void print_path(int i)	// print the longest path starting with node i
{
	printf("%d ", i);
	for (int j = 1; j <= k; j++)
		if (G[i][j] && d[i] == d[j]+1)
		{
			print_path(j);
			break;
		}
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	while (scanf("%d%d", &k, &n) != EOF)
	{
		for (int i = 1; i <= k; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &box[i][j]);
		for (int i = 1; i <= k; i++)
			sort(box[i], box[i]+n);
		memset(G, 0, sizeof(G));
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= k; j++)
				if (is_nested(box[i], box[j]))
					G[i][j] = 1;
		int ans = -1;
		int start = 0;
		memset(d, 0, sizeof(d));
		for (int i = 1; i <= k; i++)
		{
			int t = dp(i);
			if (t > ans)
			{
				ans = t;
				start = i;
			}
		}
		printf("%d\n", ans);
		print_path(start);
		printf("\n");
	}
	return 0;
}
		
