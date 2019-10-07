#ifndef ALGORITHMICCHALLENGES_1_THREEINONE_H
#define ALGORITHMICCHALLENGES_1_THREEINONE_H

#include <array>

using namespace std;

class ThreeInOneStack {
public:
    void push1(int val);
    void push2(int val);
    void push3(int val);

    int pop1();
    int pop2();
    int pop3();

private:
    std::array<int, 100> items_;
    std::array<int, 3> itemsCnt_{0, 0, 0};

    void checkLeftIndex(int index);
    void checkRightIndex(int index);
};

#endif //ALGORITHMICCHALLENGES_1_THREEINONE_H
