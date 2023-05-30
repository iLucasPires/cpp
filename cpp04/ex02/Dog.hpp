#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
public:
	Dog();
	Dog(Dog const &src);
	~Dog();

	Dog &operator=(Dog const &rhs);

private:
	Brain *brain;
};

#endif
