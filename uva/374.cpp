#include <cstdio>

int powMod(int base, int exp, int mod)
{
	if (exp == 0)  return 1;
	int res = powMod(base, exp>>1, mod);
	res = (res * res) % mod;
	if (exp & 0x1 == 1)  res = (res * base) % mod;
	return res;
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int b, p, m;
	while (scanf("%d%d%d", &b, &p, &m) != EOF)
	{
		int res = powMod(b%m, p, m);
		printf("%d\n", res);
	}
	return 0;
}
