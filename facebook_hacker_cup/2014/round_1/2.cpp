#include <cstdio>

int main()
{
#ifdef LOCAL
    freopen("coins_game.txt", "r", stdin);
    freopen("2.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        int jar, coin, target;
        scanf("%d%d%d", &jar, &coin, &target);
        int move = target;
        if (jar > coin)  move += (jar - coin);
        else if (coin > jar) {
            if (target > coin/jar*jar) {
                int t = coin % jar;
                for (int i = jar-1; i > t; i--)
                    if (coin % i == 0) {
                        t = i;
                        break;
                    }
                move += (jar - t);
            }
        }
        printf("Case #%d: %d\n", kase, move);
    }
    return 0;
}
