#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

set<int> intersection(const set<int> &a, const set<int> &b)
{
	set<int>::iterator itA = a.begin(), itB = b.begin();
	set<int> c;
	while (itA != a.end() && itB != b.end())
	{
		if (*itA == *itB)
		{
			c.insert(*itA);
			itA++;
			itB++;
		}
		else if (*itA < *itB)  itA++;
		else if (*itA > *itB)  itB++;
	}
	return c;
}

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
			set<int> s = intersection(A, B);
			if (A == s)  printf("A is a proper subset of B\n");
			else if (B == s)  printf("B is a proper subset of A\n");
			else  printf("I'm confused!\n");
		}
	}
	return 0;
}
