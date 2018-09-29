#include "../PlayWithWords.h"
#include <gtest/gtest.h>

namespace hackerrank {

TEST(PlayWithWords, test1) {
    ASSERT_EQ(playWithWords("eeegeeksforskeeggeeks"), 50);
}

}
