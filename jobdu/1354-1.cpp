#include <cstdio>

void printResult(int left, int right)
{
	for (int i = left; i <= right; i++)
		printf("%d%s", i, i==right ? "\n" : " ");
}

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	for (int n = 1; n < 1000; n++)
	{
		//printf("#%d\n", n);
		int left = 1, right = 2, sum = 3;
		int mid = n / 2;
		bool solved = false;
		while (left <= mid)
		{
			while (sum < n)
			{
				right++;
				sum += right;
			}
			if (sum == n) 
			{
				//printResult(left, right);
				solved = true;
				sum -= left;
				left++;
			}
			else if (sum > n) 
			{
				sum -= left;
				left++;
			}
		}
		if (!solved)  printf("%d\n", n);
	}
	return 0;
}
