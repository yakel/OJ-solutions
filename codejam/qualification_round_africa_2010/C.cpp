#include <cstdio>
#include <cstring>
#include <cctype>

int main()
{
#ifdef LOCAL
	freopen("C-large-practice.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	int table[26][2];
	for (int i = 0; i < 15; i++)
	{
		table[i][0] = i / 3 + 2;
		table[i][1] = i % 3 + 1;
	}
	for (int i = 15; i < 19; i++)
	{
		table[i][0] = 7;
		table[i][1] = i - 14;
	}
	for (int i = 19; i < 22; i++)
	{
		table[i][0] = 8;
		table[i][1] = i - 18;
	}
	for (int i = 22; i < 26; i++)
	{
		table[i][0] = 9;
		table[i][1] = i - 21;
	}
	int T;
	scanf("%d", &T);
	getchar();
	char str[1100];
	for (int kase = 1; kase <= T; kase++)
	{
		gets(str);
		int pre = -1;
		int len = strlen(str);
		printf("Case #%d: ", kase);
		for (int i = 0; i < len; i++)
		{
			if (str[i] == ' ')
			{
				if (pre == 0)  printf(" ");
				printf("0");
				pre = 0;
			}
			else if (isalpha(str[i]))
			{
				int t = str[i] - 'a';
				if (table[t][0] == pre)  printf(" ");
				for (int j = 0; j < table[t][1]; j++)
					printf("%d", table[t][0]);
				pre = table[t][0];
			}
		}
		printf("\n");
	}
	return 0;
}

