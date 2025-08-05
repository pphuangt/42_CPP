#include "Animal.h"
#include "Brain.h"
#include "Cat.h"
#include "Dog.h"
#include <iostream>
#include <sstream>

int main()
{
    {
        std::cout << "SUBJECT TEST CASE:" << std::endl;
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        delete j;
        delete i;
    }
    std::cout << "--------------------------------------------" << std::endl;
    {
        std::cout << "ARRAY OF ANIMAL POINTERS:" << std::endl;

        Animal** animals = new Animal*[10];
        for (unsigned int i = 0; i < 10; ++i) {
            if (i % 2 == 0) { animals[i] = new Dog(); }
            else {
                animals[i] = new Cat();
            }
        }

        for (unsigned int i = 0; i < 10; ++i) {
            std::cout << animals[i]->getType() << ": ";
            animals[i]->makeSound();
        }

        for (unsigned int i = 0; i < 10; ++i) { delete animals[i]; }
        delete[] animals;
    }
}