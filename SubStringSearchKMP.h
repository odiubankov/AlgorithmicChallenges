#ifndef LEETCODESOLUTIONS_SUBSTRINGSEARCHKMP_H
#define LEETCODESOLUTIONS_SUBSTRINGSEARCHKMP_H

#include <string>
#include <vector>

namespace kmp {

  std::vector<int> getLongestSuffixPrefixes(const std::string& world)
  {
    std::vector<int> lsp(world.length(), 0);
    int length = 0;
    for (int i = 1; i < world.length(); ) 
    {
      if (world[i] == world[length])
        lsp[i++] = ++length;
      else if (length > 0) 
        length = lsp[length - 1];
      else 
        lsp[i++] = 0;
    }

    return lsp;
  }


  int findSubstring(const std::string& str, const std::string& word)
  {
    if (word.empty())
      return 0;

    if (word.length() > str.length())
      return -1;

    auto lsp = getLongestSuffixPrefixes(word);
    int equalCharsCnt = 0;
    int wordStart = 0;
    while (wordStart + equalCharsCnt < str.length())
    {
      if (str[wordStart + equalCharsCnt] == word[equalCharsCnt])
      {
        ++equalCharsCnt;
        if (equalCharsCnt == word.length())
          return wordStart;
      }
      else
      {
        if (equalCharsCnt == 0)
        {
          ++wordStart;
        }
        else
        {
          wordStart = wordStart + equalCharsCnt - lsp[equalCharsCnt - 1];
          equalCharsCnt = lsp[equalCharsCnt - 1];
        }
      }
    }

    return -1;
  }


}//namespace kmp

#endif //LEETCODESOLUTIONS_SUBSTRINGSEARCHKMP_H
