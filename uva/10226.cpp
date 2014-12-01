#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef map<string, int> msi;

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	getchar();
	string str;
	getline(cin, str);
	msi m;
	while (T--)
	{
		int total = 0;
		m.clear();
		while (getline(cin, str))
		{
			if (str[0] == 0)  break;
			total++;
			m[str]++;
		}
		for (msi::iterator it = m.begin(); it != m.end(); it++)
			cout << it->first << " " << fixed << setprecision(4) << it->second * 100.0 / total << endl;
		if (T)  printf("\n");
	}
	return 0;
}
