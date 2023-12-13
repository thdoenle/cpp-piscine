#ifndef FIXED_HPP
#define FIXED_HPP

#include <ieee754.h>
#include <iostream>

class Fixed
{
private:

    static const int _NB_BITS_EXP = 8;

    int _value;

public:

    Fixed(void);
    Fixed(Fixed const & src);
    ~Fixed(void);
    Fixed & operator=(Fixed const & rhs);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};

#endif