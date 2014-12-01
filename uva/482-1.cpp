#include <cstdio>
#include <iostream>
#include <cctype>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Num 
{
	string s;
	int rank;
	bool operator < (const Num& n) const
	{
		return rank < n.rank;
	}
};
vector<Num> num;

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	getchar();
	string str;
	while (T--)
	{
		getline(cin, str);
		getline(cin, str);
		int len = str.size();
		num.clear();
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
				num.push_back((Num){"", t});
			}
			else i++;
		}
		for (int i = 0; i < num.size(); i++)
			cin >> num[i].s;	
		sort(num.begin(), num.end());
		for (int i = 0; i < num.size(); i++)
			cout << num[i].s << endl;
		getchar();
		if (T)  printf("\n");
	}
	return 0;
}
