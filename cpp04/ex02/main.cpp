#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
	// Exercice example
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();
	// const  AAnimal *d = new AAnimal();

    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
}
