#ifndef LEETCODESOLUTIONS_TRIESCONTACTS_H
#define LEETCODESOLUTIONS_TRIESCONTACTS_H

#include <unordered_map>
#include <memory>
#include <string>
#include <vector>
#include <array>

using namespace std;

namespace hackerrank
{
    class TriesNode
    {
        inline TriesNode* getChild(char val) const
        {
            for (auto& child : _childs)
            {
                if (child._val == val)
                    return const_cast<TriesNode*>(&child);
            }

            return nullptr;
        }


    public:
        TriesNode(char val, bool isWord)
            : _val{val}
            , _isWord(isWord)
            , _allChildsCnt(0)
        {}


        void addChild(char* str, size_t length)
        {
            auto wordEnd = length == 1;
            auto child = getChild(*str);
            if (child == nullptr)
            {
                _childs.emplace_back(*str, wordEnd);
                if (!wordEnd)
                    _childs.back().addChild(str + 1, length - 1);
            }
            else
            {
                if (wordEnd)
                    child->_isWord = true;
                else
                    child->addChild(str + 1, length - 1);
            }

            ++_allChildsCnt;
        }


        void getSubstrings(string currentPrefix, vector<string>& result) const
        {
            if (_isWord)
            {
                result.push_back(currentPrefix);
            }

            for (const auto& child : _childs)
            {
                child.getSubstrings(currentPrefix + string{child._val}, result);
            }
        }


        size_t getSubstringsCnt() const
        {
            size_t substringsCnt = 0;
            if (_isWord)
            {
                substringsCnt = 1;
            }

            substringsCnt += _allChildsCnt;
            return substringsCnt;
        }


        void getChildsWithPrefix(char* prefix, size_t prefixLength, string currentString, vector<string>& result) const
        {
            if (prefixLength == 0)
            {
                getSubstrings(currentString, result);
            }
            else
            {
                auto child = getChild(*prefix);
                if (child)
                {
                    child->getChildsWithPrefix(
                        prefix + 1, prefixLength - 1, currentString + string{*prefix}, result);
                }
            }
        }


        size_t getChildsWithPrefixCnt(char* prefix, size_t prefixLength) const
        {
            if (prefixLength == 0)
            {
                return getSubstringsCnt();
            }
            else
            {
                auto child = getChild(*prefix);
                if (child)
                {
                    return child->getChildsWithPrefixCnt(prefix + 1, prefixLength - 1);
                }
                else
                    return 0;
            }
        }

    private:
        char _val;
        bool _isWord;
        vector<TriesNode> _childs;
        size_t _allChildsCnt;
    };


    class TriesContacts
    {
        TriesNode _root;

    public:
        TriesContacts()
            : _root('Z', false)
        {}


        void addContact(string contact)
        {
            _root.addChild(&contact[0], contact.size());
        }


        vector<string> getContacts(string prefix)
        {
            vector<string> contacts;
            _root.getChildsWithPrefix(&prefix[0], prefix.size(), "", contacts);
            return  contacts;
        }


        size_t getContactsCnt(string prefix)
        {
            return _root.getChildsWithPrefixCnt(&prefix[0], prefix.size());
        }
    };
}

#endif //LEETCODESOLUTIONS_TRIESCONTACTS_H
