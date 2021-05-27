#include "787_CheapestFlightsWithinKStops.h"
#include <gtest/gtest.h>

TEST(CheapestFlightsWithinKStops, test) {
    std::vector<std::vector<int>> flights {
            std::vector<int>{0, 1, 100},
            std::vector<int>{1, 2, 100},
            std::vector<int>{0, 2, 500}
    };
    ASSERT_EQ(200, findCheapestPrice(3, flights, 0, 2, 1));
}

TEST(CheapestFlightsWithinKStops, test2) {
    std::vector<std::vector<int>> flights {
            std::vector<int>{0, 1, 1},
            std::vector<int>{0, 2, 5},
            std::vector<int>{1, 2, 1},
            std::vector<int>{2, 3, 1}
    };
    ASSERT_EQ(6, findCheapestPrice(4, flights, 0, 3, 1));
}
