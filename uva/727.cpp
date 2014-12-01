#include <cstdio>
#include <cctype>
#include <stack>
using namespace std;

int priority(char ch)
{
	if (ch == '+' || ch == '-')  return 1;
	else if (ch == '*' || ch == '/')  return 2;
	return 0;
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	getchar();
	char tmp[20], infix[60], postfix[60];
	gets(tmp);
	while (T--)
	{
		int n = 0;
		while (gets(tmp))
		{
			if (tmp[0] == '\0')  break;
			infix[n++] = tmp[0];
		}
		infix[n] = 0;
		stack<char> op;
		int k = 0;
		for (int i = 0; i < n; i++)
		{
			if (isdigit(infix[i]))  postfix[k++] = infix[i];
			else if (infix[i] == '(')  op.push('(');
			else if (infix[i] == ')')  
			{
				while (op.top() != '(')  
				{
					postfix[k++] = op.top();
					op.pop();
				}
				op.pop();
			}
			else
			{
				if (op.empty() || priority(infix[i]) > priority(op.top()))  op.push(infix[i]);
				else 
				{
					while (!op.empty() && priority(op.top()) >= priority(infix[i]))
					{
						postfix[k++] = op.top();
						op.pop();
					}
					op.push(infix[i]);
				}
			}
		}
		while (!op.empty())
		{
			postfix[k++] = op.top();
			op.pop();
		}
		postfix[k] = 0;
		printf("%s\n", postfix);
		if (T)  printf("\n");
	}
	return 0;
}
