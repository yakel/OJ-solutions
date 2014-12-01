#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	char str[60];
	while (gets(str) && str[0] != '#')
	{
		if (next_permutation(str, str+strlen(str)))
				printf("%s\n", str);
		else  printf("No Successor\n");
	}
	return 0;
}
