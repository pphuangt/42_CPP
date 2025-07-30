#ifndef FIXED_H
#define FIXED_H
#include <ostream>

class Fixed {
private:
    static const int _fractionalBits = 8;
    int _value;

public:
    Fixed();
    Fixed(int value);
    Fixed(float value);
    Fixed(const Fixed& other);
    ~Fixed();

    Fixed& operator=(const Fixed& other);

    int getRawBits() const;
    void setRawBits(int raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
