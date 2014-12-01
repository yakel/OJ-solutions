#include <cstdio>
#include <algorithm>
#include <climits>
#define MAXN 100000+10
using namespace std;

int cnt[MAXN], num[MAXN], left[MAXN], right[MAXN];
int d[MAXN][20];
int n;
int size;	// the size of cnt[]

// read data and run length encoding
void RLE()
{
	int x, pre = INT_MAX;
	int cur = -1;	// the index of current segment
	int l;	// l is the left boundary of current segment
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (x == pre)
		{
			cnt[cur]++;
			num[i] = cur;
			left[i] = l;
		}
		else
		{
			if (cur >= 0)
			{
				// set the right boundary
				for (int j = l; j <= i-1; j++)
					right[j] = i-1;
			}
			cur++;
			l = i;
			num[i] = cur;
			left[i] = l;
			cnt[cur] = 1;
			pre = x;
		}
	}
	for (int i = l; i < n; i++)
		right[i] = n-1;
	size = cur + 1;
}

void RMQ_init()
{
	int n = size;
	for (int i = 0; i < n; i++)
		d[i][0] = cnt[i];
	for (int j = 1; (1<<j) <= n; j++)
		for (int i = 0; i + (1<<j) - 1 < n; i++)
		{
			int t = i + (1<<(j-1));
			d[i][j] = max(d[i][j-1], d[t][j-1]);
		}
}

int RMQ(int L, int R)
{
	if (L > R)   return 0;
	int k = 0;
	while (1<<(k+1) <= R-L+1)   k++;
	return max(d[L][k], d[R-(1<<k)+1][k]);
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif
	int q;
	while (scanf("%d%d", &n, &q) != EOF && n)
	{
		RLE();
		//for (int i = 0; i < size; i++)
		//	printf("%d ", cnt[i]);
		//printf("\n");
		//for (int i = 0; i < n; i++)
		//	printf("%d\t%d\t%d\n", num[i], left[i], right[i]);
		RMQ_init();
		while (q--)
		{
			int L, R;
			scanf("%d%d", &L, &R);
			L--;
			R--;
			if (num[L] == num[R])   printf("%d\n", R-L+1);
			else
			{
				int t1 = right[L]-L+1;
				int t2 = R-left[R]+1;
				int t3 = RMQ(num[L]+1, num[R]-1);
				printf("%d\n", max(t1, max(t2, t3)));
			}
		}
	}
	return 0;
}
