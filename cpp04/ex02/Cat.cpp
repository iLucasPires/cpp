#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
	std::cout << "Cat default constructor called\n";

	this->type = "Cat";
	this->brain = new Brain();
	this->brain->setIdeas("Rule the world");
}

Cat::Cat(const Cat &src) : AAnimal()
{
	std::cout << "Cat copy constructor called\n";
	this->brain = new Brain();
	*this = src;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
	delete this->brain;
}

Cat &Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat assignment operator called\n";
	if (this != &rhs)
	{
		this->type = rhs.type;
		*this->brain = *rhs.brain;
	}
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow meow\n";
}

Brain *Cat::getBrain(void) const
{
	return this->brain;
}
