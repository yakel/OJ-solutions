#include <cstdio>
#define MAXN 100000+100

int n, a[MAXN];

bool judge()
{
	int cnt[3] = {0};
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 25)  cnt[0]++;
		else if (a[i] == 50)
		{
			cnt[1]++;
			if (cnt[0] >= 1)  cnt[0]--;
			else  return false;
		}
		else if (a[i] == 100)
		{
			cnt[2]++;
			if (cnt[1] >= 1 && cnt[0] >= 1)
			{
				cnt[0]--;
				cnt[1]--;
			}
			else if (cnt[0] >= 3)  cnt[0] -= 3;
			else  return false;
		}
	}
	return true;
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		if (judge())  printf("YES\n");
		else  printf("NO\n");
	}
	return 0;
}
