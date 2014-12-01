#include <cstdio>

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	char str[1000];
	while (gets(str))
	{
		int n;
		if (str[1] == 'x')
		{
			sscanf(str, "%x", &n);
			printf("%d\n", n);
		}
		else
		{
			sscanf(str, "%d", &n);
			if (n < 0)  break;
			printf("0x%X\n", n);
		}
	}
	return 0;
}
