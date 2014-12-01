#include <cstdio>
#include <cstring>

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int s, e;
	char str[100000];
	while (gets(str))
	{
		bool in_word = false;
		int len = strlen(str);
		int p = 0;
		while (p < len)
		{
			while (p < len && str[p] == ' ')
			{
				putchar(' ');
				p++;
			}
			s = p;
			while (p < len && str[p] != ' ')  p++;
			e = p - 1;
			for (int i = e; i >= s; i--)
				putchar(str[i]);
		}
		printf("\n");
	}
	return 0;
}
