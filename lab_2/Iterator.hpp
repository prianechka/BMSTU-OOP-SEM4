#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "Iterator.h"

// Определяем конструкторы
template<typename Type>
Iterator<Type>::Iterator(const Iterator<Type> &iterator) noexcept
{
    this->wPointer = iterator.wPointer;
    this->current_index = iterator.current_index;
    this->vector_size = iterator.vector_size;
}

template<typename Type>
Iterator<Type>::Iterator(const MathVector<Type> &vector) noexcept {
    this->wPointer = vector.array;
    this->current_index = 0;
    this->vector_size = vector.size();
}


// Определяем проверки на существование
template<typename Type>
void Iterator<Type>::check_not_expired(int line) const
{
    if (this->wPointer.expired())
    {
        time_t current_time = time(NULL);
        throw ExpiredIterator(__FILE__, typeid(*this).name(), line, ctime(&current_time));
    }
}

template<typename Type>
void Iterator<Type>::check_on_valid(int line) const
{
    if (this->current_index >= this->vector_size)
    {
        time_t current_time = time(NULL);
        throw InvalidIterator(__FILE__, typeid(*this).name(), line, ctime(&current_time));
    }
}

// Возвращает указатель по текущему индексу
template<typename Type>
Type *Iterator<Type>::get_pointer() const
{
    std::shared_ptr<Type[]> copied = this->wPointer.lock();
    Type *result_pointer = copied.get() + current_index;
    return result_pointer;
}

// Перегрузка операторов

template<typename Type>
const Type &Iterator<Type>::operator*() const
{
    check_not_expired(__LINE__);
    check_on_valid(__LINE__);

    const Type &result_pointer = *get_pointer();
    return result_pointer;
}

template<typename Type>
const Type *Iterator<Type>::operator->() const
{
    check_not_expired(__LINE__);
    check_on_valid(__LINE__);

    const Type *result_pointer = get_pointer();
    return result_pointer;
}

template<typename Type>
Type &Iterator<Type>::operator*()
{
    check_not_expired(__LINE__);
    check_on_valid(__LINE__);
    return *get_pointer(); // Почему-то иначе выдавало ошибку, поэтому стиль немного отличается
}

template<typename Type>
Type *Iterator<Type>::operator->()
{
    check_not_expired(__LINE__);
    check_on_valid(__LINE__);

    Type *result_pointer = get_pointer();
    return result_pointer;
}

template<typename Type>
Iterator<Type>::operator bool() const
{
    check_not_expired(__LINE__);
    bool result;
    if (current_index >= vector_size || vector_size == 0)
        result = false;
    else
        result = true;
    return result;
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator=(const Iterator<Type>& iterator) noexcept
{
    wPointer = iterator.wPointer;
    return *this;
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator+=(size_t count)
{
    check_not_expired(__LINE__);
    this->current_index += count;
    return *this;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator+(size_t count) const
{
    check_not_expired(__LINE__);
    Iterator<Type> result_iterator(*this);
    result_iterator += count;
    return result_iterator;
}

template <typename Type>
Iterator<Type> &Iterator<Type>::operator-=(size_t count)
{
    check_not_expired(__LINE__);
    this->current_index -= count;
    return *this;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator-(size_t count) const
{
    check_not_expired(__LINE__);
    Iterator<Type> result_iterator(*this);
    result_iterator -= count;
    return result_iterator;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator++(int)
{
    check_not_expired(__LINE__);
    ++(*this);

    return *this;
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator++()
{
    check_not_expired(__LINE__);
    this->current_index++;
    return *this;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator--(int)
{
    check_not_expired(__LINE__);
    ++(*this);

    return *this;
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator--()
{
    check_not_expired(__LINE__);
    this->current_index--;
    return *this;
}

//Операторы сравнений

template<typename Type>
bool Iterator<Type>::operator==(const Iterator<Type> &another_vector) const
{
    check_not_expired(__LINE__);
    bool result = (this->current_index == another_vector.current_index);
    return result;
}

template<typename Type>
bool Iterator<Type>::operator!=(const Iterator<Type> &another_vector) const
{
    check_not_expired(__LINE__);
    bool result = (this->current_index != another_vector.current_index);
    return result;
}

template<typename Type>
bool Iterator<Type>::operator<(const Iterator<Type> &another_vector) const
{
    check_not_expired(__LINE__);

    bool result = (this->current_index < another_vector.current_index);
    return result;
}

template<typename Type>
bool Iterator<Type>::operator<=(const Iterator<Type> &another_vector) const
{
    check_not_expired(__LINE__);

    bool result = (this->current_index <= another_vector.current_index);
    return result;
}

template<typename Type>
bool Iterator<Type>::operator>(const Iterator<Type> &another_vector) const
{
    check_not_expired(__LINE__);
    bool result = (this->current_index > another_vector.current_index);
    return result;
}

template<typename Type>
bool Iterator<Type>::operator>=(const Iterator<Type> &another_vector) const
{
    check_not_expired(__LINE__);
    bool result = (this->current_index >= another_vector.current_index);
    return result;
}


template<typename Type>
Type &Iterator<Type>::operator[](size_t index)
{
    check_not_expired(__LINE__);
    if (index + this->current_index >= this->vector_size)
    {
        time_t current_time = time(NULL);
        throw OutOfRangeException(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }
    return *(this + index);
}

template<typename Type>
const Type &Iterator<Type>::operator[](size_t index) const
{
    check_not_expired(__LINE__);
    if (index + this->current_index >= this->vector_size)
    {
        time_t current_time = time(NULL);
        throw OutOfRangeException(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }
    return *(this + index);
}

#endif // ITERATOR_HPP
