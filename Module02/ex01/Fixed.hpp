#ifndef FIXED_HPP
#define FIXED_HPP

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
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};

#endif