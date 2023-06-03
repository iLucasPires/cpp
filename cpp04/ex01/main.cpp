#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

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
        const Animal *animals[10];

        for (int i = 0; i < 5; i++)
        {
            animals[i] = new Dog();
        }

        for (int i = 5; i < 10; i++)
        {
            animals[i] = new Cat();
        }

        printHeader("Make sound");
        for (int i = 0; i < 10; i++)
        {
            animals[i]->makeSound();
        }

        printHeader("Ideias");

        for (int i = 0; i < 5; i++)
        {
            std::cout << "Animal " << i << " is a " << animals[i]->getType()
                      << " and has the idea " << ((Dog *)animals[i])->getBrain()->getIdea(0) << '\n';
        }

        for (int i = 5; i < 10; i++)
        {
            std::cout << "Animal " << i << " is a " << animals[i]->getType()
                      << " and has the idea " << ((Cat *)animals[i])->getBrain()->getIdea(0) << '\n';
        }

        printHeader("Destructors");
        for (int i = 0; i < 10; i++)
        {
            delete animals[i];
        }
    }

    return 0;
}
