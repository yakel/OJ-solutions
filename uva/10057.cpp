// counting sort, wrong answer
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 65600 

int num[MAXN], cnt[MAXN];
// num[] saves the numbers that appear, cnt[i] saves the number of integer i

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int k = 0;  // counter of the numbers appeared
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			if (cnt[x] == 0)
				num[k++] = x;
			cnt[x]++;
		}
		sort(num, num+k);
		int m = (k-1)/2 ;
		int t, a;
		if (k%2)  
		{
			t = cnt[num[m]];
			a = m;
		}
		else
		{
			t = cnt[num[m]] + cnt[num[m+1]];
			a = m + 1;
		}
		printf("%d %d %d\n", num[m], t, num[a]-num[m]+1);
	}
	return 0;
}
