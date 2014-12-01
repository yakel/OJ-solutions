#include <cstdio>
#include <cctype>

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	double lmin, lmax, lstack[30];
	int top;
	int N;
	scanf("%d", &N);
	getchar();
	char s[100];
	while (N--)
	{
		gets(s);
		char ch = '+';
		top = 0;
		for (int i = 0; s[i] != '\0'; )
		{
			int n = 0;
			while (isdigit(s[i]))
			{
				n = n*10 + s[i]-'0';
				i++;
			}
			if (ch == '+')   lstack[top++] = n;
			else lstack[top-1] *= n;
			if (s[i] != '\0')   ch = s[i++];
		}
		lmin = 0;
		for (int i = 0; i < top; i++)
			lmin += lstack[i];
		top = 0;
		ch = '*';
		for (int i = 0; s[i] != '\0'; )
		{
			int n = 0;
			while (isdigit(s[i]))
			{
				n = n*10 + s[i]-'0';
				i++;
			}
			if (ch == '*')   lstack[top++] = n;
			else lstack[top-1] += n;
			if (s[i] != '\0')   ch = s[i++];
		}
		lmax = 1;
		for (int i = 0; i < top; i++)
			lmax *= lstack[i];
		printf("The maximum and minimum are %.0lf and %.0lf.\n", lmax, lmin);
	}
	return 0;
}
