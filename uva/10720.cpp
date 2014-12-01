#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

#define MAXN 10000+10

int a[MAXN];
int n;

bool Havel_Hakimi()
{
	for (int i = 0; i < n-1; i++)
	{
		sort(a+i, a+n, greater<int>());
		if (i + a[i] >= n)  return false;
		for (int j = i+1; j <= i+a[i]; j++)
		{
			a[j]--;
			if (a[j] < 0)  return false;
		}
	}
	if (a[n-1])  return false;
	return true;
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	while (scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		if (Havel_Hakimi())  printf("Possible\n");
		else  printf("Not possible\n");
	}
	return 0;
}
