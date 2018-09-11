/**
* Tries: Contacts
*
* Cracking the Coding Interview Challenges
* https://www.hackerrank.com/domains/tutorials/cracking-the-coding-interview
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

#ifndef HACKERRANK_TRIESCONTACTS_H
#define HACKERRANK_TRIESCONTACTS_H

#include <unordered_map>
#include <memory>
#include <string>
#include <vector>
#include <array>

namespace hackerrank
{

class TriesNode
{
    inline std::vector<TriesNode>::iterator getChild(char val)
    {
        return find_if(begin(_childs), end(_childs),
                       [val](const auto &child)
                       { return child._val == val; });
    }

    inline std::vector<TriesNode>::const_iterator getChild(char val) const
    {
        return find_if(begin(_childs), end(_childs),
                       [val](const auto &child)
                       { return child._val == val; });
    }


public:
    TriesNode(char val, bool isWord)
        : _val{val}, _isWord(isWord), _allChildsCnt(0)
    {}

    void addChild(char *str, size_t length)
    {
        auto wordEnd = length == 1;
        auto child = getChild(*str);
        if (child != end(_childs)) {
            _childs.emplace_back(*str, wordEnd);
            if (!wordEnd)
                _childs.back().addChild(str + 1, length - 1);
        }
        else {
            if (wordEnd)
                child->_isWord = true;
            else
                child->addChild(str + 1, length - 1);
        }

        ++_allChildsCnt;
    }

    void getSubstrings(const std::string &currentPrefix, std::vector<std::string> &result) const
    {
        if (_isWord) {
            result.push_back(currentPrefix);
        }

        for (const auto &child : _childs) {
            child.getSubstrings(currentPrefix + std::string{child._val}, result);
        }
    }

    size_t getSubstringsCnt() const
    {
        size_t substringsCnt = 0;
        if (_isWord) {
            substringsCnt = 1;
        }

        substringsCnt += _allChildsCnt;
        return substringsCnt;
    }

    void getChildsWithPrefix(char *prefix,
                             size_t prefixLength,
                             const std::string &currentString,
                             std::vector<std::string> &result) const
    {
        if (prefixLength == 0) {
            getSubstrings(currentString, result);
        }
        else {
            auto child = getChild(*prefix);
            if (child != std::end(_childs)) {
                child->getChildsWithPrefix(
                    prefix + 1, prefixLength - 1, currentString + std::string{*prefix}, result);
            }
        }
    }

    size_t getChildsWithPrefixCnt(char *prefix, size_t prefixLength) const
    {
        if (prefixLength == 0) {
            return getSubstringsCnt();
        }

        auto child = getChild(*prefix);
        if (child != std::end(_childs)) {
            return child->getChildsWithPrefixCnt(prefix + 1, prefixLength - 1);
        }

        return 0;
    }

private:
    char _val;
    bool _isWord;
    std::vector<TriesNode> _childs;
    size_t _allChildsCnt;
};

class TriesContacts
{
    TriesNode _root;

public:
    TriesContacts()
        : _root('Z', false)
    {}

    void addContact(std::string contact)
    {
        _root.addChild(&contact[0], contact.size());
    }

    std::vector<std::string> getContacts(std::string prefix)
    {
        std::vector<std::string> contacts;
        _root.getChildsWithPrefix(&prefix[0], prefix.size(), "", contacts);
        return contacts;
    }

    size_t getContactsCnt(std::string prefix)
    {
        return _root.getChildsWithPrefixCnt(&prefix[0], prefix.size());
    }
};

}//namespace hackerrank

#endif //HACKERRANK_TRIESCONTACTS_H
