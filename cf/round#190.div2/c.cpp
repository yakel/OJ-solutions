#include <stdio.h>
#include <string.h>

char table[] = "UDLR";
int move[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

int main(void)
{
	int a, b;
	char s[110];
	int len, sx, sy, i;
	scanf("%d%d", &a, &b);
	getchar();
	scanf("%s", s);
	len = strlen(s);
	sx = sy = 0;
	for(i = 0; i < len; i++)
	{
		int index = strchr(table, s[i]) - table;
		sx += move[index][0];
		sy += move[index][1];
	}
	if(a % sx == 0 && b % sy == 0 && a/sx == b/sy)
		printf("Yes\n");
	else printf("No\n");
	return 0;
}
