#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10
using namespace std;

int n;
char pos[MAXN][MAXN][MAXN];
char view[6][MAXN][MAXN];

char read_char()
{
	char ch;
	while(1)
	{
		ch = getchar();
		if ((ch >= 'A' && ch <= 'Z') || ch == '.')   return ch;
	}
}

void get(int k, int i, int j, int len, int &x, int &y, int &z)
{
	switch(k)
	{
		case 0:
			x = len;
			y = j;
			z = i;
			break;
		case 1:
			x = n-1-j;
			y = len;
			z = i;
			break;
		case 2:
			x = n-1-len;
			y = n-1-j;
			z = i;
			break;
		case 3:
			x = j;
			y = n-1-len;
			z = i;
			break;
		case 4:
			x = n-1-i;
			y = j;
			z = len;
			break;
		case 5:
			x = i;
			y = j;
			z = n-1-len;
			break;
	}
}


int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	while (scanf("%d", &n) != EOF && n)
	{	
		for (int i = 0; i < n; i++)
			for (int k = 0; k < 6; k++)
				for (int j = 0; j < n; j++)
					view[k][i][j] = read_char();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					pos[i][j][k] = '#';

		for (int k = 0; k < 6; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (view[k][i][j] == '.')
						for (int p = 0; p < n; p++)
						{
							int x, y, z;
							get(k, i, j, p, x, y, z);
							pos[x][y][z] = '.';
						}
		int cnt = 0;
		while(1)
		{
			printf("cnt: %d\n", ++cnt);
			bool done = true;
			for (int k = 0; k < 6; k++)
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
					{
						if (view[k][i][j] != '.')
							for (int p = 0; p < n; p++)
							{
								int x, y, z;
								get(k, i, j, p, x, y, z);
								if (pos[x][j][z] == '.')   continue;
								if (pos[x][j][z] == '#')
								{
									pos[x][y][z] = view[k][i][j];
									break;
								}
								if (pos[x][y][z] == view[k][i][j])   break;
								pos[x][y][z] = '.';
								done = false;
							}
					}
			if (done) break;
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					if (pos[i][j][k] != '.')   ans++;
		printf("Maximum weight: %d gram(s)", ans);
	}
	return 0;
}
