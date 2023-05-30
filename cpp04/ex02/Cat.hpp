#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
public:
	Cat();
	Cat(Cat const &src);
	~Cat();

	Cat &operator=(Cat const &rhs);
	void makeSound(void) const;

	Brain *getBrain(void) const;

private:
	Brain *brain;
};

#endif
