#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
public:
	Animal();
	Animal(Animal const &src);

	virtual ~Animal();

	virtual void makeSound(void) const;

	Animal &operator=(Animal const &rhs);

	std::string getType(void) const;
protected:
	std::string _type;
};

#endif
