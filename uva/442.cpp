#include <cstdio>
#include <cstring>
#include <cctype>
#include <stack>
#define MAXN 1000
using namespace std;

struct Matrix
{
	int r;
	int c;
} mat[26];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char s[10];
		scanf("%s", s);
		int ix = s[0] - 'A';
		scanf("%d%d", &mat[ix].r, &mat[ix].c);
	}
	char s[MAXN];
	while (scanf("%s", s) != EOF)
	{
		stack<Matrix> st;
		int res = 0;
		bool error = false;
		int len = strlen(s);
		for (int i = 0; i < len; i++)
		{
			if (s[i] == '(')   continue;
			else if (isupper(s[i]))
			{
				int ix = s[i] - 'A';
				Matrix t = (Matrix){mat[ix].r, mat[ix].c};
				st.push(t);
			}
			else if (s[i] == ')')
			{
				Matrix b = st.top();
				st.pop();
				Matrix a = st.top();
				st.pop();
				if (a.c != b.r)
				{
					error = true;
					break;
				}
				else
				{
					res += a.r * a.c * b.c;
					Matrix t = (Matrix){a.r, b.c};
					st.push(t);
				}
			}
		}
		if (error)   printf("error\n");
		else printf("%d\n", res);
	}
	return 0;
}
