#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 500+10

long long p[MAXN];
int m, k;
bool cut[MAXN];

bool judge(long long n)
{
	long long sum = 0;
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		if (sum + p[i] > n)
		{
			sum = 0;
			cnt++;
		}
		sum += p[i];
	}
	cnt++;
	if (cnt > k)  return false;
	return true;
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
		scanf("%d%d", &m, &k);
		long long sum = 0, lmax = 0;
		for (int i = 0; i < m; i++)
		{
			scanf("%lld", &p[i]);
			sum += p[i];
			lmax = max(lmax, p[i]);
		}
		long long low = lmax, high = sum;
		while (low < high)
		{
			long long mid = (low + high) / 2;
			if (judge(mid))  high = mid;
			else  low = mid + 1;
		}
		long long ans = low;
		int remain = k - 1;
		memset(cut, 0, sizeof(cut));
		sum = 0;
		for (int i = m-1; i >= 0; i--)
		{
			if (i+1 > remain && sum + p[i] <= ans)
			{
				sum += p[i];
			}
			else
			{
				cut[i] = true;
				sum = p[i];
				remain--;
			}
		}
		for (int i = 0; i < m; i++)
		{
			printf("%lld%s", p[i], (i == m-1) ? "\n" : " ");
			if (cut[i])  printf("/ ");
		}
	}
	return 0;
}
