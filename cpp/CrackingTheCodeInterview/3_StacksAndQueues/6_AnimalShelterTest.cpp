#include "6_AnimalShelter.h"
#include <gtest/gtest.h>

TEST(AnimalShelter, test) {
    AnimalShelter as;
    as.enque(AnimalShelter::Cat{"cat1"});
    as.enque(AnimalShelter::Cat{"cat2"});
    as.enque(AnimalShelter::Dog{"dog1"});
    as.enque(AnimalShelter::Dog{"dog2"});
    ASSERT_EQ("dog1", as.dequeueDog().getName());
    ASSERT_EQ("cat1", as.dequeueAny().getName());
    as.enque(AnimalShelter::Cat{"cat3"});
    ASSERT_EQ("cat2", as.dequeueCat().getName());
    ASSERT_EQ("dog2", as.dequeueAny().getName());
}

TEST(AnimalShelter, maxCounter) {
    AnimalShelter as;
    as.setInitialCounter(std::numeric_limits<unsigned int>::max() - 100);
    bool insertCat = true;
    for (unsigned int j = 0; j < 300; ++j) {
        std::string name = std::to_string(j);
        if (insertCat) {
            as.enque(AnimalShelter::Cat{std::move(name)});
            insertCat = false;
        } else
            as.enque(AnimalShelter::Dog{std::move(name)});
    }

    for (unsigned int j = 0; j < 300; ++j) {
        ASSERT_EQ(std::to_string(j), as.dequeueAny().getName());
    }
}
