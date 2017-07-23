#ifndef LEETCODESOLUTIONS_UNIQUEPTR_H
#define LEETCODESOLUTIONS_UNIQUEPTR_H

#include <memory>
namespace ostd{
    template<typename T>
    class UniquePtr
    {
    public:
        UniquePtr() noexcept
        : _rawPtr{nullptr}
        {}

        explicit UniquePtr(T* rawPtr) noexcept
        : _rawPtr{rawPtr}
        {}

        explicit UniquePtr(UniquePtr<T>&& other) noexcept
        : _rawPtr{ other._rawPtr }
        {
            other._rawPtr = nullptr;
        }

        UniquePtr<T>& operator=(UniquePtr<T>&& other) noexcept
        {
            reset();
            _rawPtr = other._rawPtr;
            other._rawPtr = nullptr;
            return *this;
        }

        ~UniquePtr()
        {
            reset();
        }

        T* get() const noexcept
        {
            return  _rawPtr;
        }

        void reset() noexcept
        {
            if (nullptr != _rawPtr)
            {
                delete _rawPtr;
                _rawPtr = nullptr;
            }
        }

        T* release() noexcept
        {
            auto rawPtr = _rawPtr;
            _rawPtr = nullptr;
            return  rawPtr;
        }

    private:
        T* _rawPtr;
    };
}

#endif //LEETCODESOLUTIONS_UNIQUEPTR_H
