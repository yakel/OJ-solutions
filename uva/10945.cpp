#include <cstdio>
#include <cctype>
#include <cstring>
#define MAXN 100000

char str1[MAXN], str2[MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	while (gets(str1))
	{
		if (strcmp(str1, "DONE") == 0)  break;
		int len1 = strlen(str1), len2 = 0;
		for (int i = 0; i < len1; i++) 
			if (isalpha(str1[i]))
				str2[len2++] = tolower(str1[i]);
		bool palindrome = true;
		for (int i = 0, j = len2-1; i < j; i++, j--)
			if (str2[i] != str2[j])
			{
				palindrome = false;
				break;
			}
		if (palindrome)  printf("You won't be eaten!\n");
		else  printf("Uh oh..\n");
	}
	return 0;
}

			
