#include "Animal.h"
#include <iostream>

Animal::Animal(): type("AAnimal")
{
    std::cout << "AAnimal constructor called" << std::endl;
}

Animal::Animal(const std::string& s): type(s)
{
    std::cout << "AAnimal string constructor called" << std::endl;
}

Animal::Animal(const Animal& other): type(other.type)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "AAnimal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "AAnimal copy assignment operator called." << std::endl;
    if (this != &other) { type = other.type; }
    return *this;
}

const std::string& Animal::getType() const
{
    return type;
}