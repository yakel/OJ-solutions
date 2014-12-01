#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> m, lds;

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int x, kase = 0;
	while (scanf("%d", &x) != EOF && x != -1)
	{
		kase++;
		m.clear();
		m.push_back(x);
		while (scanf("%d", &x) && x != -1)
			m.push_back(x);
		lds.clear();
		lds.resize(m.size(), 1);
		for (int i = 1; i < m.size(); i++)
		{
			for (int j = 0; j < i; j++)
				if (m[i] < m[j] && lds[j]+1 > lds[i])
					lds[i] = lds[j] + 1;
		}
		int ans = 1;
		for (int i = 0; i < lds.size(); i++)
			ans = max(ans, lds[i]);
		if (kase > 1)  printf("\n");
		printf("Test #%d:\n  maximum possible interceptions: %d\n", kase, ans);
	}
	return 0;
}
