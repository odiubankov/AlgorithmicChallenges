//https://leetcode.com/problems/logger-rate-limiter/
#ifndef ALGORITHMICCHALLENGES_359_LOGGERRATELIMITER_H
#define ALGORITHMICCHALLENGES_359_LOGGERRATELIMITER_H

#include <unordered_map>
using namespace std;

class Logger {
public:
    unordered_map<string, int> msgs;

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, const string& message) {
        auto msgIt = msgs.find(message);
        if (msgIt == end(msgs)) {
            msgs[message] = timestamp;
            return true;
        }
        if ((timestamp - msgIt->second) >= 10) {
            msgIt->second = timestamp;
            return true;
        }
        return false;
    }
};

#endif //ALGORITHMICCHALLENGES_359_LOGGERRATELIMITER_H
