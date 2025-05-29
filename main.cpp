#include<stdio.h>
#include<iostream>
#include<string>

template<typename T>
class NumberCompare 
{
public:

    NumberCompare(T a, T b) : a(static_cast<T>(a)), b(static_cast<T>(b)) {}

    T Min(T a, T b) {
        return (a < b) ? a : b;
    }

private:
T a, b;
};

int main() {
NumberCompare<int> intNint(1, 13);
NumberCompare<int> intNfloat(10.0f, 5);
NumberCompare<int> intNdouble(7, 18.0);
NumberCompare<float> floatNfloat(3.1f, 4.5f);
NumberCompare<double> floatNdouble(5.0f, 5.1);
NumberCompare<double> doubleNdouble(123.0, 321.0);

std::cout << "Min of 1 and 13: " << std::to_string(intNint.Min(1, 13)) << std::endl;
std::cout << "Min of 10.0f and 5: " << std::to_string(intNfloat.Min(10.0f, 5)) << std::endl;
std::cout << "Min of 7 and 18.0: " << std::to_string(intNdouble.Min(7, 18.0)) << std::endl;
std::cout << "Min of 3.1f and 4.5f: " << std::to_string(floatNfloat.Min(3.1f, 4.5f)) << std::endl;
std::cout << "Min of 5.0f and 5.1: " << std::to_string(floatNdouble.Min(5.0f, 5.1)) << std::endl;
std::cout << "Min of 123.0 and 321.0: " << std::to_string(doubleNdouble.Min(123.0, 321.0)) << std::endl;

return 0;
}