#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>
using namespace std;

struct Cont
{
	int id, num, t_penalty;
	int penalty[10];
	bool solved[10], join;
	bool operator < (const Cont & c) const
	{
		if (num != c.num)  return num > c.num;
		if (t_penalty != c.t_penalty)  return t_penalty < c.t_penalty;
		return id < c.id;
	}
} cont[110];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	getchar();
	char str[100];
	gets(str);
	while (T--)
	{
		memset(cont, 0, sizeof(cont));
		for (int i = 1; i <= 100; i++)
			cont[i].id = i;
		while (gets(str) && str[0])
		{
			int c, p, time;
			char ch;
			sscanf(str, "%d%d%d", &c, &p, &time);
			for (int i = strlen(str)-1; i >= 0; i++)
				if (isupper(str[i]))
				{
					ch = str[i];
					break;
				}
			cont[c].join = true;
			if (ch == 'C')
			{
				if (!cont[c].solved[p])
				{
					cont[c].num++;
					cont[c].penalty[p] += time;
					cont[c].solved[p] = true;
				}
			}
			else if (ch == 'I')
			{
				if (!cont[c].solved[p])
					cont[c].penalty[p] += 20;
			}
		}
		for (int i = 1; i <= 100; i++)
			for (int j = 1; j <= 9; j++)
				if (cont[i].solved[j])
					cont[i].t_penalty += cont[i].penalty[j];
		sort(cont+1, cont+101);
		for (int i = 1; i <= 100; i++)
			if (cont[i].join)
				printf("%d %d %d\n", cont[i].id, cont[i].num, cont[i].t_penalty);
		if (T)  printf("\n");
	}
	return 0;
}
