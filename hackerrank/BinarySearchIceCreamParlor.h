#ifndef LEETCODESOLUTIONS_ICECREAMPARLOR_H
#define LEETCODESOLUTIONS_ICECREAMPARLOR_H

#include <vector>

using namespace std;

namespace hackerrank
{
  class IceCream {

  public:
    int flavor;
    int index;

    IceCream(int f, int i)
      : flavor(f)
      , index(i)
    {}

    bool operator<(const IceCream& other)
    {
      return flavor < other.flavor;
    }
  };

  int binarySearch(int first, int last, vector<IceCream> arr, int search) {
    if (last < first)
      return -1;

    int middleIndex = first + (last - first) / 2;
    if (arr[middleIndex].flavor < search)
      return binarySearch(middleIndex + 1, last, arr, search);

    if (arr[middleIndex].flavor > search)
      return binarySearch(first, middleIndex - 1, arr, search);

    return middleIndex;
  }
}

#endif //LEETCODESOLUTIONS_ICECREAMPARLOR_H
