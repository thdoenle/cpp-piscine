#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

class Serializer
{
private:

	Serializer(void);
	Serializer(Serializer const & s);
	~Serializer(void);
	Serializer & operator=(Serializer const & rhs);

public:

	static uintptr_t serialize(Data * ptr);
	static Data * deserialize(uintptr_t raw);
};

#endif