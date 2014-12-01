#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
#define MAXN 2000+10

map<string, int> m;
string str[MAXN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	getchar();
	char s1[80], s2[80];
	m.clear();
	map<string, int>::iterator it;
	while (n--)
	{
		gets(s1);
		sscanf(s1, "%s", s2);
		string t = s2;
		it = m.find(t);
		if (it != m.end())  m[t]++;
		else  m[t] = 1;
	}
	int p = 0;
	for (it = m.begin(); it != m.end(); it++)
		str[p++] = it->first;
	sort(str, str+p);
	for (int i = 0; i < p; i++)
		cout << str[i] << " " << m[str[i]] << endl;
	return 0;
}

