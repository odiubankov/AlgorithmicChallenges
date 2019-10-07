#include "1_ThreeInOne.h"
#include <exception>

void ThreeInOneStack::checkLeftIndex(int index) {
    if (index >= items_.size() - itemsCnt_[2] - 1)
        throw std::runtime_error("");
}

void ThreeInOneStack::checkRightIndex(int index) {
    int maxLeftIndex = std::max((itemsCnt_[0] - 1) * 2, (itemsCnt_[1] - 1) * 2 + 1);
    if (maxLeftIndex >= index)
        throw std::runtime_error("");
}

void ThreeInOneStack::push1(int val) {
    int index = itemsCnt_[0] * 2;
    checkLeftIndex(index);
    ++itemsCnt_[0];
    items_[index] = val;
}

void ThreeInOneStack::push2(int val) {
    int index = itemsCnt_[1] * 2 + 1;
    checkLeftIndex(index);
    ++itemsCnt_[1];
    items_[index] = val;
}

void ThreeInOneStack::push3(int val) {
    int index = items_.size() - 1 - itemsCnt_[2];
    checkRightIndex(index);
    ++itemsCnt_[2];
    items_[index] = val;
}

int ThreeInOneStack::pop1() {
    if (itemsCnt_[0] == 0)
        throw std::runtime_error("");
    int index = (itemsCnt_[0] - 1) * 2;
    --itemsCnt_[0];
    return items_[index];
}

int ThreeInOneStack::pop2() {
    if (itemsCnt_[1] == 0)
        throw std::runtime_error("");
    int index = (itemsCnt_[1] - 1) * 2 + 1;
    --itemsCnt_[1];
    return items_[index];
}

int ThreeInOneStack::pop3() {
    if (itemsCnt_[2] == 0)
        throw std::runtime_error("");
    int index = items_.size() - 1 - (itemsCnt_[2] - 1);
    --itemsCnt_[2];
    return items_[index];
}
