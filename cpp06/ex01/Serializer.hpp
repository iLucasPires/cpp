#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include "Data.hpp"

typedef unsigned long int uintptr_t;

class Serializer
{
public:
	Serializer();
	Serializer(Serializer const &src);
	~Serializer();
	Serializer &operator=(Serializer const &rhs);

	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif
