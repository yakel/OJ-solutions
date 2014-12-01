#include <cstdio>
#include <vector>
using namespace std;
typedef unsigned long long ull;

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
	//freopen("B-large.in", "r", stdin);
	//freopen("B-large.out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; kase++)
	{
		int id;
		scanf("%d", &id);
		if (id == 1)
		{
			ull n;
			scanf("%llu", &n);
			vector<int> seq;
			ull t = n;
			while (t != 1)
			{
				if (t & 1)  seq.push_back(1);
				else  seq.push_back(0);
				t = t >> 1;
			}
			ull p = 1, q = 1;
			for (int i = seq.size()-1; i >= 0; i--)
			{
				if (seq[i])  p = p + q;
				else  q = p + q;
			}
			printf("Case #%d: %llu %llu\n", kase, p, q);
		}
		else if (id == 2)
		{
			ull p, q;
			scanf("%llu%llu", &p, &q);
			vector<int> seq;
			while (p != 1 || q != 1)
			{
				if (p < q)
				{
					seq.push_back(0);
					q = q - p;
				}
				else if (p > q)
				{
					seq.push_back(1);
					p = p - q;
				}
			}
			ull n = 1;
			for (int i = seq.size()-1; i >= 0; i--)
			{
				if (seq[i] == 0)  n *= 2;
				else  n = n * 2 + 1;
			}
			printf("Case #%d: %llu\n", kase, n);
		}
	}
	return 0;
}
