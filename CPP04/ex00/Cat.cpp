#include "Cat.h"
#include <iostream>

Cat::Cat(): Animal("Cat")
{
    std::cout << type << " constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
{
    (void)other;
    std::cout << type << " copy constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << type << " destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other) Animal::operator=(other);
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << '\n';
}
