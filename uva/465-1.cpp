#include <cstdio>
#include <climits>

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	char str1[300], str2[300], op;
	double a, b;
	while (scanf("%s %c %s", str1, &op, str2) != EOF)
	{
		printf("%s %c %s\n", str1, op, str2);
		double a, b, c;
		sscanf(str1, "%lf", &a);
		sscanf(str2, "%lf", &b);
		if (op == '+')  c = a + b;
		else if (op == '*')  c = a * b;
		if (a > INT_MAX)  printf("first number too big\n");
		if (b > INT_MAX)  printf("second number too big\n");
		if (c > INT_MAX)  printf("result too big\n");
	}
	return 0;
}
