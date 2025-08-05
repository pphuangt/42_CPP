#include "WrongAnimal.h"
#include <iostream>

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& s): type(s)
{
    std::cout << "WrongAnimal string constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): type(other.type)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy assignment operator called." << std::endl;
    if (this != &other) { type = other.type; }
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Silence..." << std::endl;
}

const std::string& WrongAnimal::getType() const
{
    return type;
}
