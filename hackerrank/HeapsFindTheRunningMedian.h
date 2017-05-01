#ifndef LEETCODESOLUTIONS_HEAPSFINDTHERUNNINGMEDIAN_H
#define LEETCODESOLUTIONS_HEAPSFINDTHERUNNINGMEDIAN_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <iomanip>

using namespace std;

namespace hackerrank
{
    void pushValueAndSetMedian(vector<int>& leftHeap, vector<int>& rightHeap, int val)
    {
        if (leftHeap.empty() || val <= leftHeap.front() || rightHeap.empty() || val <= rightHeap.front())
        {
            leftHeap.push_back(val);
            push_heap(begin(leftHeap), end(leftHeap), less<int>());

            if ((leftHeap.size() - rightHeap.size()) == 2)
            {
                rightHeap.push_back(leftHeap.front());
                push_heap(begin(rightHeap), end(rightHeap), greater<int>());
                pop_heap(begin(leftHeap), end(leftHeap), less<int>());
                leftHeap.pop_back();
            }
        }
        else
        {
            rightHeap.push_back(val);
            push_heap(begin(rightHeap), end(rightHeap), greater<int>());

            if (rightHeap.size() > leftHeap.size())
            {
                leftHeap.push_back(rightHeap.front());
                push_heap(begin(leftHeap), end(leftHeap), less<int>());
                pop_heap(begin(rightHeap), end(rightHeap), greater<int>());
                rightHeap.pop_back();
            }
        }
    }


    float getMedian(const vector<int>& leftHeap, const vector<int>& rightHeap)
    {
        if (leftHeap.size() > rightHeap.size())
        {
            return static_cast<float>(leftHeap.front());
        }
        else
        {
            return (leftHeap.front() + rightHeap.front()) / 2.0f;
        }
    }


    int heapsRunningMedian()
    {
        cout << fixed << setprecision(1);

        vector<int> leftHeap;
        vector<int> rightHeap;

        int n;
        cin >> n;
        vector<int> a(n);
        for(int a_i = 0;a_i < n;a_i++){
            cin >> a[a_i];
            pushValueAndSetMedian(leftHeap, rightHeap, a[a_i]);
            cout << getMedian(leftHeap, rightHeap) << endl;
        }

        return 0;
    }


    vector<float> heapsRunningMedian(vector<int> input)
    {
        vector<float> result;
        vector<int> leftHeap;
        vector<int> rightHeap;

        for(const auto& val : input)
        {
            pushValueAndSetMedian(leftHeap, rightHeap, val);
            result.push_back(getMedian(leftHeap, rightHeap));
        }

        return result;
    }
}

#endif //LEETCODESOLUTIONS_HEAPSFINDTHERUNNINGMEDIAN_H
