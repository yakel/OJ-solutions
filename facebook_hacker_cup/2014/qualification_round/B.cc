#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

const int maxn = 35;

struct Player
{
    string name;
    int shot, height;
    int rank, played_time;
} players[maxn];

bool rank_cmp(const Player& lhs, const Player& rhs)
{
    if (lhs.shot != rhs.shot) return lhs.shot < rhs.shot;
    return lhs.height < rhs.height;
}

struct play_cmp {
    bool operator()(const Player& lhs, const Player& rhs)
    {
        if (lhs.played_time != rhs.played_time)  return lhs.played_time < rhs.played_time;
        return lhs.rank < rhs.rank;
    }
};

struct rest_cmp {
    bool operator()(const Player& lhs, const Player& rhs)
    {
        if (lhs.played_time != rhs.played_time)  return lhs.played_time > rhs.played_time;
        return lhs.rank > rhs.rank;
    }
};

int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        int n, m, p;
        scanf("%d%d%d", &n, &m, &p);
        for (int i = 0; i < n; ++i) {
            cin >> players[i].name >> players[i].shot >> players[i].height;
            players[i].played_time = 0;
        }
        sort(players, players+n, rank_cmp);
        for (int i = 0; i < n; ++i)  players[i].rank = i;

        priority_queue<Player, vector<Player>, play_cmp> play_A, play_B;
        priority_queue<Player, vector<Player>, rest_cmp> rest_A, rest_B;
        for (int i = 0; i < n; i++) {
            if (i < 2*p) {
                if (i % 2 == 0)  play_A.push(players[i]);
                else  play_B.push(players[i]);
            } else {
                if (i % 2 == 0)  rest_A.push(players[i]);
                else  rest_B.push(players[i]);
            }
        }

        for (int i = 1; i <= m; ++i) {
            Player to_rest_A, to_play_A;
            to_rest_A = play_A.top();
            play_A.pop();
            to_play_A = rest_A.top();
            rest_A.pop();
            play_A.push(to_play_A);
            rest_A.push(to_rest_A);

            Player to_rest_B, to_play_B;
            to_rest_B = play_B.top();
            play_B.pop();
            to_play_B = rest_B.top();
            rest_B.pop();
            play_B.push(to_play_B);
            rest_B.push(to_rest_B);
        }

        multiset<string> res;
        while (!play_A.empty()) {
            res.insert(play_A.top().name);
            play_A.pop();
        }
        while (!play_B.empty()) {
            res.insert(play_B.top().name);
            play_B.pop();
        }

        cout << "Case #" << kase << ";";
        for (multiset<string>::iterator it = res.begin(); it != res.end(); ++it)
            cout << " " << *it;
        cout << endl;
    }
    return 0;
}
