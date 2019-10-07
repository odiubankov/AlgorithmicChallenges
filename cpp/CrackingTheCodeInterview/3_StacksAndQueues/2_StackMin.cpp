#include "2_StackMin.h"

void StackMin::push(int val) {
    currentMin_ = std::min(currentMin_, val);
    items_.push(val);
    mins_.push(currentMin_);
}

int StackMin::pop() {
    int val = items_.top();
    items_.pop();
    mins_.pop();
    return val;
}

int StackMin::min() const {
    return mins_.top();
}
