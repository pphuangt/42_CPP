#include "Dog.h"
#include <iostream>

Dog::Dog(): Animal("Dog")
{
    std::cout << type << " constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
{
    (void)other;
    std::cout << type << " copy constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << type << " destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other) Animal::operator=(other);
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << '\n';
}