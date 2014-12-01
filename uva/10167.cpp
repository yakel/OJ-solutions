#include <cstdio>
#define POINTN 110

struct Point
{
	int x, y;
};
Point point[POINTN];
int n;

bool judge(int A, int B)
{
	int pos = 0, neg = 0;
	for(int i = 0; i < 2*n; i++)
	{
		int res = A * point[i].x + B * point[i].y; 
		if(res == 0)   return false;
		else if(res > 0)   pos++;
		else if(res < 0)   neg++;
	}
	if(pos == neg)   return true;
	return false;
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	while(scanf("%d", &n) != EOF && n)
	{
		for(int i = 0; i < 2*n; i++)
			scanf("%d%d", &point[i].x, &point[i].y);
		int A, B;
		for(A = -500; A <= 500; A++)
			for(B = 0; B <= 500; B++)
				if(judge(A, B))
					goto found;
found:	printf("%d %d\n", A, B);
	}
	return 0;
}
