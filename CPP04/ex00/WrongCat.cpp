#include "WrongCat.h"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
    std::cout << type << " constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
    std::cout << type << " copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << type << " destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << type << " copy assignment operator called." << std::endl;
    if (this != &other) WrongAnimal::operator=(other);
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongMeow!" << std::endl;
}
