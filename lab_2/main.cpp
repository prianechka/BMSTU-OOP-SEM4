#include "MathVector.h"

int main()
{
    MathVector <double> first_array = {1, 2, 3};
    std::cout << "First array: " << first_array << std::endl;
    first_array += 2.0;
    std::cout << "First array after +=2.0 :" << first_array << std::endl;
    std::cout << "First array after +2.0 :" << first_array + 2.0 << std::endl;
    first_array -= 2.0;
    std::cout << "First array after -=2.0 :" << first_array << std::endl;
    std::cout << "First array: " << first_array << std::endl;
    std::cout << "First array after -2.0 :" << first_array - 2.0 << std::endl;
    first_array *= 2.0;
    std::cout << "First array after *=2.0 :" << first_array << std::endl;
    std::cout << "First array: " << first_array << std::endl;
    std::cout << "First array after *2.0 :" << first_array * 2.0 << std::endl;
    std::cout << "First array: " << first_array << std::endl;
    first_array /= 2.0;
    std::cout << "First array after /=2.0 :" << first_array << std::endl;
    std::cout << "First array: " << first_array << std::endl;
    std::cout << "First array after /2.0 :" << first_array / 2.0 << std::endl;
    std::cout << "First array: " << first_array << std::endl;

    std::cout << "--------------" << std::endl;

    first_array = {1, 2, 3};
    std::cout << "First array: " << first_array << std::endl;
    first_array.add(2.0);
    std::cout << "First array after add(2.0) :" << first_array << std::endl;
    std::cout << "First array after +2.0 :" << first_array + 2.0 << std::endl;
    first_array.sub(2.0);
    std::cout << "First array after sub(2.0) :" << first_array << std::endl;
    std::cout << "First array: " << first_array << std::endl;
    std::cout << "First array after -2.0 :" << first_array - 2.0 << std::endl;
    first_array.mul(2.0);
    std::cout << "First array after mul(2.0) :" << first_array << std::endl;
    std::cout << "First array: " << first_array << std::endl;
    std::cout << "First array after *2.0 :" << first_array * 2.0 << std::endl;
    std::cout << "First array: " << first_array << std::endl;
    first_array.div(2.0);
    std::cout << "First array after div(2.0) :" << first_array << std::endl;
    std::cout << "First array: " << first_array << std::endl;
    std::cout << "First array after /2.0 :" << first_array / 2.0 << std::endl;
    std::cout << "First array: " << first_array << std::endl;

    MathVector <int> second_array(3);
    std::cout << "Second array: " << second_array << std::endl;
    MathVector <long double> third_array(3, 3.1415);
    std::cout << "Third array: " << third_array << std::endl;
    MathVector <long double> fourth_array(third_array);
    std::cout << "Fourth array: " << fourth_array << std::endl;

    std::cout << "--------------" << std::endl;
    MathVector <int> unit_vector = {1, 0, 0};
    MathVector <double> unit_vec_sec = {0, 0, 1};
    MathVector <int> col_vec = {2, 0, 0};
    std::cout << "Is Unit: " << unit_vector.is_unit() << std::endl;
    std::cout << "Are Ort: " << unit_vec_sec.areOrthgonal(unit_vec_sec) << std::endl;
    std::cout << "Are Col: " << unit_vector.areCollinear(col_vec) << std::endl;

    std::cout << "--------------" << std::endl;
    MathVector <double> one_vec = {1.45, 2.21, 3.76};
    MathVector <double> sec_vec = {0.31, 0.45, 1.56};
    std::cout << "Are Col: " << one_vec.areCollinear(sec_vec) << std::endl;
    std::cout << "Scalar: " << one_vec.scalarMul(sec_vec) << std::endl;
    double result = one_vec & sec_vec;
    std::cout << "Scalar operator: " << result << std::endl;
    std::cout << "Mul: " << one_vec.vecMul(sec_vec) << std::endl;
    MathVector <double> sec_result = one_vec ^ sec_vec;
    std::cout << "Mul operator: " << sec_result << std::endl;

    MathVector <int> array = {1, 2, 3};
    std::cout << "Int array: " << array << std::endl;
    array += 2.3;
    std::cout << "Int array after +=2.3:" << array << std::endl;
    std::cout << "Int array after +2.4 :" << array + 2.4 << std::endl;
    return 0;
}
