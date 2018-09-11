#include "GreatestCommonDivisor.h"

namespace sedgewick
{

int greatestCommonDivisor(int var1, int var2)
{
    //implementation of euclid algorithm
    if (var1 == var2)
        return var1;
    else if (var1 > var2)
        return greatestCommonDivisor(var1 - var2, var2);
    else
        return greatestCommonDivisor(var2 - var1, var1);
}

}//namespace sedgewick
