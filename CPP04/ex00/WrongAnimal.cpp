#include "WrongAnimal.h"
#include <iostream>

WrongAnimal::WrongAnimal()
{
    std::cout << "Animal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& s): type(s)
{
    std::cout << "Animal string constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    (void)other;
    std::cout << "Animal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Animal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other) { this->type = other.type; }
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Silence..." << '\n';
}

const std::string& WrongAnimal::getType() const
{
    return type;
}
