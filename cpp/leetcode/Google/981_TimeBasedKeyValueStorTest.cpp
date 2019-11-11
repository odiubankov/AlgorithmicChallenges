#include "981_TimeBasedKeyValueStor.h"
#include <gtest/gtest.h>

TEST(TimeBaseKeyValStor, test1) {
    TimeMap kv;
    kv.set("foo", "bar", 1); // store the key "foo" and value "bar" along with timestamp = 1
    ASSERT_EQ(kv.get("foo", 1), "bar");  // output "bar"
    ASSERT_EQ(kv.get("foo", 3), "bar"); // output "bar" since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 ie "bar"
    kv.set("foo", "bar2", 4);
    ASSERT_EQ(kv.get("foo",4), "bar2"); // output "bar2"
    ASSERT_EQ(kv.get("foo", 5), "bar2"); //output "bar2"
}

TEST(TimeBaseKeyValStor, test2) {
    TimeMap kv;
    kv.set("love","high",10);
    kv.set("love","low",20);
    ASSERT_EQ("", kv.get("love",5));
    ASSERT_EQ("high", kv.get("love",10));
    ASSERT_EQ("high", kv.get("love",15));
    ASSERT_EQ("low", kv.get("love",20));
    ASSERT_EQ("low", kv.get("love",25));
}
