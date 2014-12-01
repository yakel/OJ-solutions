#include <stdio.h>

int main(void)
{
	int r, g, b;
	int res, min;
	scanf("%d%d%d", &r, &g, &b);
	res = 0;
	res += r/3;
	r %= 3;
	res += g/3;
	g %= 3;
	res += b/3;
	b %= 3;
	min = r;
	printf("%d %d %d\n", r, g, b);
	if(g < min)   g = min;
	if(b < min)   b = min;
	printf("min: %d\n", min);
	res += min;
	printf("%d\n", res);
	return 0;
}
