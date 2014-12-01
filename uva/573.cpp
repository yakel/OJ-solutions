#include <cstdio>

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int height, up, down, f;
	while (scanf("%d%d%d%d", &height, &up, &down, &f) && height)
	{
		double diff = up * f / 100.0;
		double pos = 0, dis = up;  // dis is the distance of climb on current day
		int day = 0;
		while (true)
		{
			day++;
			pos += dis;
			if (pos > height)
			{
				printf("success on day %d\n", day);
				break;
			}
			if (dis > 0)  dis -= diff;
			if (dis < 0)  dis = 0;
			pos -= down;
			if (pos < 0)
			{
				printf("failure on day %d\n", day);
				break;
			}
		}
	}
	return 0;
}
		
