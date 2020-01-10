#include "297_SerializeAndDeserializeBinaryTree.h"
#include <gtest/gtest.h>

TEST(Codec, deserialize) {
    Codec codec;
    auto deserialized = codec.deserialize("1,2,3,null,null,4,5");
    ASSERT_EQ(1, deserialized->val);
    ASSERT_EQ("1,2,3,null,null,4,5", codec.serialize(deserialized));
}

TEST(Codec, deserialize2) {
    Codec codec;
    auto deserialized = codec.deserialize("1");
    ASSERT_EQ(1, deserialized->val);
}

TEST(Codec, deserialize3) {
    Codec codec;
    auto deserialized = codec.deserialize("");
    ASSERT_FALSE(deserialized);
}
