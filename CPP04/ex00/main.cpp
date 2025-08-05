#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include <iostream>

static void call_makeSound(Animal& animal);
static void call_makeSound_wrong(WrongAnimal& animal);

int main()
{
    {
        std::cout << "SUBJECT TEST CASE:" << std::endl;

        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete i;
        delete j;
    }
    std::cout << "--------------------------------------------" << std::endl;
    {
        std::cout << "WRONG_ANIMAL & WRONG_CAT:" << std::endl;

        WrongAnimal* wrongAnimal = new WrongAnimal();
        WrongAnimal* wrongCat = new WrongCat();
        std::cout << wrongAnimal->getType() << ": ";
        wrongAnimal->makeSound();
        std::cout << wrongCat->getType() << ": ";
        wrongCat->makeSound();

        delete wrongAnimal;
        delete wrongCat;
    }
    std::cout << "--------------------------------------------" << std::endl;
    {
        std::cout << "POLYMORPHISM WITH REFERENCE:" << std::endl;

        Cat cat;
        Dog dog;
        call_makeSound(cat);
        call_makeSound(dog);

        WrongCat wrongCat;
        call_makeSound_wrong(wrongCat);
    }
    return 0;
}

static void call_makeSound(Animal& animal)
{
    animal.makeSound();
}

static void call_makeSound_wrong(WrongAnimal& animal)
{
    animal.makeSound();
}