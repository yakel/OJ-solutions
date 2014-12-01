#include <cstdio>
#include <cmath>

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int table[9] = {0};
	int base = 9;
	for (int i = 1; i <= 8; i++)
	{
		table[i] = i * base;
		base *= 10;
	}
	for (int i = 1; i <= 8; i++)
		table[i] += table[i-1];
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int k = 1;
		while (table[k] < n)   k++;
		double t1 = 1.0 * (n - table[k-1]) / k;
		int offset = (int)ceil(t1);  // n is offset-th num of k-th row
		int t2 = (n - table[k-1] - 1) % k + 1;  // the t2-th digit of the num	
		int t3 = 0;
		for (int i  = 1; i <= k-1; i++)
			t3 = t3*10 + 9;
		int m = t3 + offset;  // the compete num  
		for (int i = 0; i < k-t2; i++)   m /= 10;
		printf("%d\n", m % 10);
	}
	return 0;
}
