#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
#define FILEN 150
#define SIZEN 256*8+10

string str[FILEN];
map<string, int> m;

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	char s[300];
	int T;
	scanf("%d", &T);
	getchar();
	gets(s);
	while (T--)
	{
		int n = 0; 
		while (gets(s))
		{
			if (!s[0])   break;
			str[n++] = s;
		}
		int min_len = 10000, max_len = 0;
		for (int i = 0; i < n; i++)
		{
			if (str[i].size() < min_len)  min_len = str[i].size();
			if (str[i].size() > max_len)  max_len = str[i].size();
		}
		int len = max_len + min_len;
		map<string, int>::iterator it;
		m.clear();
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
			{
				string t = str[i] + str[j];
				if (t.size() == len)
				{
					it = m.find(t);
					if (it != m.end())  m[t]++;
					else  m[t] = 1;
				}
				t = str[j] + str[i];
				if (t.size() == len)
				{
					it = m.find(t);
					if (it != m.end())  m[t]++;
					else  m[t] = 1;
				}
			}
		int lmax = 0; 
		string ans;
		for (it = m.begin(); it != m.end(); it++)
			if (it->second > lmax)
			{
				lmax = it->second;
				ans = it->first;
			}
		cout << ans << endl;
		if (T)  printf("\n");
	}
	return 0;
}

		
