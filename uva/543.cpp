#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
#define MAXN 1000000

vi primes;
bitset<MAXN+100> bs;

void sieve(ll upper)
{
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

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	sieve(MAXN);
	int n;
	while (scanf("%d", &n) && n)
	{
		int idx = 1;
		bool ok = false;
		while (primes[idx] * 2 <= n)
		{
			int t = n - primes[idx];
			if (bs.test((size_t)t))
			{
				ok = true;
				break;
			}
			idx++;
		}
		if (ok)  printf("%d = %d + %d\n", n, primes[idx], n-primes[idx]);
		else  printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}
