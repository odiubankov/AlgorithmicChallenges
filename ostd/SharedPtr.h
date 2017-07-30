#ifndef LEETCODESOLUTIONS_SHAREDPTR_H
#define LEETCODESOLUTIONS_SHAREDPTR_H

#include <cstddef>
#include <cassert>

namespace ostd
{
    template<typename T>
    class SharedPtr
    {
    public:
        SharedPtr() noexcept
        : _counter{nullptr}
        , _rawPtr{nullptr}
        {}


        explicit SharedPtr(T* rawPtr) noexcept
        : _counter{new std::size_t(1)}
        , _rawPtr{rawPtr}
        {}


        ~SharedPtr()
        {
            decrementRefCount();
        }


        SharedPtr(const SharedPtr<T>& other) noexcept
        : _counter{other._counter}
        , _rawPtr{other._rawPtr}
        {
            incrementRefCount();
        }


        SharedPtr(SharedPtr<T>&& other) noexcept
        : _counter{other._counter}
        , _rawPtr{other._rawPtr}
        {
            other.reset();
        }


        SharedPtr<T>& operator=(const SharedPtr<T>& other) noexcept
        {
            decrementRefCount();
            copyFromOther(other);
            incrementRefCount();
            return *this;
        }


        SharedPtr<T>& operator=(SharedPtr<T>&& other) noexcept
        {
            decrementRefCount();
            copyFromOther(other);
            other.reset();
            return *this;
        }


        T* operator->() const noexcept
        {
            return _rawPtr;
        }


        T& operator*() noexcept
        {
            assert(nullptr != _rawPtr);
            return *_rawPtr;
        }


        const T& operator*() const noexcept
        {
            assert(nullptr != _rawPtr);
            return *_rawPtr;
        }


        T* get() const noexcept
        {
            return _rawPtr;
        }

    private:
        void copyFromOther(const SharedPtr<T>& other) noexcept
        {
            _counter = other._counter;
            _rawPtr = other._rawPtr;
        }


        void decrementRefCount() noexcept
        {
            if (nullptr != _counter)
            {
                --*_counter;
                if (0 == *_counter)
                    delete _rawPtr;
            }
        }


        void incrementRefCount() noexcept
        {
            if (nullptr != _counter)
                ++(*_counter);
        }


        void reset() noexcept
        {
            _counter = nullptr;
            _rawPtr = nullptr;
        }


        std::size_t* _counter;
        T* _rawPtr;
    };
}

#endif //LEETCODESOLUTIONS_SHAREDPTR_H
