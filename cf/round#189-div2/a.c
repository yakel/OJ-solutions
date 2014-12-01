#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_magic(char num[])
{
	int len = strlen(num);
	int i = 0;
	int level = 0;
	while(i < len)
	{
		switch(level)
		{
			case 0:
				if(num[i] == '1')   
				{
					i++;
					level++;
					break;
				}
				else return false;
			case 1:
				if(num[i] == '4')
				{
					i++;
					level++;
					break;
				}
				else if(num[i] == '1')
				{
					level = 0;
					break;
				}
				else return false;
			case 2:
				if(num[i] == '4')
				{
					i++;
					level = 0;
					break;
				}
				else if(num[i] == '1')
				{
					level = 0;
					break;
				}
				else return false;
		}
	}
	return true;
}

int main(void)
{
	char num[12];
	scanf("%s", num);
	if(is_magic(num))   printf("YES\n");
	else   printf("NO\n");
	return 0;
}
