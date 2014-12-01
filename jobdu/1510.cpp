#include <cstdio>
#include <cstring>

char str[1000000];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	while (gets(str))
	{
		int len = strlen(str);
		for (int i = 0; i < len; i++)
		{
			if (str[i] == ' ')  printf("%%20");
			else  printf("%c", str[i]);
		}
		printf("\n");
	}
	return 0;
}
