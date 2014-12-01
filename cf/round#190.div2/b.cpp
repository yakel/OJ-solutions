#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void)
{
	int r, g, b;
	scanf("%d%d%d", &r, &g, &b);
	int res = 0;
	int m = min(min(r,g), b);
	res += m;
	r -= m;
	g -= m;
	b -= m;
	res += r/3;
	res += g/3;
	res += b/3;
	printf("%d\n", res);
	return 0;
}
