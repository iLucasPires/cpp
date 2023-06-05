#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void printHeader(std::string str)
{
    std::cout << "============================================================\n"
              << str << '\n'
              << "============================================================\n";
}

int main(void)
{
    printHeader("Constructors");
    const Animal *meta = new Animal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();

    printHeader("Constructors Wrong Animal");
    const WrongAnimal *metaWrong = new WrongAnimal();
    const WrongAnimal *dogWrong = new WrongCat();

    printHeader("Copy Constructors");
    const Animal *metaCopy = new Animal(*meta);
    const Animal *catCopy = new Cat(dynamic_cast<Cat const &>(*cat));
    const Animal *dogCopy = new Dog(dynamic_cast<Dog const &>(*dog));

    printHeader("Get Type");
    std::cout << "meta: " << meta->getType() << '\n';
    std::cout << "dog: " << dog->getType() << '\n';
    std::cout << "cat: " << cat->getType() << '\n';

    printHeader("Sounds");
    dog->makeSound();
    cat->makeSound();
    meta->makeSound();

    printHeader("Get Type Copy");
    std::cout << "metaCopy: " << metaCopy->getType() << '\n';
    std::cout << "dogCopy: " << dogCopy->getType() << '\n';
    std::cout << "catCopy: " << catCopy->getType() << '\n';

    printHeader("Sounds Copy");
    catCopy->makeSound();
    dogCopy->makeSound();
    metaCopy->makeSound();

    printHeader("Get Type Wrong Animal");
    std::cout << "metaWrong: " << metaWrong->getType() << '\n';
    std::cout << "dogWrong: " << dogWrong->getType() << '\n';

    printHeader("Sounds Wrong Animal");
    dogWrong->makeSound();
    metaWrong->makeSound();

    printHeader("Destructor");
    delete meta;
    delete metaWrong;
    delete dog;
    delete dogWrong;
    delete cat;
    delete catCopy;
    delete dogCopy;
    delete metaCopy;

    return 0;
}
