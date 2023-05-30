#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{

public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const &src);
	virtual ~WrongAnimal();

	WrongAnimal &operator=(WrongAnimal const &rhs);

	void makeSound(void) const;
	std::string getType(void) const;

protected:
	std::string _type;
};

#endif
