#ifndef ALGORITHMICCHALLENGES_BAGSQUEUESSTACKS_1_3_37_JOSEPHUSPROBLEM_H
#define ALGORITHMICCHALLENGES_BAGSQUEUESSTACKS_1_3_37_JOSEPHUSPROBLEM_H

#include <vector>
#include <list>

namespace sedgewick
{

std::vector<int> josephusProblem(int removeIndex, int number)
{
    std::list<int> people;
    for (int i = 0; i < number; ++i)
        people.push_back(i);

    std::vector<int> removedPeople;
    if (number == 0)
        return removedPeople;
    auto peopleIt = begin(people);
    while (!people.empty())
    {
        for (int i = 1; i < removeIndex; ++i)
        {
            ++peopleIt;
            if (peopleIt == end(people))
                peopleIt = begin(people);
        }
        removedPeople.push_back(*peopleIt);
        peopleIt = people.erase(peopleIt);
        if (peopleIt == end(people))
            peopleIt = begin(people);
    }
    return removedPeople;
}

}

#endif //ALGORITHMICCHALLENGES_BAGSQUEUESSTACKS_1_3_37_JOSEPHUSPROBLEM_H
