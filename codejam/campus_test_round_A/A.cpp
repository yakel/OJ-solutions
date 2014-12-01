#include <cstdio>
#include <vector>
using namespace std;

const char cnt_words[11][20] = {"", "", "double", "triple", "quadruple", "quintuple", "sextuple", "septuple", "octuple", "nonuple", "decuple"};
const char digit_words[10][20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main()
{
#ifdef LOCAL
	//freopen("in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	char phone[200], ch;
	for (int kase = 1; kase <= T; kase++)
	{
		scanf("%s", phone);
		vector<int> format;
		format.push_back(0);
		int x;
		do
		{
			scanf("%d", &x);
			format.push_back(x);
		} while ((ch = getchar()) != '\n');
		printf("Case #%d:", kase);
		int start = 0, end = 0;
		for (int i = 1; i < format.size(); i++)
		{
			start += format[i-1];
			end += format[i];
			vector<int> digit, cnt;
			int t = 1;
			for (int j = start+1; j <= end; j++)
			{
				if (j == end || phone[j] != phone[j-1])
				{
					digit.push_back(phone[j-1]-'0');
					cnt.push_back(t);
					t = 1;
				}
				else  t++;
			}
			for (int j = 0; j < digit.size(); j++)
			{
				if (cnt [j] == 1)  printf(" %s", digit_words[digit[j]]);
				if (cnt[j] > 1 && cnt[j] < 11)  printf(" %s %s", cnt_words[cnt[j]], digit_words[digit[j]]);
				if (cnt[j] > 10)
					for (int p = 0; p < cnt[j]; p++)  printf(" %s", digit_words[digit[j]]);
			}
		}
		printf("\n");
	}
	return 0;
}
	
			
