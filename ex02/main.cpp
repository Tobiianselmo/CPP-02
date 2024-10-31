#include "Fixed.hpp"

int main( void )
{
    std::cout << "\n----INTEGER VALUE----\n" << std::endl;
    Fixed a(10);

    std::cout << "a value is " << a << std::endl;
    std::cout << "a value is " << a.toFloat() << " as float." << std::endl;
    std::cout << "a value is " << a.toInt() << " as integer." << std::endl;

    std::cout << "\n----FLOAT VALUE----\n" << std::endl;
    Fixed b(12.42f);

    std::cout << "b value is " << b << std::endl;
    std::cout << "b value is " << b.toFloat() << " as float." << std::endl;
    std::cout << "b value is " << b.toInt() << " as integer." << std::endl;

    std::cout << "\n----ARITHMETIC OPERATORS----\n" << std::endl;
    std::cout << "a + 2 = " << a + 2 << std::endl;
    std::cout << "a - 2 = " << a - 2 << std::endl;
    std::cout << "a * 2 = " << a * 2 << std::endl;
    std::cout << "a / 2 = " << a / 2 << std::endl;

    std::cout << "\n----COMPARISON OPERATORS----" << std::endl;
    std::cout << "0 is false, 1 is true\n" << std::endl;

    std::cout << "Is A equal to B? " << (a == b) << std::endl;
    std::cout << "Is A different to B? " << (a != b) << std::endl;
    std::cout << "Is A smaller from B? " << (a < b) << std::endl;
    std::cout << "Is A greater from B? " << (a > b) << std::endl;
    std::cout << "Is A smaller or equal from B? " << (a <= b) << std::endl;
    std::cout << "Is A greater or equal from B? " << (a >= b) << std::endl;

    std::cout << "\n----INCREMENT/DECREMENT OPERATORS----\n" << std::endl;
    std::cout << "++a is " << ++a << std::endl;
    std::cout << "a++ is " << a++ << std::endl;
    std::cout << "--a is " << --a << std::endl;
    std::cout << "a-- is " << a-- << std::endl;

    std::cout << "\n----MIN/MAX FUNCTIONS----\n" << std::endl;
    std::cout << "Between a and b, the min is " << a.min(a, b) << std::endl;
    std::cout << "Between a and b, the max is " << a.max(a, b) << std::endl;

    return 0;
}