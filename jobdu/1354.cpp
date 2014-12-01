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
	int n;
	while (scanf("%d", &n) != EOF && n >= 0)
	{
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
				printResult(left, right);
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
		if (!solved)  printf("Pity!\n");
		printf("#\n");
	}
	return 0;
}
