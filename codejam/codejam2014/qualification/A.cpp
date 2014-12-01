#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T, row;
    int m[4][4];

    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        scanf("%d", &row);
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                scanf("%d", &m[i][j]);
        set<int> A;
        for (int i = 0; i < 4; i++)
            A.insert(m[row-1][i]);

        scanf("%d", &row);
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                scanf("%d", &m[i][j]);
        set<int> B;
        for (int i = 0; i < 4; i++)
            B.insert(m[row-1][i]);

        set<int> C;
        set_intersection(A.begin(), A.end(), B.begin(),
                B.end(), inserter(C, C.begin()));

        printf("Case #%d: ", kase);
        if (C.size() == 1)  cout << *C.begin() << endl;
        else if (C.size() == 0)  cout << "Volunteer cheated!" << endl;
        else if (C.size() > 1)  cout << "Bad magician!" << endl;
    }
}
