#include <cstdio>
#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;
typedef map<string, int> msi;

struct Recipe
{
	string name;
	int cost;
	bool operator < (const Recipe& r) const
	{
		if (cost != r.cost)  return cost < r.cost;
		return name < r.name;
	}
}recipe[110];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	cin >> T;
	getchar();
	msi ingredient;
	while (T--)
	{
		string title;
		getline(cin, title);
		transform(title.begin(), title.end(), title.begin(), ::toupper);
		int m, n, b;
		cin >> m >> n >> b;
		getchar();
		ingredient.clear();
		string str;
		int x; 
		for (int i = 0; i < m; i++)
		{
			cin >> str >> x;
			getchar();
			ingredient[str] = x;
		}
		for (int i = 0; i < n; i++)
		{
			getline(cin, recipe[i].name);
			recipe[i].cost = 0;
			int k;
			cin >> k;
			getchar();
			for (int j = 0; j < k; j++)
			{
				cin >> str >> x;
				getchar();
				recipe[i].cost += ingredient[str]*x;
			}
		}
		sort(recipe, recipe+n);
		cout << title << endl;
		if (recipe[0].cost > b)
		{
			cout << "Too expensive!" << endl << endl;
			continue;
		}
		for (int i = 0; i < n; i++)
		{
			if (recipe[i].cost > b)  break;
			cout << recipe[i].name << endl;
		}
		cout << endl;
	}
	return 0;
}
