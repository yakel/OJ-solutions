#include <cstdio>

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int main()
{
	int n;
	while (scanf("%d", &n) && n)
	{
		int g = 0;
		for (int i = 1; i < n; i++)
			for (int j = i+1; j <= n; j++)
				g += gcd(j, i);
		printf("%d\n", g);
	}
	return 0;
}
