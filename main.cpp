#include<stdio.h>
#include<iostream>

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
NumberCompare<int> intNint(5, 10);
NumberCompare<int> intNfloat(5, 10.0f);
NumberCompare<int> intNdouble(5, 10.0);
NumberCompare<float> floatNfloat(5.0f, 10.0f);
NumberCompare<double> floatNdouble(5.0, 10.0);
NumberCompare<double> doubleNdouble(5.0, 10.0);

std::cout << "Min of 5 and 10: " << intNint.Min(5, 10) << std::endl;
std::cout << "Min of 5 and 10.0f: " << intNfloat.Min(5, 10.0f) << std::endl;
std::cout << "Min of 5 and 10.0: " << intNdouble.Min(5, 10.0) << std::endl;
std::cout << "Min of 5.0f and 10.0f: " << floatNfloat.Min(5.0f, 10.0f) << std::endl;
std::cout << "Min of 5.0 and 10.0: " << floatNdouble.Min(5.0, 10.0) << std::endl;
std::cout << "Min of 5.0 and 10.0: " << doubleNdouble.Min(5.0, 10.0) << std::endl;


return 0;
}