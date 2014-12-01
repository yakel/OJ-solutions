#include <cstdio>

int main()
{
	int a, b;
	int m[20];
	b = 0;
	m[a=b] = m[b++];
	printf("%d\n", a);
	return 0;
}
