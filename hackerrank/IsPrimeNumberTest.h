#ifndef LEETCODESOLUTIONS_ISPRIMENUMBERTEST_H
#define LEETCODESOLUTIONS_ISPRIMENUMBERTEST_H
#include <vector>
#include <unordered_set>
using namespace std;

namespace hackerrank{
bool isPrime2(int n){
    if (n <= 1)
        return false;

    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    int i = 5;
    while (i * i <= n){
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

        i = i + 6;
    }

    return true;
}

bool isPrime(int val){
    if (val == 1)
        return false;

    if (val == 2)
        return true;

    static unordered_set<int> primeNumbers;
    if (primeNumbers.find(val) != end(primeNumbers))
        return true;

    static unordered_set<int> nonPrimeNumbers;
    if (nonPrimeNumbers.find(val) != end(nonPrimeNumbers))
        return false;

    for (int i = 2; i <= val / 2; ++i){
        if (val % i == 0){
            nonPrimeNumbers.insert(val);
            return false;
        }
    }

    primeNumbers.insert(val);
    return true;
}
}

#endif //LEETCODESOLUTIONS_ISPRIMENUMBERTEST_H
