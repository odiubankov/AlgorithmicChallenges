// https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description

#ifndef LEETCODESOLUTIONS_LONGESTUNIQCHARSSUBSTR_H
#define LEETCODESOLUTIONS_LONGESTUNIQCHARSSUBSTR_H

#include <string>
#include <unordered_set>

using namespace std;

namespace longestuniqcharssubstr
{
  class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int longestSubstrLength = 0;
      unordered_set<char> substrChars;
      auto substrBeginIt = begin(s);
      auto substrEndIt = begin(s);
      for (; substrEndIt != end(s); ++substrEndIt)
      {
        auto insertRes = substrChars.insert(*substrEndIt);
        if (!insertRes.second)
        {
          if (static_cast<int>(substrChars.size()) > longestSubstrLength)
          {
            longestSubstrLength = substrChars.size();
          }

          while (*substrBeginIt != *substrEndIt)
          {
            substrChars.erase(*substrBeginIt);
            ++substrBeginIt;
          }

          ++substrBeginIt;
        }
      }

      if (static_cast<int>(substrChars.size()) > longestSubstrLength)
      {
        return substrChars.size();
      }

      return longestSubstrLength;
    }
  };
}

#endif //LEETCODESOLUTIONS_LONGESTUNIQCHARSSUBSTR_H
