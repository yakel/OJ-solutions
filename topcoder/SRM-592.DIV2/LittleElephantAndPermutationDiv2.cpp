#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class LittleElephantAndPermutationDiv2 
{
public:
	long long getNumber(int N, int K) 
	{
		long long fact[12];
		fact[0] = 1;
		for (int i = 1; i <= N; i++)
			fact[i] = i * fact[i-1];

		vector<int> a, b;
		for (int i = 1; i <= N; i++)
		{
			a.push_back(i);
			b.push_back(i);
		}
		long long cnt = 0;
		do
		{
			int sum = 0;
			for (int i = 0; i <= N; i++)
				sum += max(a[i], b[i]);
			if (sum >= K)  cnt += fact[N];
		} while (next_permutation(b.begin(), b.end()));
		return cnt;
	}
};
