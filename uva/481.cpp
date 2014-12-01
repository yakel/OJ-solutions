#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;

vi v, temp, pos, ans;

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int x;
	while (scanf("%d", &x) != EOF)
		v.push_back(x);
	temp.push_back(v[0]);
	pos.push_back(1);
	for (int i = 1; i < v.size(); i++)
	{
		x = v[i];
		if (x > temp.back())
		{
			temp.push_back(x);
			pos.push_back(temp.size());
		}
		else
		{
			vi::iterator it = lower_bound(temp.begin(), temp.end(), x);
			*it = x;
			pos.push_back(it-temp.begin()+1);
		}
	}
	for (int p = pos.size()-1, len = temp.size(); p >=0 && len > 0; p--)
		if (pos[p] == len)
		{
			ans.push_back(v[p]);
			len--;
		}
	cout << ans.size() << endl << '-' << endl;
	for (int i = ans.size()-1; i >= 0; i--)
		cout << ans[i] << endl;
	return 0;
}
