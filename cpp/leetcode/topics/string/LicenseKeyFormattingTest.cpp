#include "LicenseKeyFormatting.h"
#include <gtest/gtest.h>

namespace leetcode
{

TEST(LicenseKeyFormatting, test)
{
    Solution licenseKeyFormatting;
    ASSERT_EQ(licenseKeyFormatting.licenseKeyFormatting("---ad123---345-234234-222", 2), "A-D1-23-34-52-34-23-42-22");
}

}//namespace leetcode
