#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : rawValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->rawValue = value << fractionalBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->rawValue = static_cast<int>(roundf(value * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed& other) : rawValue(other.rawValue) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->rawValue = other.rawValue;
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return this->rawValue;
}

void Fixed::setRawBits(int const raw) {
	this->rawValue = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->rawValue) / static_cast<float>(1 << fractionalBits);
}

int Fixed::toInt(void) const {
	return this->rawValue >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fxd) {
	os << fxd.toFloat();
	return os;
}
