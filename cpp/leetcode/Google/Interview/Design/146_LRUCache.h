//https://leetcode.com/problems/lru-cache/
#ifndef ALGORITHMICCHALLENGES_146_LRUCACHE_H
#define ALGORITHMICCHALLENGES_146_LRUCACHE_H

#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
    int capacity_ = 0;
    struct CacheVal{
        int val_ = 0;
        list<int>::const_iterator lruIt_;
    };
    unordered_map<int, CacheVal> keyValues_;
    list<int> leastRecentlyUsedKeys_;

public:
    explicit LRUCache(int capacity) : capacity_{capacity} {}

    int get(int key) {
        auto keyIt = keyValues_.find(key);
        if (keyIt != end(keyValues_)) {
            leastRecentlyUsedKeys_.erase(keyIt->second.lruIt_);
            putImpl(key, keyIt->second.val_);
            return keyIt->second.val_;
        }
        return -1;
    }

    void put(int key, int value) {
        auto keyIt = keyValues_.find(key);
        if (keyIt != end(keyValues_)) {
            leastRecentlyUsedKeys_.erase(keyIt->second.lruIt_);
        } else if (keyValues_.size() == capacity_) {
            keyValues_.erase(leastRecentlyUsedKeys_.front());
            leastRecentlyUsedKeys_.pop_front();
        }
        putImpl(key, value);
    }

private:
    void putImpl(int key, int val) {
        leastRecentlyUsedKeys_.push_back(key);
        auto last = end(leastRecentlyUsedKeys_);
        --last;
        keyValues_[key] = CacheVal{val, last};
    }
};

#endif //ALGORITHMICCHALLENGES_146_LRUCACHE_H
