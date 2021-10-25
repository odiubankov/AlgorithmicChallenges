#include "1041_RobotBoundedInCircle.h"
#include <gtest/gtest.h>

TEST(RobotBoundedInCircle, test) {
    // ASSERT_TRUE(isRobotBounded("GGLLGG"));
    // ASSERT_FALSE(isRobotBounded("GG"));
    // ASSERT_TRUE(isRobotBounded("GL"));
    // ASSERT_TRUE(isRobotBounded("GLRLGLLGLGRGLGL"));
    ASSERT_FALSE(isRobotBounded("GRGL"));
}
