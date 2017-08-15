#include "../TriesContacts.h"
#include <gtest/gtest.h>

namespace hackerrank
{

TEST(TriesContacts, test1)
{
    TriesContacts contacts;
    contacts.addContact("hacker");
    contacts.addContact("hackerrank");
    auto result = contacts.getContacts("hac");
    ASSERT_EQ(result.size(), 2);
    ASSERT_EQ(contacts.getContactsCnt("hac"), 2);
    ASSERT_TRUE(find(begin(result), end(result), "hacker") != end(result));
    ASSERT_TRUE(find(begin(result), end(result), "hackerrank") != end(result));

    result = contacts.getContacts("hackerr");
    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(contacts.getContactsCnt("hackerr"), 1);
    ASSERT_EQ(result.front(), "hackerrank");

    result = contacts.getContacts("no");
    ASSERT_TRUE(result.empty());

    result = contacts.getContacts("hacker");
    ASSERT_EQ(result.size(), 2);
    ASSERT_EQ(contacts.getContactsCnt("hacker"), 2);
    ASSERT_TRUE(find(begin(result), end(result), "hacker") != end(result));
    ASSERT_TRUE(find(begin(result), end(result), "hackerrank") != end(result));
}

}//namespace hackerrank

