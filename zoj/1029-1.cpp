#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int move[200];
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		memset(move, 0, sizeof(move));
		for (int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if (x > y)
			{
				int t = x;
				x = y;
				y = t;
			}
			x = (x-1) / 2;
			y = (y-1) / 2;
			for (int j = x; j <= y; j++)
				move[j]++;
		}
		int ans = -1;
		for (int i = 0; i < 200; i++)
			ans = max(ans, move[i]);
		printf("%d\n", ans*10);
	}
	return 0;
}
