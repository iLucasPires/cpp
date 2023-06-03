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
    {
        printHeader("Constructors");
        const Animal *meta = new Animal();
        const Animal *j = new Dog();
        const Animal *i = new Cat();

        printHeader("Constructors Wrong Animal");
        const WrongAnimal *metaWrong = new WrongAnimal();
        const WrongAnimal *jWrong = new WrongCat();

        printHeader("Copy Constructors");
        const Animal *jCopy = new Dog((Dog const &)*j);
        const Animal *metaCopy = new Animal(*meta);

        printHeader("Copy Constructors Wrong Animal");
        const WrongAnimal *iWrongCopy = new WrongCat((WrongCat const &)*jWrong);
        const WrongAnimal *metaWrongCopy = new WrongAnimal(*metaWrong);

        printHeader("Sounds");
        j->makeSound();
        i->makeSound();
        meta->makeSound();

        printHeader("Sounds Copy");
        jCopy->makeSound();
        metaCopy->makeSound();

        printHeader("Sounds Wrong Animal");
        jWrong->makeSound();
        metaWrong->makeSound();

        printHeader("Sounds Wrong Animal Copy");
        iWrongCopy->makeSound();
        metaWrongCopy->makeSound();

        printHeader("Destructor");

        delete meta;
        delete metaWrong;
        delete j;
        delete jWrong;
        delete i;
    }

    return 0;
}
