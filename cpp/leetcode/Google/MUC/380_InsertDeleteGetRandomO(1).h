//https://leetcode.com/problems/insert-delete-getrandom-o1/
#ifndef ALGORITHMICCHALLENGES_380_INSERTDELETEGETRANDOMO_1_H
#define ALGORITHMICCHALLENGES_380_INSERTDELETEGETRANDOMO_1_H

#include <vector>
#include <unordered_map>
#include <random>

using namespace std;

class RandomizedSet {
    vector<int> valuesArray_;
    unordered_map<int, size_t> valuesDictionary_;
    std::default_random_engine randGenerator_;

public:
    bool insert(int val) {
        auto insertRes = valuesDictionary_.emplace(val, valuesArray_.size());
        if (insertRes.second)
            valuesArray_.push_back(val);
        return insertRes.second;
    }


    bool remove(int val) {
        auto dictIt = valuesDictionary_.find(val);
        if (dictIt == end(valuesDictionary_))
            return false;
        auto elementPos = dictIt->second;
        auto lastElement = valuesArray_.back();
        valuesArray_[elementPos] = lastElement;
        valuesDictionary_[lastElement] = elementPos;
        valuesDictionary_.erase(dictIt);
        valuesArray_.pop_back();
        return true;
    }

    int getRandom() {
        uniform_int_distribution<size_t> distribution{0,valuesArray_.size() - 1};
        return valuesArray_[distribution(randGenerator_)];
    }
};

#endif //ALGORITHMICCHALLENGES_380_INSERTDELETEGETRANDOMO_1_H
