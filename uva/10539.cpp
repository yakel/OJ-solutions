#include <cstdio>
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
#define MAXN 10000000

vi primes;
bitset<MAXN+100> bs;
ll sieve_size;

void sieve(ll upper)
{
	sieve_size = upper;
	bs.set();
	bs.set(0, false);
	bs.set(1, false);
	for (ll i = 2; i <= upper; i++)
		if (bs.test((size_t)i))
		{
			for (ll j = i*i; j <= upper; j += i)
				bs.set((size_t)j, false);
			primes.push_back((int)i);
		}
}

bool isPrime(ll n)
{
	if (n <= sieve_size)  return bs.test((size_t)n);
	for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++)
		if (n % primes[i] == 0)  return false;
	return true;
}

vi primeFactors(ll n)
{
	vi factors;
	int idx = 0;
	ll pf = primes[idx];
	while (n != 1 && (pf * pf <= n))
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
	sieve(10000000);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		ll low, upper;
		scanf("%lld%lld", &low, &upper);
		int cnt = 0;
		for (ll i = low; i <= upper; i++)
			if (!isPrime(i))
			{
				vi res = primeFactors(i);
				vi::iterator last = unique(res.begin(), res.end());
				if (last - res.begin() == 1)  cnt++;
			}
		printf("%d\n", cnt);
	}
	return 0;
}
