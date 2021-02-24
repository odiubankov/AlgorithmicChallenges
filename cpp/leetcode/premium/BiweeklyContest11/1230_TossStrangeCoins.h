//https://leetcode.com/contest/biweekly-contest-11/problems/toss-strange-coins/
#ifndef ALGORITHMICCHALLENGES_1230_TOSSSTRANGECOINS_H
#define ALGORITHMICCHALLENGES_1230_TOSSSTRANGECOINS_H

double probabilityOfHeads(const vector<double>& prob, int target) {
    vector<vector<double>> probabilities(prob.size() + 1, vector<double>(target + 1, 0.0));
    probabilities[0][0] = 1;
    for (int i = 1; i <= prob.size(); ++i)
        for (int j = 0; j <= target && j <= i; ++j)
            if (j == 0)
                probabilities[i][j] = probabilities[i - 1][j] * (1.0 - prob[i - 1]);
            else if (j == i)
                probabilities[i][j] = probabilities[i - 1][j - 1] * prob[i - 1];
            else
                probabilities[i][j] = probabilities[i - 1][j] * (1.0 - prob[i - 1]) + probabilities[i - 1][j - 1] * prob[i - 1];
    return probabilities.back().back();
}

#endif //ALGORITHMICCHALLENGES_1230_TOSSSTRANGECOINS_H
