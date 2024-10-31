#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called." << std::endl;
	this->value = other.getRawBits();
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

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}

int Fixed::toInt() const
{
	return this->value >> bits;
}

float Fixed::toFloat() const
{
	return static_cast<float>(value) / (1 << bits);
}

int Fixed::getRawBits() const
{
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return *this;
}

std::ostream& operator<<(std::ostream& output, const Fixed& other)
{
	output << other.toFloat();
	return output;
}