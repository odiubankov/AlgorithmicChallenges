#include "1032_StreamOfCharacters.h"
#include <gtest/gtest.h>

TEST(StreamOfCharacters, test) {
    StreamChecker streamChecker{{"cd","f","kl"}};
    ASSERT_FALSE(streamChecker.query('a'));
    streamChecker.query('b');          // return false
    streamChecker.query('c');          // return false
    streamChecker.query('d');          // return true, because 'cd' is in the wordlist
    streamChecker.query('e');          // return false
    streamChecker.query('f');          // return true, because 'f' is in the wordlist
    streamChecker.query('g');          // return false
    streamChecker.query('h');          // return false
    streamChecker.query('i');          // return false
    streamChecker.query('j');          // return false
    streamChecker.query('k');          // return false
    streamChecker.query('l');          // return true, because 'kl' is in
}

TEST(StreamOfCharacters, test2) {
    StreamChecker sc{{"aa","baa","baaa","aaa","bbbb"}};
    vector<bool> res{false,false,false,false,false,false,false,false,false,false,false,true,true,false,false,true,false,false,false,true,false,true,false,false,false,false,false,false,true,false,false,false,false,false,false,false,true,true,true,true,false,false,false,false,false,true,true,true,false,false,true,false,false,false,true,false,false,false,false,false};
    vector<char> queries{'b','b','b','a','b','a','b','a','b','b','a','a','a','b','a','a','b','b','b','b','a','a','b','b','b','a','b','a','a','b','b','b','a','b','b','b','b','b','b','b','a','b','a','b','a','a','a','a','b','a','a','b','b','b','b','a','b','b','b','a'};
    for (size_t i = 0; i < queries.size(); ++i)
        if (res[i] != sc.query(queries[i]))
            int y = 0;
}

TEST(StreamOfCharacters, test3) {
    StreamChecker sc{{"aa","baa","baaa","aaa","bbbb"}};
    for (int i = 0; i < 4; ++i)
        sc.query('b');
    ASSERT_TRUE(sc.query('b'));
}
