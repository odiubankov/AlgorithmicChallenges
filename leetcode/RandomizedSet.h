/**
* https://leetcode.com/problems/insert-delete-getrandom-o1/#/description
*
* Design a data structure that supports all following operations in average O(1) time.
*
* insert(val): Inserts an item val to the set if not already present.
* remove(val): Removes an item val from the set if present.
* getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
*
* Copyright 2017 Oleksii Diubankov
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef LEETCODESOLUTIONS_RANDOMIZEDSET_H
#define LEETCODESOLUTIONS_RANDOMIZEDSET_H

#include <vector>
#include <unordered_map>
#include <ctime>
#include <cstdlib>

namespace leetcode
{

class RandomizedSet
{
    using ValuesArrayT = std::vector<unsigned long>;
    using ValuesDictionaryT = std::unordered_map<unsigned long, unsigned long>;

    ValuesArrayT _valuesArray;
    ValuesDictionaryT _valuesDictionary;

public:
    RandomizedSet()
    {
        srand(static_cast<unsigned int>(time(nullptr)));
    }

    bool insert(unsigned long val)
    {
        auto insertRes = _valuesDictionary.emplace(val, 0);
        if (!insertRes.second)
            return false;

        _valuesArray.push_back(val);
        insertRes.first->second = _valuesArray.size() - 1;
        return true;
    }

    bool remove(unsigned long val)
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

    std::size_t getRandom()
    {
        return _valuesArray[rand() % _valuesArray.size()];
    }
};

}//namespace leetcode

#endif //LEETCODESOLUTIONS_RANDOMIZEDSET_H
