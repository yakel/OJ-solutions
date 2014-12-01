#include <cstdio>

int main()
{
	freopen("136-1.cpp", "w", stdout);
	int p = 1; // the number of ugly number
	int i;
	for (i = 2; ; i++)
	{
		int t = i;
		while (t % 2 == 0)   t /= 2;
		while (t % 3 == 0)   t /= 3;
		while (t % 5 == 0)   t /= 5;
		if (t == 1)
		{
			p++;
			//printf("%d is the %dth ugly number\n", i, p);
		}
		if (p >= 1500)   break;
	}
	printf("%d\n", i);
	return 0;
}

