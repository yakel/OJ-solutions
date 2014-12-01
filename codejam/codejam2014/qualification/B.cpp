#include <cstdio>

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        double cost, bonus, target;
        double speed = 2;
        int farm = 0;

        scanf("%lf%lf%lf", &cost, &bonus, &target);
        double time;
        if (target <= cost)  time = target / speed;
        else {
            while ( (target-cost) * (speed + (farm+1)*bonus) >
                    (speed + farm*bonus) * target)
                farm++;

            time = 0;
            for (int i = 0; i < farm; i++) {
                time += cost / speed;
                speed += bonus;
            }
            time += target / speed;
        }
        printf("Case #%d: %.7lf\n", kase, time);
    }
}
