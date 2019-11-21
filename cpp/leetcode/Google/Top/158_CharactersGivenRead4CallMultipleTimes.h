//https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/
#ifndef ALGORITHMICCHALLENGES_158_CHARACTERSGIVENREAD4CALLMULTIPLETIMES_H
#define ALGORITHMICCHALLENGES_158_CHARACTERSGIVENREAD4CALLMULTIPLETIMES_H

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
    static constexpr int READ_SIZE = 4;
    int readCnt_ = 0;
    array<char, READ_SIZE> chars_;
    int index_ = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char* buf, int n) {
        int res = 0;
        if (index_ < readCnt_) {
            int amount = min(n, readCnt_ - index_);
            memcpy(buf, &chars_[index_], amount);
            index_ += amount;
            n -= amount;
            res = amount;
            buf += amount;
        }
        while (n > 0) {
            index_ = 0;
            readCnt_ = read4(&chars_[0]);
            if (readCnt_ == 0)
                break;
            int amount = min(readCnt_, n);
            memcpy(buf, &chars_[0], amount);
            index_ += amount;
            n -= amount;
            res += amount;
            buf += amount;
        }

        return res;
    }
};

#endif //ALGORITHMICCHALLENGES_158_CHARACTERSGIVENREAD4CALLMULTIPLETIMES_H
