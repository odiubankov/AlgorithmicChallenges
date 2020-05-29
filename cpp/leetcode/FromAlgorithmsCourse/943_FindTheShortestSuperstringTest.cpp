#include "943_FindTheShortestSuperstring.h"
#include <gtest/gtest.h>

TEST(SuperString, test) {
//gctaagttcatgcatc
//gcta
// ctaagt
//      ttca
//        catg
//         atgcatc
    ASSERT_EQ("gctaagttcatgcatc", shortestSuperstring({"catg","ctaagt","gcta","ttca","atgcatc"}));
}

TEST(SuperString, test2) {
//znrjiddfh
//znr
//   jid
//     ddfh
    ASSERT_EQ("znrjiddfh", shortestSuperstring({"ddfh","znr","idd","jid","rji"}));
}