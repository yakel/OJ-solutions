#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAXN 100+10

string str[MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			cin >> str[i];
		sort(str, str+n);
		int ans = str[0].size();
		for (int i = 1; i < n; i++)
		{
			int k = 0;
			for (int j = 0; j < str[i-1].size(); j++)
			{
				if (str[i-1][j] == str[i][j])  k++;
				else break;
			}
			ans += str[i].size() - k;
		}
		printf("%d\n", ans);
		for (int i = 0; i < n; i++)
			cout << str[i] << endl;
	}
	return 0;
}
				
