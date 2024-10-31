#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const int value) : value(value << bits)
{
    std::cout << "Int constructor called." << std::endl;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called." << std::endl;
    this->value = static_cast<int>(roundf(value * (1 << bits)));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called." << std::endl;
    this->value = other.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Destructor called." << std::endl;
}

int Fixed::getRawBits() const
{
    return this->value;
}

void Fixed::setRawBits(const int raw)
{
    this->value = raw;
}

float Fixed::toFloat() const
{
    return static_cast<float>(value) / (1 << bits);
}

int Fixed::toInt() const
{
    return this->value >> bits;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return *this;
}

// Arithmetic operators

Fixed Fixed::operator+(const Fixed& other)
{
    Fixed ret;
    ret.setRawBits(this->value + other.value);
    return ret;
}

Fixed Fixed::operator-(const Fixed& other)
{
    Fixed ret;
    ret.setRawBits(this->value - other.value);
    return ret;
}

Fixed Fixed::operator*(const Fixed& other)
{
    Fixed ret;
    ret.setRawBits(this->value * other.toFloat());
    return ret;
}

Fixed Fixed::operator/(const Fixed& other)
{
    if (other.value == 0)
    {
        std::cout << "Error in operator '/'." << std::endl;
        return 0;
    }
    Fixed ret;
    ret.setRawBits(this->value / other.toFloat());
    return ret;
}

// Comparison operators

bool Fixed::operator==(const Fixed& other) const
{
    if (this->getRawBits() == other.getRawBits())
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed& other) const
{
    if (this->getRawBits() != other.getRawBits())
        return true;
    return false;
}

bool Fixed::operator<(const Fixed& other) const
{
    if (this->getRawBits() < other.getRawBits())
        return true;
    return false;
}

bool Fixed::operator>(const Fixed& other) const
{
    if (this->getRawBits() > other.getRawBits())
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed& other) const
{
    if (this->getRawBits() <= other.getRawBits())
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed& other) const
{
    if (this->getRawBits() >= other.getRawBits())
        return true;
    return false;
}

// Increment/decrement operators

Fixed& Fixed::operator++(void)
{
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed ret(*this);
    this->value++;
    return ret;
}

Fixed& Fixed::operator--(void)
{
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed ret(*this);
    this->value--;
    return ret;
}

// Min/max functions

const Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
    if (f1 < f2)
        return f1;
    return f2;
}

const Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
    if (f1 > f2)
        return f1;
    return f2;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
    if (f1 < f2)
        return f1;
    return f2;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
    if (f1 > f2)
        return f1;
    return f2;
}

std::ostream& operator<<(std::ostream& output, const Fixed& other)
{
	output << other.toFloat();
	return output;
}