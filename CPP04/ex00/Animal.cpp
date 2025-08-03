#include "Animal.h"
#include <iostream>

Animal::Animal()
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const std::string& s): type(s)
{
    std::cout << "Animal string constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    (void)other;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other) { this->type = other.type; }
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "Silence..." << '\n';
}

const std::string& Animal::getType() const
{
    return type;
}
