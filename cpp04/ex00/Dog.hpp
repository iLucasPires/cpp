#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(Dog const &src);
	Dog &operator=(Dog const &rhs);
	~Dog();

	void makeSound(void) const;
};

#endif
