#include "FibonacciNumber.h"
#include <vector>

namespace
{
std::vector<unsigned> FIBONACCI_CACHE{0, 1};
}

namespace sedgewick
{

unsigned calcFibonacciNumber(unsigned i)
{
    if (FIBONACCI_CACHE.size() > i)
        return FIBONACCI_CACHE[i];

    auto result = calcFibonacciNumber(i - 2) + calcFibonacciNumber(i - 1);
    FIBONACCI_CACHE.push_back(result);
    return result;
}

}//namespace sedgewick
