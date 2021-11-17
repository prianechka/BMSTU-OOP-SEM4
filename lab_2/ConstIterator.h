#ifndef CONSTITERATOR_H
#define CONSTITERATOR_H


#include "Exceptions.h"

#include <memory>
#include <time.h>

template<typename Type>
class MathVector;

template<typename Type>
class ConstIterator: public std::iterator<std::random_access_iterator_tag, int>
{
    private:
        std::weak_ptr<Type[]> wPointer;

    protected:
        void check_not_expired(int line) const;
        void check_on_valid(int line) const;
        Type *get_pointer() const;
        size_t current_index = 0;
        size_t vector_size = 0;

    public:
        ConstIterator(const ConstIterator<Type> &iterator) noexcept;
        ConstIterator(const MathVector<Type> &vector) noexcept;

        const Type &operator*() const;
        const Type *operator->() const;
        operator bool() const;

        ConstIterator<Type> &operator=(const ConstIterator<Type> &iterator) noexcept;

        ConstIterator<Type> &operator+=(size_t count);
        ConstIterator<Type> operator+(size_t count) const;
        ConstIterator<Type> &operator++();
        ConstIterator<Type> operator++(int);

        ConstIterator<Type> &operator-=(size_t count);
        ConstIterator<Type> operator-(size_t count) const;
        ConstIterator<Type> &operator--();
        ConstIterator<Type> operator--(int);

        bool operator==(const ConstIterator<Type> &another_vector) const;
        bool operator!=(const ConstIterator<Type> &another_vector) const;

        bool operator<(const ConstIterator<Type> &another_vector) const;
        bool operator>(const ConstIterator<Type> &another_vector) const;
        bool operator<=(const ConstIterator<Type> &another_vector) const;
        bool operator>=(const ConstIterator<Type> &another_vector) const;

        const Type &operator[](const size_t index) const;
};

#include "ConstIterator.hpp"

#endif // CONSTITERATOR_H
