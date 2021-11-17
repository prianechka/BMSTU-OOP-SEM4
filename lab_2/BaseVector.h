#ifndef BASEVECTOR_H
#define BASEVECTOR_H

#include <cstddef>

class BaseVector
{
    protected:
        size_t vector_size = 0;
    public:
        BaseVector(size_t vector_size = 0): vector_size(vector_size) {};

        virtual size_t size() const noexcept
        {
            size_t size = this->vector_size;
            return size;
        };

        virtual operator bool() const noexcept
        {
            bool result = bool(this->vector_size);
            return result;
        }

        virtual ~BaseVector() = 0;
};

BaseVector::~BaseVector() {}

#endif // BASEVECTOR_H
