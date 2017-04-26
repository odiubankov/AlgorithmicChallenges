// https://leetcode.com/problems/insert-delete-getrandom-o1/#/description
/*
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
*/
#ifndef LEETCODESOLUTIONS_RANDOMIZEDSET_H
#define LEETCODESOLUTIONS_RANDOMIZEDSET_H

#include <vector>
#include <unordered_map>
#include <time.h>

using namespace std;

namespace randomizedset
{
  class RandomizedSet
  {
    using ValuesArrayT = vector<int>;
    using ValuesDictionaryT = unordered_map<int, int>;

    ValuesArrayT _valuesArray;
    ValuesDictionaryT _valuesDictionary;

  public:
    RandomizedSet()
    {
      srand(static_cast<unsigned int>(time(0)));
    }

    bool insert(int val)
    {
      auto insertRes = _valuesDictionary.emplace(val, 0);
      if (!insertRes.second)
        return false;

      _valuesArray.push_back(val);
      insertRes.first->second = _valuesArray.size() - 1;
      return true;
    }


    bool remove(int val)
    {
      auto dictIt = _valuesDictionary.find(val);
      if (dictIt == end(_valuesDictionary))
        return false;

      _valuesArray[dictIt->second] = *_valuesArray.rbegin();
      _valuesDictionary[_valuesArray[dictIt->second]] = dictIt->second;
      _valuesDictionary.erase(dictIt);
      _valuesArray.pop_back();
      return true;
    }

    int getRandom()
    {
      return _valuesArray[rand() % _valuesArray.size()];
    }
  };
}

#endif //LEETCODESOLUTIONS_RANDOMIZEDSET_H
