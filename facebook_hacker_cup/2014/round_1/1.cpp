#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 30;

int main()
{
#ifdef LOCAL
    freopen("labelmaker.txt", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        char table[maxn];
        long long n;
        scanf("%s%lld", table, &n);
        int k = strlen(table);
        vector<int> v;
        while (n) {
            int t = n % k;
            n /= k;
            if (t == 0) {
                t = k;
                n--;
            }
            v.push_back(t);
        }
        reverse(v.begin(), v.end());
        printf("Case #%d: ", kase);
        for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
            cout << table[*it-1];
        cout << endl;
    }
    return 0;
}
