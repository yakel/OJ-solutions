#include <cstdio>
#include <cmath>
#include <cctype>
#include <climits>
#define MAXN 100000

long long sum[MAXN];
char str[1000000];
int k;

void init()
{
	k = sqrt(INT_MAX);
	int p = 0;
	for (int i = 1; i <= k; i++)
	{
		sprintf(&str[p], "%d", i);
		while (isdigit(str[p]))  p++;
	}
	int tmp = 0;
	sum[0] = 0;
	for (int i = 1; i <= k; i++)
	{
		int cnt = 0, t = i;
		while (t)
		{
			cnt++;
			t /= 10;
		}
		tmp += cnt;
		sum[i] = sum[i-1];
		sum[i] += tmp;
	}
}
	
int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	init();
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int low = 1, high = k;
		while (low < high)
		{
			int mid = (low + high) / 2;
			if (n <= sum[mid])  high = mid;
			else  low = mid + 1;
		}
		int pos = n - sum[low-1];
		printf("%c\n", str[pos-1]);
	}
	return 0;
}
