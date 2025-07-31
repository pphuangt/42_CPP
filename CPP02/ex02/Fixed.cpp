#include "Fixed.h"
#include <cmath>
#include <iostream>
#include <ostream>

Fixed::Fixed(): _value(0) {}

Fixed::Fixed(int const value): _value(value << _fractionalBits) {}

Fixed::Fixed(float const value)
{
    _value = roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& other): _value(other.getRawBits()) {}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other) _value = other.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed& other) const
{
    return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const
{
    return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const
{
    return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return _value != other._value;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return toFloat() + other.toFloat();
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return toFloat() - other.toFloat();
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return toFloat() * other.toFloat();
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return toFloat() / other.toFloat();
}

Fixed Fixed::operator++()
{
    _value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed fixed = Fixed(*this);
    _value++;
    return fixed;
}

Fixed Fixed::operator--()
{
    _value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed fixed = Fixed(*this);
    _value--;
    return fixed;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return a <= b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return a <= b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return a >= b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return a >= b ? a : b;
}

int Fixed::getRawBits() const
{
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

float Fixed::toFloat() const
{
    return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
    return _value >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    return os << fixed.toFloat();
}