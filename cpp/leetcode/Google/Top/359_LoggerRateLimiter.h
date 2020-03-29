//https://leetcode.com/problems/logger-rate-limiter/
#ifndef ALGORITHMICCHALLENGES_359_LOGGERRATELIMITER_H
#define ALGORITHMICCHALLENGES_359_LOGGERRATELIMITER_H

#include <unordered_set>
#include <queue>
using namespace std;

class Logger {
public:
    unordered_set<string> msgs;
    queue<pair<int, string>> msgQueue;


    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, const string& message) {
        while (!msgQueue.empty() && (timestamp - msgQueue.front().first) >= 10) {
            msgs.erase(msgQueue.front().second);
            msgQueue.pop();
        }

        if (msgs.find(message) != end (msgs))
            return false;

        msgQueue.emplace(timestamp, message);
        msgs.insert(message);
        return true;
    }
};

#endif //ALGORITHMICCHALLENGES_359_LOGGERRATELIMITER_H
