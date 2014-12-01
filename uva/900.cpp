#include <cstdio>
#define MAXN 60
#define N 50

unsigned int F[MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	F[1] = 1;
	F[2] = 2;
	for (int i = 3; i <= N; i++)
		F[i] = F[i-1] + F[i-2];
	int n;
	while (scanf("%d", &n) && n)
		printf("%u\n", F[n]);
	return 0;
}
