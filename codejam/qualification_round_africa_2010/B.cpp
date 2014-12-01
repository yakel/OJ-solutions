#include <cstdio>
#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

int main()
{
#ifdef LOCAL
	freopen("B-large-practice.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	getchar();
	string str;
	vector<string> v;
	for (int kase = 1; kase <= T; kase++)
	{
		v.clear();
		getline(cin, str);
		for (int i = 0; i < str.size(); i++)
		{
			string t = "";
			while (i < str.size() && isalpha(str[i]))
			{
				t += str[i];
				i++;
			}
			v.push_back(t);
		}
		printf("Case #%d:", kase);
		for (int i = v.size()-1; i >= 0; i--)
			cout << " " << v[i];
		printf("\n");
	}
	return 0;
}
