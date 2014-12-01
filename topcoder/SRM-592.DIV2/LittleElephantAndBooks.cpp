#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class LittleElephantAndBooks
{
public:
	int getNumber(vector<int> pages, int number)
	{
		sort(pages.begin(), pages.end());
		int sum = 0;
		for (int i = 0; i < number-1; i++)
			sum += pages[i];
		sum += pages[number];
		return sum;
	}
};
