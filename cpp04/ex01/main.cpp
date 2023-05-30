#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    {
        const Animal *j = new Dog();
        const Animal *i = new Cat();

        delete j; // should not create a leak
        delete i;
    }
    std::cout << "---------------------\n";
    {
        // Create and fill an array of Animals
        const int size = 2;
        const Animal *animals[size];

        for (int i = 0; i < size; i++)
        {
            if (i % 2 == 0)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }

        // Make all the animals speak
        for (int i = 0; i < size; i++)
        {
            animals[i]->makeSound();
        }

        // Delete all the animals
        for (int i = 0; i < size; i++)
        {
            delete animals[i];
        }
    }
    std::cout << "---------------------\n";
    {
        Cat *cat = new Cat();
        std::cout << "Cat's type: " << cat->getType() << std::endl;
        cat->makeSound();

        // print cat ideas
        for (int i = 0; i < 100; i++)
        {
            std::cout << "Cat's idea #" << i << ": " << cat->getBrain()->getIdea(i) << '\n';
        }
        delete cat;
    }
    return 0;
}
