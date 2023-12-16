#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:

    static const int _FRAC_BITS = 8;

    int _value;

public:

    Fixed(void);
    Fixed(Fixed const & src);
    Fixed(const int & src);
    Fixed(const float & src);
    ~Fixed(void);

    Fixed & operator=(Fixed const & rhs);

    bool operator>(Fixed const & rhs) const;
    bool operator>=(Fixed const & rhs) const;
    bool operator<(Fixed const & rhs) const;
    bool operator<=(Fixed const & rhs) const;
    bool operator==(Fixed const & rhs) const;
    bool operator!=(Fixed const & rhs) const;

    Fixed operator+(Fixed const & rhs) const;
    Fixed operator-(Fixed const & rhs) const;
    Fixed operator*(Fixed const & rhs) const;
    Fixed operator/(Fixed const & rhs) const;

    Fixed & operator++(void);
    Fixed & operator--(void);
    Fixed   operator++(int);
    Fixed   operator--(int);

    static Fixed & min(Fixed & lhs, Fixed & rhs);
    static Fixed const & min(Fixed const & lhs, Fixed const & rhs);
    static Fixed & max(Fixed & lhs, Fixed & rhs);
    static Fixed const & max(Fixed const & lhs, Fixed const & rhs);

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & f);

#endif