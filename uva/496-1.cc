#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int x;
	while (scanf("%d", &x) != EOF)
	{
		set<int> A, B, C;
		A.insert(x);
		C.insert(x);
		while (getchar() != '\n')
		{
			scanf("%d", &x);
			A.insert(x);
			C.insert(x);
		}
		scanf("%d", &x);
		B.insert(x);
		C.insert(x);
		while (getchar() != '\n')
		{
			scanf("%d", &x);
			B.insert(x);
			C.insert(x);
		}
		if (A.size() + B.size() == C.size())  printf("A and B are disjoint\n");
		else if (A == B)  printf("A equals B\n");
		else
		{
			set<int> s;
            set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(s, s.begin()));
			if (A == s)  printf("A is a proper subset of B\n");
			else if (B == s)  printf("B is a proper subset of A\n");
			else  printf("I'm confused!\n");
		}
	}
	return 0;
}
