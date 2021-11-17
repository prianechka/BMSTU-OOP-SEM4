#ifndef MATHVECTOR_HPP
#define MATHVECTOR_HPP

#include <limits>
#include "MathVector.h"
#include "defines.h"

// Метод выделения памяти
template<typename Type>
void MathVector<Type>::allocate_memory(size_t amount)
{
    time_t current_time = time(NULL);
    try
    {
        this->array.reset(new Type[amount]);
    }
    catch (std::bad_alloc &exception)
    {
        throw MemoryException(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }
}

// Итераторы
template<typename Type>
Iterator<Type> MathVector<Type>::begin() noexcept
{
    Iterator<Type> iterator(*this);
    return iterator;
}

template<typename Type>
Iterator<Type> MathVector<Type>::end() noexcept
{
    Iterator<Type> iterator(*this);
    return iterator + this->vector_size;
}

template<typename Type>
ConstIterator<Type> MathVector<Type>::begin() const noexcept
{
    ConstIterator<Type> constIterator(*this);
    return constIterator;
}

template<typename Type>
ConstIterator<Type> MathVector<Type>::end() const noexcept
{
    ConstIterator<Type> constIterator(*this);
    return constIterator + this->vector_size;
}

template<typename Type>
ConstIterator<Type> MathVector<Type>::constBegin() const noexcept
{
    ConstIterator<Type> constIterator(*this);
    return constIterator;
}

template<typename Type>
ConstIterator<Type> MathVector<Type>::constEnd() const noexcept
{
    ConstIterator<Type> constIterator(*this);
    return constIterator + this->vector_size;
}

// Конструкторы подъехали

// Дефолтный
template<typename Type>
MathVector<Type>::MathVector()
{
    time_t current_time = time(NULL);
    if (std::is_arithmetic<Type>() == false)
        throw InvalidType(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    else
    {
        this->vector_size = 0;
        this->allocate_memory(vector_size);
    }
}

// Заполняем нулями, выделяем память
template<typename Type>
MathVector<Type>::MathVector(size_t size)
{
    time_t current_time = time(NULL);
    if (std::is_arithmetic<Type>() == false)
        throw InvalidType(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    else
    {
        this->allocate_memory(size);
        this->vector_size = size;
        Iterator<Type> iterator = this->begin();
        for (; iterator; iterator++)
            *iterator = 0;
    }
}

// Заполняем N элементов выбранным элементом.
template<typename Type>
MathVector<Type>::MathVector(size_t size, Type element)
{
    time_t current_time = time(NULL);
    if (std::is_arithmetic<Type>() == false)
        throw InvalidType(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));

    else if (size == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    else
    {
        this->allocate_memory(size);
        if (this->array == nullptr)
            throw MemoryException(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
        else
        {
            this->vector_size = size;
            Iterator<Type> iterator = this->begin();
            for (; iterator; iterator++)
                *iterator = element;
        }

    }
}

// По массиву значений
template<typename Type>
MathVector<Type>::MathVector(size_t size, const Type *mold_array)
{
    time_t current_time = time(NULL);
    if (std::is_arithmetic<Type>() == false)
        throw InvalidType(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    else if (size == 0)
    {
        throw EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }
    else if (mold_array == nullptr)
    {
        throw InvalidCopyArrayPointer(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }
    else
    {
        this->allocate_memory(size);
        if (this->array == nullptr)
            throw MemoryException(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
        else
        {
            this->vector_size = size;
            Iterator<Type> iterator = this->begin();
            for (size_t i = 0; iterator; iterator++, i++)
                *iterator = mold_array[i];
        }
    }
}

// По переданным аргументам
template<typename Type>
MathVector<Type>::MathVector(const std::initializer_list<Type> &arguments)
{
    time_t current_time = time(NULL);
    if (std::is_arithmetic<Type>() == false)
        throw InvalidType(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    else
    {
        this->vector_size = arguments.size();
        this->allocate_memory(vector_size);
        if (this->array == nullptr)
            throw MemoryException(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
        else
        {
            Iterator<Type> iterator = this->begin();
            for (auto &currentItem : arguments)
            {
                *iterator = currentItem;
                iterator++;
            }
        }
    }
}

// Старый вектор превращаем в новый. Конструктор перемещения
template<typename Type>
MathVector<Type>::MathVector(MathVector<Type> &&old_vector) noexcept
{
    this->array = old_vector.array;
    this->vector_size = old_vector.vector_size;
    old_vector.array = nullptr;
    old_vector.vector_size = 0;
}

//Конструктор копирования
template<typename Type>
MathVector<Type>::MathVector(const MathVector<Type> &vector)
{
    *this = vector;
}


// Операции равенства
template<typename Type>
MathVector<Type> &MathVector<Type>::operator=(const MathVector<Type> &another_vector)
{
    time_t current_time = time(NULL);
    this->vector_size = another_vector.vector_size;
    this->allocate_memory(this->vector_size);

    if (this->array == nullptr)
        throw MemoryException(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    else
    {
        Iterator<Type> destiny_iterator(*this);
        Iterator<Type> source_iterator(another_vector);
        for (; destiny_iterator; destiny_iterator++, source_iterator++)
            *destiny_iterator = *source_iterator;
    }
    return *this;
}

template<typename Type>
MathVector<Type> &MathVector<Type>::operator=(const std::initializer_list<Type> &arguments)
{
    time_t current_time = time(NULL);
    if (std::is_arithmetic<Type>() == false)
        throw InvalidType(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    else
    {
        this->vector_size = arguments.size();
        this->allocate_memory(this->vector_size);
        Iterator<Type> iterator = this->begin();
        for (auto &current_item : arguments)
        {
            *iterator = current_item;
            iterator++;
        }
    }
    return *this;
}

template<typename Type>
MathVector<Type> &MathVector<Type>::operator=(MathVector<Type> &&another_vector)
{
    time_t current_time = time(NULL);
    this->vector_size = another_vector.vector_size;
    this->allocate_memory(this->vector_size);
    if (this->array == nullptr)
        throw MemoryException(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    else
    {
        this->array = another_vector.array;
        another_vector.array.reset();
    }
    return *this;
}

template<typename Type>
Type &MathVector<Type>::operator[](size_t index)
{
    time_t currentTime = time(NULL);
    if (index >= this->vector_size)
        throw OutOfRangeException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    Iterator<Type> iterator = this->begin();
    for (size_t i = 0; i < index; i++)
        iterator++;
    return *iterator;
}

template<typename Type>
const Type &MathVector<Type>::operator[](size_t index) const
{
    time_t currentTime = time(NULL);
    if (index >= this->vector_size)
        throw OutOfRangeException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    ConstIterator<Type> iterator = this->begin();
    for (size_t i = 0; i < index; i++)
        iterator++;
    return *iterator;
}

template<typename Type>
Type &MathVector<Type>::at(size_t index)
{
    return this->operator[](index);
}

template<typename Type>
const Type &MathVector<Type>::at(size_t index) const
{
    return this->operator[](index);
}

template<typename Type>
bool MathVector<Type>::operator==(const MathVector<Type> &vector) const
{
    bool result = true;
    if (this->vector_size != vector.vector_size)
        result = false;
    else
    {
        ConstIterator<Type> first_iterator = this->begin();
        ConstIterator<Type> second_iterator = vector.begin();
        for (; first_iterator && result; second_iterator++)
        if (std::abs(*first_iterator - *second_iterator) < std::numeric_limits<Type>::epsilon()) // Конструктор гарантирует, что такой Eps есть
            result = false;
    }
    return result;
}

template<typename Type>
bool MathVector<Type>::is_equal(const MathVector<Type> &vector) const
{
    return *this == vector;
}

template<typename Type>
bool MathVector<Type>::operator!=(const MathVector<Type> &vector) const
{
    return !(*this == vector);
}

template<typename Type>
bool MathVector<Type>::is_not_equal(const MathVector<Type> &vector) const
{
    return *this != vector;
}

template<typename Type>
MathVector<Type> MathVector<Type>::operator-()
{
    MathVector<Type> new_vector(*this);
    Iterator<Type> iterator = new_vector.begin();
    for (; iterator; iterator++)
        *iterator = -*iterator;
    return new_vector;
}

template<typename Type>
MathVector<Type> MathVector<Type>::negative()
{
    return -*this;
}

template<typename Type>
template<typename Type_2>
void MathVector<Type>::check_vector_sizes(const MathVector<Type_2> &vector, int line) const
{
    time_t currentTime = time(NULL);
    if (this->vector_size != vector.vector_size)
        throw InvalidVectorsSizes(__FILE__, typeid(*this).name(), line, ctime(&currentTime));
}

template<typename Type>
template<typename Type_2>
MathVector<Type> MathVector<Type>::sum_two_vectors(const MathVector<Type_2> &vector) const
{
    MathVector<Type> result(*this);
    Iterator<Type> resultIterator = result.begin();
    ConstIterator<Type_2> iterFrom = vector.begin();

    for (; resultIterator; resultIterator++, iterFrom++)
        *resultIterator = *resultIterator + *iterFrom;
    return result;
}

template<typename Type>
template<typename Type_2>
MathVector<Type> &MathVector<Type>::operator+=(const MathVector<Type_2> &vector)
{
    time_t current_time = time(NULL);
    if (this->vector_size == 0 || vector.vector_size == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));

    this->check_vector_sizes(vector, __LINE__);
    *this = this->sum_two_vectors(vector);

    return *this;
}

template<typename Type>
template<typename Type_2>
MathVector<Type> MathVector<Type>::sum_vector_and_elem(const Type_2 &element) const
{
    time_t current_time = time(NULL);
    if (std::is_arithmetic<Type>() == false)
        throw InvalidType(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    MathVector<Type> result(*this);

    ConstIterator<Type> iter_from = this->begin();
    Iterator<Type> iter_to = result.begin();

    for (; iter_from; iter_from++, iter_to++)
        *iter_to = *iter_from + element;
    return result;
}

template<typename Type>
template<typename Type_2>
MathVector<Type> &MathVector<Type>::operator+=(const Type_2 &element)
{
    time_t currentTime = time(NULL);
    if (this->vector_size == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    *this = this->sum_vector_and_elem(element);
    return *this;
}

template<typename Type>
template<typename Type_2>
MathVector<Type> MathVector<Type>::operator+(const MathVector<Type_2> &vector) const
{
    time_t currentTime = time(NULL);
    if (this->vector_size == 0 || vector.vector_size == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    this->check_vector_sizes(vector, __LINE__);
    return this->sum_two_vectors(vector);
}

template<typename Type>
template<typename Type_2>
MathVector<Type> MathVector<Type>::operator+(const Type_2 &element) const
{
    time_t currentTime = time(NULL);
    if (this->vector_size == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    return this->sum_vector_and_elem(element);
}

template<typename Type>
template<typename Type_2>
void MathVector<Type>::add(const MathVector<Type_2> &vector)
{
    *this += vector;
}

template<typename Type>
template<typename Type_2>
void MathVector<Type>::add(const Type_2 &element)
{
    *this += element;
}

template<typename Type>
template<typename Type_2>
MathVector<Type> MathVector<Type>::sub_two_vectors(const MathVector<Type_2> &vector) const
{
    MathVector<Type> result(*this);
    Iterator<Type> resultIterator = result.begin();
    ConstIterator<Type_2> iterFrom = vector.begin();

    for (; resultIterator; resultIterator++, iterFrom++)
        *resultIterator = *resultIterator - *iterFrom;
    return result;
}

template<typename Type>
template<typename Type_2>
MathVector<Type> &MathVector<Type>::operator-=(const MathVector<Type_2> &vector)
{
    time_t currentTime = time(NULL);
    if (this->vector_size == 0 || vector.vector_size == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    this->check_vector_sizes(vector, __LINE__);
    *this = this->sub_two_vectors(vector);

    return *this;
}

template<typename Type>
template<typename Type_2>
MathVector<Type> MathVector<Type>::sub_vector_and_elem(const Type_2 &element) const
{
    time_t current_time = time(NULL);
    if (std::is_arithmetic<Type>() == false)
        throw InvalidType(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    MathVector<Type> result(*this);

    ConstIterator<Type> iter_from = this->begin();
    Iterator<Type> iter_to = result.begin();

    for (; iter_from; iter_from++, iter_to++)
        *iter_to = *iter_from - element;
    return result;
}

template<typename Type>
template<typename Type_2>
MathVector<Type> &MathVector<Type>::operator-=(const Type_2 &element)
{
    time_t currentTime = time(NULL);
    if (this->vector_size == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    *this = this->sub_vector_and_elem(element);
    return *this;
}

template<typename Type>
template<typename Type_2>
MathVector<Type> MathVector<Type>::operator-(const MathVector<Type_2> &vector) const
{
    time_t currentTime = time(NULL);
    if (this->vector_size == 0 || vector.vector_size == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    this->check_vector_sizes(vector, __LINE__);
    return this->sub_two_vectors(vector);
}

template<typename Type>
template<typename Type_2>
MathVector<Type> MathVector<Type>::operator-(const Type_2 &element) const
{
    time_t currentTime = time(NULL);
    if (this->vector_size == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    return this->sub_vector_and_elem(element);
}

template<typename Type>
template<typename Type_2>
void MathVector<Type>::sub(const MathVector<Type_2> &vector)
{
    *this -= vector;
}

template<typename Type>
template<typename Type_2>
void MathVector<Type>::sub(const Type_2 &element)
{
    *this -= element;
}

template<typename Type>
template<typename Type_2>
MathVector<Type> MathVector<Type>::mul_two_vectors(const MathVector<Type_2> &vector) const
{
    MathVector<Type> result(*this);
    Iterator<Type> resultIterator = result.begin();
    ConstIterator<Type> iterFrom = vector.begin();

    for (; resultIterator; resultIterator++, iterFrom++)
        *resultIterator = *resultIterator * *iterFrom;
    return result;
}

template<typename Type>
template<typename Type_2>
MathVector<Type> &MathVector<Type>::operator*=(const MathVector<Type_2> &vector)
{
    time_t currentTime = time(NULL);
    if (this->vector_size == 0 || vector.vector_size == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    this->check_vector_sizes(vector, __LINE__);
    *this = this->mul_two_vectors(vector);

    return *this;
}

template<typename Type>
template<typename Type_2>
MathVector<Type> MathVector<Type>::mul_vector_and_elem(const Type_2 &element) const
{
    time_t current_time = time(NULL);
    if (std::is_arithmetic<Type>() == false)
        throw InvalidType(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    MathVector<Type> result(*this);

    ConstIterator<Type> iter_from = this->begin();
    Iterator<Type> iter_to = result.begin();

    for (; iter_from; iter_from++, iter_to++)
        *iter_to = *iter_from * element;
    return result;
}

template<typename Type>
template<typename Type_2>
MathVector<Type> &MathVector<Type>::operator*=(const Type_2 &element)
{
    time_t currentTime = time(NULL);
    if (this->vector_size == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    *this = this->mul_vector_and_elem(element);
    return *this;
}

template<typename Type>
template<typename Type_2>
MathVector<Type> MathVector<Type>::operator*(const MathVector<Type_2> &vector) const
{
    time_t currentTime = time(NULL);
    if (this->vector_size == 0 || vector.vector_size == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    this->check_vector_sizes(vector, __LINE__);
    return this->sum_two_vectors(vector);
}

template<typename Type>
template<typename Type_2>
MathVector<Type> MathVector<Type>::operator*(const Type_2 &element) const
{
    time_t currentTime = time(NULL);
    if (this->vector_size == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    return this->sum_vector_and_elem(element);
}

template<typename Type>
template<typename Type_2>
void MathVector<Type>::mul(const MathVector<Type_2> &vector)
{
    *this *= vector;
}

template<typename Type>
template<typename Type_2>
void MathVector<Type>::mul(const Type_2 &element)
{
    *this *= element;
}

template<typename Type>
template<typename Type_2>
MathVector<Type> MathVector<Type>::div_two_vectors(const MathVector<Type_2> &vector) const
{
    MathVector<Type> result(*this);
    Iterator<Type> resultIterator = result.begin();
    ConstIterator<Type> iterFrom = vector.begin();

    for (; resultIterator; resultIterator++, iterFrom++)
        *resultIterator = *resultIterator / *iterFrom;
    return result;
}

template<typename Type>
template<typename Type_2>
MathVector<Type> &MathVector<Type>::operator/=(const MathVector<Type_2> &vector)
{
    time_t currentTime = time(NULL);
    if (this->vector_size == 0 || vector.vector_size == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    this->check_vector_sizes(vector, __LINE__);
    *this = this->div_two_vectors(vector);

    return *this;
}

template<typename Type>
template<typename Type_2>
MathVector<Type> MathVector<Type>::div_vector_and_elem(const Type_2 &element) const
{
    time_t current_time = time(NULL);
    if (std::is_arithmetic<Type>() == false)
        throw InvalidType(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    else if (fabs(element) < __FLT_EPSILON__)
        throw ZeroDivisionException(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    MathVector<Type> result(*this);

    ConstIterator<Type> iter_from = this->begin();
    Iterator<Type> iter_to = result.begin();

    for (; iter_from; iter_from++, iter_to++)
        *iter_to = *iter_from / element;
    return result;
}

template<typename Type>
template<typename Type_2>
MathVector<Type> &MathVector<Type>::operator/=(const Type_2 &element)
{
    time_t current_time = time(NULL);
    if (this->vector_size == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    else if (fabs(element) < __FLT_EPSILON__)
        throw ZeroDivisionException(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));

    *this = this->div_vector_and_elem(element);
    return *this;
}

template<typename Type>
template<typename Type_2>
MathVector<Type> MathVector<Type>::operator/(const MathVector<Type_2> &vector) const
{
    time_t currentTime = time(NULL);
    if (this->vector_size == 0 || vector.vector_size == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    this->check_vector_sizes(vector, __LINE__);
    return this->div_two_vectors(vector);
}

template<typename Type>
template<typename Type_2>
MathVector<Type> MathVector<Type>::operator/(const Type_2 &element) const
{
    time_t currentTime = time(NULL);
    if (this->vector_size == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    return this->div_vector_and_elem(element);
}

template<typename Type>
template<typename Type_2>
void MathVector<Type>::div(const MathVector<Type_2> &vector)
{
    *this /= vector;
}

template<typename Type>
template<typename Type_2>
void MathVector<Type>::div(const Type_2 &element)
{
    *this /= element;
}


template<typename Type>
Type MathVector<Type>::sumElems()
{
    time_t currentTime = time(NULL);
    if (this->vector_size == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    Iterator<Type> iterator = this->begin();
    Type sum = 0;
    for (; iterator; iterator++)
        sum += *iterator;
    return sum;
}

template<typename Type>
Type MathVector<Type>::scalarMul(const MathVector<Type> &vector) const
{
    time_t currentTime = time(NULL);
    if (this->vector_size == 0 || vector.vector_size == 0)
        EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    this->check_vector_sizes(vector, __LINE__);
    Type result = this->mul_two_vectors(vector).sumElems();
    return result;
}

template<typename Type>
Type MathVector<Type>::operator&(const MathVector<Type> &vector) const
{
    Type result = this->scalarMul(vector);
    return result;
}

template<typename Type>
void MathVector<Type>::checkSizesForVecMul(const MathVector<Type> &vector, int lineError) const
{
    time_t currentTime = time(NULL);
    if (this->vector_size != 3 || vector.vector_size != 3)
        throw InvalidVectorsSizes(__FILE__, typeid(*this).name(), lineError, ctime(&currentTime));
}

template<typename Type>
MathVector<Type> MathVector<Type>::vecMul(const MathVector<Type> &vector) const
{
    checkSizesForVecMul(vector, __LINE__);

    Type xCoord = this->array[1] * vector.array[2] - this->array[2] * vector.array[1];
    Type yCoord = this->array[2] * vector.array[0] - this->array[0] * vector.array[2];
    Type zCoord = this->array[0] * vector.array[1] - this->array[1] * vector.array[0];

    MathVector<Type> result = {xCoord, yCoord, zCoord};
    return result;
}

template<typename Type>
MathVector<Type> MathVector<Type>::operator^(const MathVector<Type> &vector) const
{
    MathVector<Type> result = this->vecMul(vector);
    return result;
}

template<typename Type>
MathVector<Type> &MathVector<Type>::operator^=(const MathVector<Type> &vector)
{
    checkSizesForVecMul(vector, __LINE__);
    *this = *this ^ vector;
    return *this;
}

template<typename Type>
template<typename TypeOut>
TypeOut MathVector<Type>::geomLength(void) const
{
    time_t currentTime = time(NULL);
    if (this->vector_size == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    ConstIterator<Type> iterator = this->begin();
    Type sum = 0;
    for (; iterator; iterator++)
        sum += *iterator * *iterator;
    return sqrt(sum);
}

// Специализация для int
template<>
template<>
double MathVector<int>::geomLength(void) const
{
    time_t currentTime = time(NULL);
    if (this->vector_size == 0)
        throw EmptyVectorException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    ConstIterator<int> iterator = this->begin();
    int sum = 0;
    for (; iterator; iterator++)
        sum += *iterator * *iterator;
    return sqrt(sum);
}

template<typename Type>
double MathVector<Type>::angle(const MathVector<Type> &vector) const
{
    time_t currentTime = time(NULL);
    if (this->geomLength<Type>() == 0 || vector.geomLength<Type>() == 0)
        throw ZeroDivisionException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    double angle = (*this & vector) / (this->geomLength<Type>() * vector.geomLength<Type>());
    return acos(angle) * 180 / M_PI;
}

template<typename Type>
bool MathVector<Type>::areCollinear(const MathVector<Type> &vector) const
{
    bool result = false;
    if (this->angle(vector) < __FLT_EPSILON__)
        result = true;
    return result;
}

template<typename Type>
bool MathVector<Type>::areOrthgonal(const MathVector<Type> &vector) const
{
    bool result = false;
    if ((this->angle(vector) - 90) < __FLT_EPSILON__)
        result = true;
    return result;
}

template<typename Type>
bool MathVector<Type>::is_unit() const noexcept
{
    bool result = true;
    if (fabs(this->geomLength<Type>() - 1) < __FLT_EPSILON__)
        result = true;
    return result;
}

template<typename Type>
bool MathVector<Type>::is_zero() const noexcept
{
    bool result = false;
    if (this->geomLength<Type>() < __FLT_EPSILON__)
        result = true;
    return result;
}

template<typename Type>
template<typename TypeOut>
MathVector<TypeOut> MathVector<Type>::find_unit_vector() const
{
    MathVector<TypeOut> result(this->vector_size);
    Type geom_len = this->geomLength<Type>();

    Iterator<TypeOut> iteratorTo = result.begin();
    ConstIterator<Type> iteratorFrom = this->begin();
    for (; iteratorFrom; iteratorFrom++, iteratorTo++)
        *iteratorTo = *iteratorFrom / geom_len;

    return result;
}

//Специализация для int
template<>
template<>
MathVector<double> MathVector<int>::find_unit_vector() const
{
    MathVector<double> result(this->vector_size);
    float geom_len = this->geomLength<int>();

    Iterator<double> iteratorTo = result.begin();
    ConstIterator<int> iteratorFrom = this->begin();
    for (; iteratorFrom; iteratorFrom++, iteratorTo++)
        *iteratorTo = *iteratorFrom / geom_len;

    return result;
}

template<typename Type>
std::ostream &operator<<(std::ostream &os, const MathVector<Type> &vector)
{
    ConstIterator<Type> iterator = vector.begin();
    if (!iterator)
    {
        os << "Empty mVector";
        return os;
    }

    os<< "{";
    os<< *iterator;
    for (iterator++; iterator; iterator++)
            os<< ", "<< *iterator;
    os<< "}";

    return os;
}

#endif // MATHVECTOR_HPP
