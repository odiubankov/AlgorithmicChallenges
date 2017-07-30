#ifndef LEETCODESOLUTIONS_DISTANCE_H
#define LEETCODESOLUTIONS_DISTANCE_H

#include <iterator>
namespace ostd{

    template<typename IteratorT, typename IteratorTraitT>
    class _distance
    {
    public:
        _distance(const IteratorT& itFirst, const IteratorT& itSecond)
        : _val{0}
        {
            auto itFirstCopy = itFirst;
            while (itFirstCopy != itSecond)
            {
                ++itFirstCopy;
                ++_val;
            }
        }

        std::size_t get() const { return _val; }

    private:
        std::size_t _val;
    };


    template<typename IteratorT>
    class _distance<IteratorT, std::random_access_iterator_tag>
    {
    public:
        _distance(const IteratorT& itFirst, const IteratorT& itSecond)
            : _val{0}
        {
            _val = itSecond - itFirst;
        }

        std::size_t get() const { return _val; }

    private:
        std::size_t _val;
    };

    template<typename IteratorT>
    std::size_t distance(const IteratorT& itFirst, const IteratorT& itSecond)
    {
        return _distance<IteratorT, typename std::iterator_traits<IteratorT>::iterator_category>{itFirst, itSecond}.get();
    }

}//namespace ostd

#endif //LEETCODESOLUTIONS_DISTANCE_H
