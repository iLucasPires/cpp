#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
public:
	AAnimal();
	AAnimal(AAnimal const &src);

	virtual ~AAnimal() = 0;
	virtual void makeSound(void) const = 0;

	std::string getType(void) const;
	AAnimal &operator=(AAnimal const &rhs);

protected:
	std::string type;
};

#endif
