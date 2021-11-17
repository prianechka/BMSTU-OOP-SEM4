#ifndef MATHVECTOR_H
#define MATHVECTOR_H

#include <iostream>
#include <memory>
#include <type_traits>
#include <cmath>

#include "Iterator.h"
#include "ConstIterator.h"
#include "BaseVector.h"

template<typename Type>
class MathVector: public BaseVector
{
    private:
        std::shared_ptr<Type[]> array;

    protected:
        void allocate_memory(size_t count); //+
        template<typename Type_2> void check_vector_sizes(const MathVector<Type_2> &vector, int line) const; //+
        void checkSizesForVecMul(const MathVector<Type> &vector, int lineError) const; //+
        Type sumElems(); //Для скалярного произведения //+

    public:
        friend class Iterator<Type>; //+
        friend class ConstIterator<Type>; //+

        // Конструкторы
        MathVector(); //+
        explicit MathVector(size_t size); //+
        MathVector(size_t size, const Type *arrayFrom); //+
        MathVector(size_t size, Type element); //+
        MathVector(const std::initializer_list<Type> &elements); //+
        explicit MathVector(const MathVector<Type> &vector); //+
        MathVector(MathVector<Type> &&vector) noexcept; //+

        // Деструктор
        virtual ~MathVector() = default; //+)

        // Варианты оператора присвоения
        MathVector<Type> &operator=(const MathVector<Type> &vector); //+
        MathVector<Type> &operator=(const std::initializer_list<Type> &arguments); //+
        MathVector<Type> &operator=(MathVector<Type> &&vector); //+

        // Варианты метода at и перегрузка оператора индексации
        Type &at(size_t index); //+
        const Type &at(size_t index) const; //+
        Type &operator[](size_t index);  //+
        const Type &operator[](size_t index) const; //+

        // Булевы операции для сравнения векторов и определения типа вектора
        bool operator==(const MathVector<Type> &vector) const; //+
        bool is_equal(const MathVector<Type> &vector) const; //+
        bool operator!=(const MathVector<Type> &vector) const; //+
        bool is_not_equal(const MathVector<Type> &vector) const; //+
        bool is_zero() const noexcept; //+
        bool is_unit() const noexcept; //+

        // Методы работы с одним вектором: узнать модуль и найти коллинеарный единичный
        template<typename TypeOut> TypeOut geomLength() const; //+
        template<typename TypeOut> MathVector<TypeOut> find_unit_vector() const;


        // Методы для взаимного определения двух векторов
        double angle(const MathVector<Type> &another) const; //+
        bool areCollinear(const MathVector<Type> &another) const; //+
        bool areOrthgonal(const MathVector<Type> &another) const; //+

        MathVector<Type> operator-(); //+
        MathVector<Type> negative(); //+

        template<typename Type_2> MathVector<Type> &operator+=(const MathVector<Type_2> &vector); //+
        template<typename Type_2> MathVector<Type> &operator+=(const Type_2 &element); //+
        template<typename Type_2> void add(const MathVector<Type_2> &vector); //+
        template<typename Type_2> void add(const Type_2 &element); //+
        template<typename Type_2> MathVector<Type> operator+(const MathVector<Type_2> &vector) const; //+
        template<typename Type_2> MathVector<Type> operator+(const Type_2 &element) const; //+
        template<typename Type_2> MathVector<Type> sum_two_vectors(const MathVector<Type_2> &vector) const; //+
        template<typename Type_2> MathVector<Type> sum_vector_and_elem(const Type_2 &element) const; //+

        template<typename Type_2> MathVector<Type> &operator-=(const MathVector<Type_2> &vector); //+
        template<typename Type_2> MathVector<Type> &operator-=(const Type_2 &element); //+
        template<typename Type_2> void sub(const MathVector<Type_2> &vector); //+
        template<typename Type_2> void sub(const Type_2 &element); //+
        template<typename Type_2> MathVector<Type> operator-(const MathVector<Type_2> &vector) const; //+
        template<typename Type_2> MathVector<Type> operator-(const Type_2 &element) const; //+
        template<typename Type_2> MathVector<Type> sub_two_vectors(const MathVector<Type_2> &vector) const; //+
        template<typename Type_2> MathVector<Type> sub_vector_and_elem(const Type_2 &element) const; //+

        template<typename Type_2> MathVector<Type> &operator*=(const MathVector<Type_2> &vector); //+
        template<typename Type_2> MathVector<Type> &operator*=(const Type_2 &element); //+
        template<typename Type_2> void mul(const MathVector<Type_2> &vector); //+
        template<typename Type_2> void mul(const Type_2 &element); //+
        template<typename Type_2> MathVector<Type> operator*(const MathVector<Type_2> &vector) const; //+
        template<typename Type_2> MathVector<Type> operator*(const Type_2 &element) const; //+
        template<typename Type_2> MathVector<Type> mul_two_vectors(const MathVector<Type_2> &vector) const; //+
        template<typename Type_2> MathVector<Type> mul_vector_and_elem(const Type_2 &element) const; //+

        template<typename Type_2> MathVector<Type> &operator/=(const MathVector<Type_2> &vector); //+
        template<typename Type_2> MathVector<Type> &operator/=(const Type_2 &element); //+
        template<typename Type_2> void div(const MathVector<Type_2> &vector); //+
        template<typename Type_2> void div(const Type_2 &element); //+
        template<typename Type_2> MathVector<Type> operator/(const MathVector<Type_2> &vector) const; //+
        template<typename Type_2> MathVector<Type> operator/(const Type_2 &element) const; //+
        template<typename Type_2> MathVector<Type> div_two_vectors(const MathVector<Type_2> &vector) const; //+
        template<typename Type_2> MathVector<Type> div_vector_and_elem(const Type_2 &element) const; //+

        Type operator&(const MathVector<Type> &vector) const; //+
        Type scalarMul(const MathVector<Type> &vector) const; //+

        MathVector<Type> operator^(const MathVector<Type> &vector) const; //+
        MathVector<Type> vecMul(const MathVector<Type> &vector) const; //+
        MathVector<Type> &operator^=(const MathVector<Type> &vector); //+

        // Методы для итераторов
        ConstIterator<Type> begin() const noexcept; //+
        ConstIterator<Type> end() const noexcept; //+
        Iterator<Type> begin() noexcept; //+
        Iterator<Type> end() noexcept; //+
        ConstIterator<Type> constBegin() const noexcept; //+
        ConstIterator<Type> constEnd() const noexcept; //+

};

#include "MathVector.hpp"

#endif // MATHVECTOR_H
