#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called\n";

	this->type = "Dog";
	this->brain = new Brain();
	this->brain->setIdeas("Dog's idea");
}

Dog::Dog(const Dog &src) : Animal()
{
	std::cout << "Dog copy constructor called\n";

	this->brain = new Brain();
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";

	delete this->brain;
}

Dog &Dog::operator=(Dog const &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
		*this->brain = *rhs.brain;
	}
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof woof\n";
}

Brain *Dog::getBrain(void) const
{
	return this->brain;
}
