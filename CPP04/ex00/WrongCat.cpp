#include "WrongCat.h"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal("Cat")
{
    std::cout << type << " constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
    (void)other;
    std::cout << type << " copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << type << " destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other) WrongAnimal::operator=(other);
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow!" << '\n';
}
