#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef pair<int, int> pii;

const int N = 8;
int m[N][N];
pii knight[2];

bool judge()
{
    int row_diff = abs(knight[0].first - knight[1].first);
    int col_diff = abs(knight[0].second - knight[1].second);
    if (row_diff % 4 != 0 || col_diff % 4 != 0)  return false;
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    getchar();
    while (T--)
    {
        // read data
        char s[20];
        int p = 0;
        memset(m, 0, sizeof(m));
        for (int i = 0; i < 8; ++i)
        {
            gets(s);
            for (int j = 0; j < 8; ++j)
            {
                if (s[j] == '#')  m[i][j] = 1;
                else if (s[j] == 'K')
                {
                    m[i][j] = 1;
                    knight[p++] = make_pair(i,j);
                }
            }
        }
        if (T)  gets(s);

        if (judge())  printf("YES\n");
        else  printf("NO\n");
    }
    return 0;
}

