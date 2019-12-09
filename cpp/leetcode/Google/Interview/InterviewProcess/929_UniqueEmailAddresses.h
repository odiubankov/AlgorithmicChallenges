//https://leetcode.com/problems/unique-email-addresses/
#ifndef ALGORITHMICCHALLENGES_929_UNIQUEEMAILADDRESSES_H
#define ALGORITHMICCHALLENGES_929_UNIQUEEMAILADDRESSES_H

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int numUniqueEmails(const vector<string>& emails) {
    unordered_set<string> finalEmails;
    for (auto email : emails) {
        auto atPos = email.find('@');
        string finalEmail;
        for (int i = 0; i < atPos && email[i] != '+'; ++i) {
            if (email[i] != '.')
                finalEmail += email[i];
        }
        finalEmail += email.substr(atPos);
        finalEmails.insert(finalEmail);
    }
    return finalEmails.size();
}

#endif //ALGORITHMICCHALLENGES_929_UNIQUEEMAILADDRESSES_H
