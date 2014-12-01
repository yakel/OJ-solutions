#include <cstdio>
#include <bitset>
using namespace std;

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	unsigned int un;
	while (scanf("%d", &n) != EOF)
	{
		un = (unsigned int)n;
		bitset<32> b(un), bt;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 8; j++)
				bt[i*8+j] = b[(3-i)*8+j];
		un = bt.to_ulong();
		printf("%d converts to %d\n", n, un);
	}
	return 0;
}
