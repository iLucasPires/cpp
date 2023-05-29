#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{

    const Animal *animal = new Animal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    cat->makeSound(); // will output the cat sound!
    dog->makeSound();
    animal->makeSound();

    delete animal;
    delete dog;
    delete cat;

    return 0;
}
