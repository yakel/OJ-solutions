#include <cstdio>
#include <cstring>

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	char str[200];
	while (gets(str))
	{
		int t = 0;
		bool stop = false;
		do
		{
			int len = strlen(str);
			for (int i = 0; i < len; i++)
			{
				if (str[i] == '#')
				{
					stop = true;
					break;
				}
				if (str[i] == '0' || str[i] == '1')
				{
					t = t * 2 + str[i] - '0';
					if (t >= 131071)  t %= 131071;
				}
			}
		} while (!stop && gets(str));
		if (t == 0)  printf("YES\n");
		else  printf("NO\n");
	}
	return 0;
}
