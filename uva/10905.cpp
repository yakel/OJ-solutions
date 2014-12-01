#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
#define MAXN 50+5

string num[MAXN];

bool cmp(const string a, const string b)
{
	string s1 = a+b, s2 = b+a;
	return s1 > s2;
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	while (cin >> n && n)
	{
		for (int i = 0; i < n; i++)
			cin >> num[i];
		sort(num, num+n, cmp);
		for (int i = 0; i < n; i++)
			cout << num[i];
		cout << endl;
	}
	return 0;
}
