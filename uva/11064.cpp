#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
#define MAXN 10000000

bitset<MAXN+100> bs;
vi primes;

void sieve(ll upper)
{
	bs.set();
	bs.set(0, false);
	bs.set(1, false);
	for (ll i = 2; i <= upper; i++)
	{
		if (bs.test((size_t)i))
			for (ll j = i*i; j <= upper; j++)
				bs.set((size_t)j, false);
		primes.push_back((int)i);
	}
}

vi primeFactors(ll n)
{
	vi factors;
	int idx = 0, pf = primes[idx];
	while (n != 1 && (pf*pf <= n))
	{
		while (n % pf == 0)
		{
			n /= pf;
			factors.push_back(pf);
		}
		pf = primes[++idx];
	}
	if (n != 1)  factors.push_back(n);
	return factors;
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	sieve(MAXN);
	int n;
	while (scanf("%d", &n) != EOF)
	{
		vi factors = primeFactors(n);
		vi::iterator last = unique(factors.begin(), factors.end());
		int result = n;
		for (vi::iterator it = factors.begin(); it != last; it++)
			result = result - result/(*it);
		printf("%d\n", result);
	}
	return 0;
}

