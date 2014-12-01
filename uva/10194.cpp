#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

struct Team
{
	char name[35], tname[35];
	int point, game, win, tie, loss, diff, scored, against;
	bool operator < (const Team& t) const
	{
		if (point != t.point)  return point > t.point;
		if (win != t.win)  return win > t.win;
		if (diff != t.diff)  return diff > t.diff;
		if (scored != t.scored)  return scored > t.scored;
		if (game != t.game)  return game < t.game;
		return strcmp(tname, t.tname) < 0;
	}
		
};
Team team[35];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	char tourn[110];
	int T;
	scanf("%d", &T);
	getchar();
	while (T--)
	{
		memset(team, 0, sizeof(team));
		gets(tourn);
		int n;
		scanf("%d", &n);
		getchar();
		for (int i = 0; i < n; i++)
		{
			gets(team[i].name);
			for (int j = 0; j <= strlen(team[i].name); j++)
				team[i].tname[j] = tolower(team[i].name[j]);
		}
		int k;
		scanf("%d", &k);
		getchar();
		char tmp[200];
		while (k--)
		{
			gets(tmp);
			char name1[35], name2[35];
			int len1 = strchr(tmp, '#') - tmp;
			memcpy(name1, tmp, len1);
			name1[len1] = 0;
			int a, b;
			sscanf(strchr(tmp, '#')+1, "%d", &a);
			sscanf(strchr(tmp, '@')+1, "%d", &b);
			int len2 = strlen(strrchr(tmp, '#')+1);
			memcpy(name2, strrchr(tmp, '#')+1, len2);
			name2[len2] = 0;
			int p, q;
			for (int i = 0; i < n; i++)
				if (strcmp(team[i].name, name1) == 0)
				{
					p = i;
					break;
				}
			for (int i = 0; i < n; i++)
				if (strcmp(team[i].name, name2) == 0)
				{
					q = i;
					break;
				}
			team[p].game++;
			team[q].game++;
			if (a > b)
			{
				team[p].win++;
				team[p].point += 3;
				team[q].loss++;
			}
			else if (a == b)
			{
				team[p].tie++;
				team[p].point++;
				team[q].tie++;
				team[q].point++;
			}
			else 
			{
				team[p].loss++;
				team[q].win++;
				team[q].point += 3;
			}
			team[p].diff += (a-b);
			team[q].diff += (b-a);
			team[p].scored += a;
			team[q].scored += b;
			team[p].against += b;
			team[q].against += a;
		}
		sort(team, team+n);
		printf("%s\n", tourn);
		for (int i = 0; i < n; i++)
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i+1, team[i].name, team[i].point, team[i].game, team[i].win, team[i].tie, team[i].loss, team[i].diff, team[i].scored, team[i].against);
		if (T)  printf("\n");
	}
	return 0;
}
			

