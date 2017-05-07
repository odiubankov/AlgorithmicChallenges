#ifndef LEETCODESOLUTIONS_SORTINGCOMPARATOR_H
#define LEETCODESOLUTIONS_SORTINGCOMPARATOR_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

namespace hackerrank
{
struct Player {
    string name;
    int score;
};

bool operator<(const Player& player1, const Player& player2)
{
    if (player1.score == player2.score)
    {
        return player1.name < player2.name;
    }

    return player1.score > player2.score;
}


vector<Player> comparator(vector<Player> players) {
    sort(begin(players), end(players));
    return players;
}

}

#endif //LEETCODESOLUTIONS_SORTINGCOMPARATOR_H
