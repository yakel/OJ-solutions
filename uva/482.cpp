#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 1000000

struct Num 
{
	char s[20];
	int rank;
	bool operator < (const Num& n) const
	{
		return rank < n.rank;
	}
};
Num num[MAXN];
int idx[MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	getchar();
	char str[MAXN];
	while (T--)
	{
		gets(str);
		gets(str);
		int len = strlen(str);
		int n = 0;
		for (int i = 0; i < len; )
		{
			if (isdigit(str[i]))
			{
				int t = str[i] - '0';
				i++;
				while (isdigit(str[i]))
				{
					t = t*10 + str[i] - '0';
					i++;
				}
				n++;
				num[n].rank = t;
			}
			else i++;
		}
		for (int i = 1; i <= n; i++)
			scanf("%s", num[i].s);
		sort(num+1, num+n+1);
		for (int i = 1; i <= n; i++)
			printf("%s\n", num[i].s);
		getchar();
		if (T)  printf("\n");
	}
	return 0;
}
