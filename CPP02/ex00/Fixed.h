#ifndef FIXED_H
#define FIXED_H

class Fixed {
private:
    static const int _fractionalBits = 8;
    int _value;

public:
    Fixed();
    Fixed(const Fixed& other);
    ~Fixed();

    Fixed& operator=(const Fixed& other);

    int getRawBits() const;
    void setRawBits(int raw);
};

#endif
