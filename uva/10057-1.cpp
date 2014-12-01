#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 1000000+10 

int num[MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);
		sort(num, num+n);
		int left = (n-1)/2, right;
		if (n % 2)   right = left;
		else right = left + 1;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (num[i] >= num[left] && num[i] <= num[right])   cnt++;
			if (num[i] > num[right])   break;
		}
		printf("%d %d %d\n", num[left], cnt, num[right]-num[left]+1);
	}
	return 0;
}
