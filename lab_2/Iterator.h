#ifndef ITERATOR_H
#define ITERATOR_H

#include "Exceptions.h"
#include <memory>
#include <time.h>

template<typename Type>
class MathVector;

template<typename Type>
class Iterator: public std::iterator<std::random_access_iterator_tag, int>
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
        Iterator(const Iterator<Type> &iterator) noexcept;
        Iterator(const MathVector<Type> &vector) noexcept;

        Type &operator*();
        const Type &operator*() const;
        Type *operator->();
        const Type *operator->() const;
        operator bool() const;

        Iterator<Type> &operator=(const Iterator<Type> &iterator) noexcept;

        Iterator<Type> &operator+=(size_t count);
        Iterator<Type> operator+(size_t count) const;
        Iterator<Type> &operator++();
        Iterator<Type> operator++(int);

        Iterator<Type> &operator-=(size_t count);
        Iterator<Type> operator-(size_t count) const;
        Iterator<Type> &operator--();
        Iterator<Type> operator--(int);

        bool operator==(const Iterator<Type> &another) const;
        bool operator!=(const Iterator<Type> &another) const;

        bool operator<(const Iterator<Type> &another) const;
        bool operator>(const Iterator<Type> &another) const;
        bool operator<=(const Iterator<Type> &another) const;
        bool operator>=(const Iterator<Type> &another) const;

        Type &operator[](const size_t index);
        const Type &operator[](const size_t index) const;
};

#include "Iterator.hpp"

#endif // ITERATOR_H
