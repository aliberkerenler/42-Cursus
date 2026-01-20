#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : rawValue(0) {}

Fixed::Fixed(const int value) {
	this->rawValue = value << fractionalBits;
}

Fixed::Fixed(const float value) {
	this->rawValue = static_cast<int>(roundf(value * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed& other) : rawValue(other.rawValue) {}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		this->rawValue = other.rawValue;
	}
	return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const { return this->rawValue; }
void Fixed::setRawBits(int const raw) { this->rawValue = raw; }

float Fixed::toFloat(void) const {
	return static_cast<float>(this->rawValue) / static_cast<float>(1 << fractionalBits);
}

int Fixed::toInt(void) const { return this->rawValue >> fractionalBits; }

bool Fixed::operator>(const Fixed& other) const { return this->rawValue > other.rawValue; }
bool Fixed::operator<(const Fixed& other) const { return this->rawValue < other.rawValue; }
bool Fixed::operator>=(const Fixed& other) const { return this->rawValue >= other.rawValue; }
bool Fixed::operator<=(const Fixed& other) const { return this->rawValue <= other.rawValue; }
bool Fixed::operator==(const Fixed& other) const { return this->rawValue == other.rawValue; }
bool Fixed::operator!=(const Fixed& other) const { return this->rawValue != other.rawValue; }

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed res;
	res.rawValue = this->rawValue + other.rawValue;
	return res;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed res;
	res.rawValue = this->rawValue - other.rawValue;
	return res;
}

Fixed Fixed::operator*(const Fixed& other) const {
	long a = static_cast<long>(this->rawValue);
	long b = static_cast<long>(other.rawValue);
	Fixed res;
	res.rawValue = static_cast<int>((a * b) >> fractionalBits);
	return res;
}

Fixed Fixed::operator/(const Fixed& other) const {
	long a = static_cast<long>(this->rawValue) << fractionalBits;
	long b = static_cast<long>(other.rawValue);
	Fixed res;
	res.rawValue = static_cast<int>(a / b);
	return res;
}

Fixed& Fixed::operator++() {
	++this->rawValue;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed& Fixed::operator--() {
	--this->rawValue;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b ? a : b); }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b ? a : b); }

Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b ? a : b); }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b ? a : b); }

std::ostream& operator<<(std::ostream& os, const Fixed& fxd) {
	os << fxd.toFloat();
	return os;
}
